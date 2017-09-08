#include "configwindow.h"
#include "ui_configwindow.h"

ConfigWindow::ConfigWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->PowerButton,SIGNAL(clicked(bool)),this,SLOT(PowerSlot()));
    QObject::connect(ui->ScanButton,SIGNAL(clicked(bool)),this,SLOT(ScanSlot()));
    QObject::connect(ui->ConnectButton,SIGNAL(clicked(bool)),this,SLOT(ConnetSlot()));
    QObject::connect(ui->SendButton,SIGNAL(clicked(bool)),this,SLOT(SendSlot()));
    QObject::connect(ui->SaveButton,SIGNAL(clicked(bool)),this,SLOT(SaveSlot()));
}

ConfigWindow::~ConfigWindow()
{
    if(this->PortBase->Socket->state()==QBluetoothSocket::ConnectedState)
    {
        QObject::disconnect(this->PortBase->Socket,SIGNAL(readyRead()),this,SLOT(ReceiveSlot()));
    }
    delete ui;
}

void ConfigWindow::PowerSlot()
{
    if(ui->PowerButton->text()=="打开蓝牙")
    {
        this->PortBase->Power(true);
        ui->PowerButton->setText("关闭蓝牙");
    }
    else if(ui->PowerButton->text()=="关闭蓝牙")
    {
        this->PortBase->Power(false);
        ui->PowerButton->setText("打开蓝牙");
    }
}

void ConfigWindow::ScanSlot()
{
    ui->BluetoothBox->clear();
    QObject::disconnect(this->PortBase,SIGNAL(DisCoverdSignal(QBluetoothDeviceInfo)),this,SLOT(DisCoveredSlot(QBluetoothDeviceInfo)));
    this->PortBase->scan();
    QObject::connect(this->PortBase,SIGNAL(DisCoverdSignal(QBluetoothDeviceInfo)),this,SLOT(DisCoveredSlot(QBluetoothDeviceInfo)));
}

void ConfigWindow::DisCoveredSlot(QBluetoothDeviceInfo InfoBase)
{
    ui->BluetoothBox->addItem(InfoBase.name().toUtf8());
}

void ConfigWindow::ConnetSlot()
{
    if(ui->ConnectButton->text()=="连接")
    {
        this->PortBase->BlueToothConnect(&this->PortBase->DeviceInfo.at(ui->BluetoothBox->currentIndex()));
        ui->ConnectButton->setText("断开");
        QObject::connect(this->PortBase->Socket,SIGNAL(readyRead()),this,SLOT(ReceiveSlot()));
        this->PortBase->CurrentDeviceInfo=this->PortBase->DeviceInfo.at(ui->BluetoothBox->currentIndex());
    }
    else if(ui->ConnectButton->text()=="断开")
    {
        this->PortBase->BlueToothDisConnect();
        ui->ConnectButton->setText("连接");
        QObject::disconnect(this->PortBase->Socket,SIGNAL(readyRead()),this,SLOT(ReceiveSlot()));
    }
}


void ConfigWindow::SaveSlot()
{
    this->PortBase->CurrentDeviceInfo=this->PortBase->DeviceInfo.at(ui->BluetoothBox->currentIndex());
    QMessageBox::information(this,"保存成功","已保存到:"+this->PortBase->CurrentDeviceInfo.name(),QMessageBox::Yes);
}



void ConfigWindow::ReceiveSlot()
{
    if(ui->HEXBox->isChecked())
    {
        QByteArray buf=this->PortBase->Socket->read(1);
        QString str=" "+buf.toHex();
        ui->ReceiveAera->insertPlainText(str);
        buf.clear();
    }
    else if(!ui->HEXBox->isChecked())
    {
        QByteArray buf;
        buf =this->PortBase->Socket->readAll();
        QString str="下位机:"+buf;
        QString test=buf;
        qDebug()<<test.toInt();
        ui->ReceiveAera->append(str);
        buf.clear();
    }
}

void ConfigWindow::SendSlot()
{
    if(ui->SendAera->text().isEmpty())
    {
        if(QMessageBox::question(this,tr("当前发送区无内容"),"您确定要发送空内容吗?",QMessageBox::Cancel|QMessageBox::Ok)==QMessageBox::Cancel)
        {
            return;
        }
    }

    this->PortBase->SafeWrite(ui->SendAera->text().toLatin1());
    ui->ReceiveAera->append("上位机:"+ui->SendAera->text());
    if(ui->CleanBox->isChecked())
    {
        ui->SendAera->clear();
    }
}
