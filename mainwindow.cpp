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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ConfigSlot()
{
    QObject::disconnect(&Port,SIGNAL(readyRead()),this,SLOT(ReceiveSlot()));
    ConfigWindow windowBase;
    windowBase.showFullScreen();
    //windowBase.show();
    windowBase.exec();
    if(Port.isOpen())
    {
        QObject::connect(&Port,SIGNAL(readyRead()),this,SLOT(ReceiveSlot()));
        ui->PowerButton->setText("关闭串口");
    }
    else
    {
        QObject::disconnect(&Port,SIGNAL(readyRead()),this,SLOT(ReceiveSlot()));
        ui->PowerButton->setText("打开串口");
    }
}

void MainWindow::PowerSlot()
{
    if(ui->PowerButton->text()=="打开串口")
        {
            QMessageBox *a=new QMessageBox;
            a->setIcon(QMessageBox::Information);
            a->setParent(this);
            a->setWindowTitle("正在打开串口");
            a->show();

            bool ok=Port.OpenPort();
            if(ok)
            {
                ui->PowerButton->setText("关闭串口");
                QObject::connect(&Port,SIGNAL(readyRead()),this,SLOT(ReceiveSlot()));
            }
            else
            {
                QMessageBox::information(this,"串口可能未打开","请检查设备是否未连接或被其他程序占用",QMessageBox::Yes);
                ui->PowerButton->setText("打开串口");
            }
            a->close();

        }
        else
        {
            QMessageBox a;
            a.setIcon(QMessageBox::Information);
            a.setWindowTitle("正在关闭串口");
            a.show();

            Port.clear();
            Port.close();
            QObject::disconnect(&Port,SIGNAL(readyRead()),this,SLOT(ReceiveSlot()));
            ui->PowerButton->setText("打开串口");

            a.close();
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
    Port.SafeWrite(QByteArray("w"));
}

void MainWindow::DownSlot()
{
    Port.SafeWrite("s");
}

void MainWindow::RightSlot()
{
    Port.SafeWrite("f");
}

void MainWindow::LeftSlot()
{
    Port.SafeWrite("a");
}

void MainWindow::Slot1()
{
    Port.SafeWrite("q1");
}

void MainWindow::Slot2()
{
    Port.SafeWrite("q2");
}

void MainWindow::Slot3()
{
    Port.SafeWrite("q3");
}

void MainWindow::Slot4()
{
    Port.SafeWrite("q4");
}

void MainWindow::Slot5()
{
    Port.SafeWrite("q5");
}

void MainWindow::Slot6()
{
    Port.SafeWrite("q6");
}

void MainWindow::Slot7()
{
    Port.SafeWrite("s7");
}

void MainWindow::Slot8()
{
    Port.SafeWrite("q8");
}

void MainWindow::Slot9()
{
    Port.SafeWrite("q9");
}
