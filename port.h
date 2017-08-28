#ifndef PORT_H
#define PORT_H

#include <QObject>
#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QByteArray>
#include <QList>
#include <QMessageBox>
#include <QDebug>
#include <QString>

class port : public QSerialPort
{
    Q_OBJECT
public:
    port();
    void PortScan();
    QList<QSerialPortInfo> PortInfo;
    bool OpenPort();

    struct
        {
            QString portname;
            char baud;
            char Data;
            char stopbit;
            char parity;
        }settings;

    void SafeWrite(QByteArray data);
    void SafeWrite(QString &data);

signals:

public slots:
    void DirectionSlot(unsigned char direction);
    void AimSlot(unsigned char Aim);
private:

};

extern port Port;

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#endif // PORT_H
