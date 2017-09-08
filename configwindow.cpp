#include "configwindow.h"
#include "ui_configwindow.h"
#include <QDesktopServices>
#include <QUrl>

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
    QObject::disconnect(this->PortBase,SIGNAL(ConnectOK(bool)),this,SLOT(ConnetOKSlot(bool)));
    QObject::disconnect(this->PortBase,SIGNAL(DisConnetOK(bool)),this,SLOT(DisconnetOKSlot(bool)));
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
    if(ui->ConnectButton->text()=="断开")
    {
        if(QMessageBox::warning(this,"蓝牙已连接","蓝牙已连接,此时搜索可能会导致连接断开,确定要继续吗?",QMessageBox::Yes,QMessageBox::No)==QMessageBox::No)
            return;
    }
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
    if(ui->BluetoothBox->currentText().isEmpty())
    {
        QMessageBox::information(this,"蓝牙未连接","请重新扫描蓝牙后重试",QMessageBox::Ok);
        return;
    }
    QObject::connect(this->PortBase,SIGNAL(ConnectOK(bool)),this,SLOT(ConnetOKSlot(bool)));
    QObject::connect(this->PortBase,SIGNAL(DisConnetOK(bool)),this,SLOT(DisconnetOKSlot(bool)));

    if(ui->ConnectButton->text()=="连接")
    {
        this->PortBase->BlueToothConnect(&this->PortBase->DeviceInfo.at(ui->BluetoothBox->currentIndex()));
        ui->ConnectButton->setText("正在连接");
        QObject::connect(this->PortBase->Socket,SIGNAL(readyRead()),this,SLOT(ReceiveSlot()));
        this->PortBase->CurrentDeviceInfo=this->PortBase->DeviceInfo.at(ui->BluetoothBox->currentIndex());
    }
    else if(ui->ConnectButton->text()=="断开")
    {
        this->PortBase->BlueToothDisConnect();
        ui->ConnectButton->setText("正在断开");
        QObject::disconnect(this->PortBase->Socket,SIGNAL(readyRead()),this,SLOT(ReceiveSlot()));
    }
}


void ConfigWindow::SaveSlot()
{
    if(ui->BluetoothBox->currentText().isEmpty())
    {
        QMessageBox::information(this,"错误","请扫描后重试",QMessageBox::Ok);
        ScanSlot();
        return;
    }

    this->PortBase->CurrentDeviceInfo=this->PortBase->DeviceInfo.at(ui->BluetoothBox->currentIndex());
    QMessageBox::information(this,"保存成功","已保存到:"+this->PortBase->CurrentDeviceInfo.name(),QMessageBox::Yes);
    this->close();
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

    QString test=ui->SendAera->text();
    if(test=="Author")
    {
        QMessageBox::information(this,"软件作者:","Powered By ZZS",QMessageBox::Ok);
        return;
    }
    else if(test=="About Qt")
    {
        qApp->aboutQt();
        return;
    }
    else if(test=="About")
    {
        QMessageBox::information(this,"718创新实验室","此软件由哈工大718创新实验室开发",QMessageBox::Ok);
        QDesktopServices::openUrl(QUrl("http://git.oschina.net/code.zzs/diansai2017Uper"));
        return;
    }

    this->PortBase->SafeWrite(ui->SendAera->text().toLatin1());
    ui->ReceiveAera->append("上位机:"+ui->SendAera->text());
    if(ui->CleanBox->isChecked())
    {
        ui->SendAera->clear();
    }
}

void ConfigWindow::SetButton()
{
    if(this->PortBase->LocalDevice->hostMode()==QBluetoothLocalDevice::HostPoweredOff)
     {
        ui->PowerButton->setText("打开蓝牙");
    }
    else
     {
         ui->PowerButton->setText("关闭蓝牙");
         if(this->PortBase->Socket->state()==QBluetoothSocket::ConnectedState)
         {
             ui->ConnectButton->setText("断开");
             QList<QBluetoothDeviceInfo>::iterator itor;
                 itor=this->PortBase->DeviceInfo.begin();
                 int i=0;
                 ui->BluetoothBox->clear();
                 while(itor!=this->PortBase->DeviceInfo.end())
                 {
                    ui->BluetoothBox->addItem(this->PortBase->DeviceInfo.at(i).name().toUtf8());
                    itor++;
                    i++;
                 }
         }
         else
         {
             ui->ConnectButton->setText("连接");
             ScanSlot();
         }
    }
}

void ConfigWindow::DisconnetOKSlot(bool ok)
{
    if(ok)
    ui->ConnectButton->setText("连接");
}

void ConfigWindow::ConnetOKSlot(bool ok)
{
    if(ok)
    ui->ConnectButton->setText("断开");
}
