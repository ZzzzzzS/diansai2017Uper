﻿#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <QObject>
#include <QWidget>
#include <QtBluetooth>
#include <QBluetoothAddress>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothLocalDevice>
#include <QBluetoothSocket>
#include <QString>
#include <QLatin1String>
#include <QtDebug>
#include <QMessageBox>

class BlueTooth : public QWidget
{
    Q_OBJECT
public:
    explicit BlueTooth(QWidget *parent = nullptr);
    void scan();
    void Power(bool Power);
    void SafeWrite(QString data);
    void BlueToothConnect(const QBluetoothDeviceInfo *Base);
    void BlueToothDisConnect();
    QList<QBluetoothDeviceInfo> DeviceInfo;
    QBluetoothSocket *Socket;

public slots:
    void Discoverd(const QBluetoothDeviceInfo &info);

private:
    QLatin1String ServiceUuid;
    QBluetoothDeviceDiscoveryAgent *DiscoverAgent;
    QBluetoothLocalDevice *LocalDevice;

private slots:
    void Connected();
    void Disconnected();
    void ConnectError();
};

#endif // BLUETOOTH_H
