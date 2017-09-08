#include "bluetooth.h"

BlueTooth::BlueTooth(QWidget *parent) : QWidget(parent)
{
    this->ServiceUuid=QLatin1String("00001101-0000-1000-8000-00805F9B34FB");
    this->LocalDevice=new QBluetoothLocalDevice();
    this->DiscoverAgent=new QBluetoothDeviceDiscoveryAgent();
    this->Socket=new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
}

void BlueTooth::scan()
{
    QObject::disconnect(this->DiscoverAgent,SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),this,SLOT(Discoverd(QBluetoothDeviceInfo)));
    this->DeviceInfo.clear();
    this->DiscoverAgent->stop();
    this->DiscoverAgent->start();
    QObject::connect(this->DiscoverAgent,SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),this,SLOT(Discoverd(QBluetoothDeviceInfo)));
}

void BlueTooth::Power(bool Power)
{
    if(Power==true)
    {
        this->LocalDevice->powerOn();
    }
    else if(Power==false)
        this->LocalDevice->setHostMode(QBluetoothLocalDevice::HostPoweredOff);
}

void BlueTooth::BlueToothConnect(const QBluetoothDeviceInfo *Base)
{
    QObject::disconnect(this->Socket,SIGNAL(connected()),this,SLOT(Connected()));
    this->Socket->connectToService(Base->address(),QBluetoothUuid(this->ServiceUuid));
    QObject::connect(this->Socket,SIGNAL(connected()),this,SLOT(Connected()));
}

void BlueTooth::Connected()
{
    QMessageBox::information(NULL,"连接","已连接成功!",QMessageBox::Ok);
}

void BlueTooth::BlueToothDisConnect()
{
    QObject::disconnect(this->Socket,SIGNAL(disconnected()),this,SLOT(Disconnected()));
    this->Socket->disconnectFromService();
    QObject::connect(this->Socket,SIGNAL(disconnected()),this,SLOT(Disconnected()));
}

void BlueTooth::Disconnected()
{
    QMessageBox::information(NULL,"断开","已断开成功!",QMessageBox::Ok);
}

void BlueTooth::SafeWrite(QString data)
{
    if(this->Socket->state()==QBluetoothSocket::ConnectedState)
    {
        Socket->write(data.toUtf8());
    }
    else
    {
        QMessageBox::information(NULL,"错误","")
    }
}
