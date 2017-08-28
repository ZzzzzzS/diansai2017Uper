#include "port.h"

port Port;

port::port()
{
    this->PortScan();
}

bool port::OpenPort()
{
    if(this->isOpen())
    {
        return true;
    }

    this->setPortName(this->settings.portname);
    this->open(QIODevice::ReadWrite);

    switch(this->settings.baud)
    {
    case 0:
        this->setBaudRate(QSerialPort::Baud9600);
        break;
    case 1:
        this->setBaudRate(QSerialPort::Baud19200);
        break;
    case 2:
        this->setBaudRate(QSerialPort::Baud38400);
        break;
    case 3:
        this->setBaudRate(QSerialPort::Baud57600);
        break;
    case 4:
        this->setBaudRate(QSerialPort::Baud115200);
        break;
    }

    switch(this->settings.Data)
    {
    case 0:
        this->setDataBits(QSerialPort::Data8);
        break;
    case 1:
        this->setDataBits(QSerialPort::Data7);
        break;
    case 2:
        this->setDataBits(QSerialPort::Data6);
        break;
    case 3:
        this->setDataBits(QSerialPort::Data5);
        break;
    }

    switch(this->settings.stopbit)
    {
    case 0:
        this->setStopBits(QSerialPort::OneStop);
        break;
    case 1:
        this->setStopBits(QSerialPort::TwoStop);
        break;
    }

    switch(this->settings.parity)
    {
    case 0:
        this->setParity(QSerialPort::NoParity);
        break;
    case 1:
        this->setParity(QSerialPort::OddParity);
        break;
    case 2:
        this->setParity(QSerialPort::EvenParity);
        break;
    }

    if(!this->isOpen())
    {
        return false;
    }
    return true;
}

void port::PortScan()
{
    this->PortInfo.clear();
    this->PortInfo=QSerialPortInfo::availablePorts();
}

void port::SafeWrite(QByteArray data)
{
    if(!this->isOpen())
    {
        QMessageBox::information(NULL,"请打开串口","串口可能未打开",QMessageBox::Ok);
        return;
    }
    qDebug()<<data;
    this->write(data);
}

void port::SafeWrite(QString &data)
{
    if(!this->isOpen())
    {
        QMessageBox::information(NULL,"请打开串口","串口可能未打开",QMessageBox::Ok);
        return;
    }
    qDebug()<<data.toUtf8();
    this->write(data.toUtf8());

}






void port::DirectionSlot(unsigned char direction)
{

}

void port::AimSlot(unsigned char Aim)
{

}
