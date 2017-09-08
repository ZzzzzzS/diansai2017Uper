﻿#include "mainwindow.h"
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
    if(ui->PowerButton->text()=="连接")
        {
          this->PortBase->BlueToothConnect(this->PortBase->CurrentDeviceInfo);
          ui->PowerButton->setText("断开");
          QObject::connect(this->PortBase->Socket,SIGNAL(readyRead()),this,SLOT(ReceiveSlot()));
        }
        else
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
    this->PortBase->SafeWrite("s7");
}

void MainWindow::Slot8()
{
    this->PortBase->SafeWrite("q8");
}

void MainWindow::Slot9()
{
    this->PortBase->SafeWrite("q9");
}
