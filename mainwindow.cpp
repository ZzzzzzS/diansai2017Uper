#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->ConfigButton,SIGNAL(clicked(bool)),this,SLOT(ConfigSlot()));
    QObject::connect(ui->PowerButton,SIGNAL(clicked(bool)),this,SLOT(PowerSlot()));
    QObject::connect(ui->Button1,SIGNAL(clicked(bool)),this,SLOT(Slot1()));
    QObject::connect(ui->Button2,SIGNAL(clicked(bool)),this,SLOT(Slot2()));
    QObject::connect(ui->Button3,SIGNAL(clicked(bool)),this,SLOT(Slot3()));
    QObject::connect(ui->Button4,SIGNAL(clicked(bool)),this,SLOT(Slot4()));
    QObject::connect(ui->Button5,SIGNAL(clicked(bool)),this,SLOT(Slot5()));
    QObject::connect(ui->Button6,SIGNAL(clicked(bool)),this,SLOT(Slot6()));
    QObject::connect(ui->Button7,SIGNAL(clicked(bool)),this,SLOT(Slot7()));
    QObject::connect(ui->Button8,SIGNAL(clicked(bool)),this,SLOT(Slot8()));
    QObject::connect(ui->Button9,SIGNAL(clicked(bool)),this,SLOT(Slot9()));
    QObject::connect(ui->DebugButton,SIGNAL(clicked(bool)),this,SLOT(DebugSlot()));
    QObject::connect(ui->LeftButton,SIGNAL(clicked(bool)),this,SLOT(LeftSlot()));
    QObject::connect(ui->RightButton,SIGNAL(clicked(bool)),this,SLOT(RightSlot()));
    QObject::connect(ui->UpButton,SIGNAL(clicked(bool)),this,SLOT(UpSlot()));
    QObject::connect(ui->DownButton,SIGNAL(clicked(bool)),this,SLOT(DownSlot()));
    this->AcceSensor.start();
    this->AcceScanTimer.start(10);
    QObject::connect(&AcceScanTimer,SIGNAL(timeout()),this,SLOT(AcceScan()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ConfigSlot()
{
    QObject::disconnect(this->PortBase->Socket,SIGNAL(readyRead()),this,SLOT(ReceiveSlot()));
    ConfigWindow windowBase;
    windowBase.PortBase=this->PortBase;
    windowBase.showFullScreen();
    windowBase.SetButton();
    //windowBase.show();
    windowBase.exec();
    if(this->PortBase->Socket->state()==QBluetoothSocket::ConnectedState)
    {
        QObject::connect(this->PortBase->Socket,SIGNAL(readyRead()),this,SLOT(ReceiveSlot()));
        ui->PowerButton->setText("断开");
    }
    else
    {
        QObject::disconnect(this->PortBase->Socket,SIGNAL(readyRead()),this,SLOT(ReceiveSlot()));
        ui->PowerButton->setText("连接");
    }
}

void MainWindow::PowerSlot()
{
    if(this->PortBase->LocalDevice->hostMode()==QBluetoothLocalDevice::HostPoweredOff)
    {
        QMessageBox::information(this,"蓝牙未打开","请打开蓝牙后重试",QMessageBox::Ok);
        this->ConfigSlot();
        return;
    }
    if(this->PortBase->CurrentDeviceInfo.name().isEmpty())
    {
        QMessageBox::information(this,"蓝牙未连接","请重新扫描蓝牙后重试",QMessageBox::Ok);
        ConfigSlot();
        return;
    }
    QObject::connect(this->PortBase,SIGNAL(ConnectOK()),this,SLOT(ConnetOKSlot()));
    QObject::connect(this->PortBase,SIGNAL(DisConnetOK()),this,SLOT(DisconnetOKSlot()));
    if(ui->PowerButton->text()=="连接")
        {
          this->PortBase->BlueToothConnect(this->PortBase->CurrentDeviceInfo);
          ui->PowerButton->setText("断开");
          QObject::connect(this->PortBase->Socket,SIGNAL(readyRead()),this,SLOT(ReceiveSlot()));
        }
        else if(ui->PowerButton->text()=="断开")
        {
            this->PortBase->BlueToothDisConnect();
            QObject::disconnect(this->PortBase->Socket,SIGNAL(readyRead()),this,SLOT(ReceiveSlot()));
            ui->PowerButton->setText("连接");
        }
}

void MainWindow::DebugSlot()
{
    QMessageBox::information(this,"Sorry","调试模式正在调试中",QMessageBox::Ok);
}

void MainWindow::ReceiveSlot()
{

}

void MainWindow::UpSlot()
{
    this->PortBase->SafeWrite("w");
}

void MainWindow::DownSlot()
{
    this->PortBase->SafeWrite("s");
}

void MainWindow::RightSlot()
{
    this->PortBase->SafeWrite("f");
}

void MainWindow::LeftSlot()
{
    this->PortBase->SafeWrite("a");
}

void MainWindow::Slot1()
{
    this->PortBase->SafeWrite("q1");
}

void MainWindow::Slot2()
{
    this->PortBase->SafeWrite("q2");
}

void MainWindow::Slot3()
{
    this->PortBase->SafeWrite("q3");
}

void MainWindow::Slot4()
{
    this->PortBase->SafeWrite("q4");
}

void MainWindow::Slot5()
{
    this->PortBase->SafeWrite("q5");
}

void MainWindow::Slot6()
{
    this->PortBase->SafeWrite("q6");
}

void MainWindow::Slot7()
{
    this->PortBase->SafeWrite("q7");
}

void MainWindow::Slot8()
{
    this->PortBase->SafeWrite("q8");
}

void MainWindow::Slot9()
{
    this->PortBase->SafeWrite("q9");
}

void MainWindow::DisconnetOKSlot()
{
    ui->PowerButton->setText("连接");
}

void MainWindow::ConnetOKSlot()
{
    ui->PowerButton->setText("断开");
}

void MainWindow::AcceScan()
{
    static char motion=0;
    //读取传感器的值
    this->x=AcceSensor.reading()->x();
    this->y=AcceSensor.reading()->y();
    this->z=AcceSensor.reading()->z();
    //显示在屏幕上
    ui->ZLine->setText(QString::number(this->z));
    ui->XLine->setText(QString::number(this->x));
    ui->YLine->setText(QString::number(this->y));

    if(motion!=0)
    {
        motion++;
    }
    if(motion>=100)
        motion=0;

    if(motion==0)
    {
        if(x>5)//<<
        {
            LeftSlot();
            ui->InformationEdit->append("小球向左移动");
        }
        else if(x<-5)//>>
        {
            RightSlot();
            ui->InformationEdit->append("小球向右移动");
        }
        else if(y>3)//向下
        {
            DownSlot();
            ui->InformationEdit->append("小球向下移动");
        }
        else if(y<-3)//向上
        {
            UpSlot();
            ui->InformationEdit->append("小球向上移动");
        }
        motion=1;
    }





}
