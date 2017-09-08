#ifndef BLUETOOTH_H
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
    void BlueToothConnect(QBluetoothDeviceInfo Base);
    void BlueToothDisConnect();
    QList<QBluetoothDeviceInfo> DeviceInfo;
    QBluetoothSocket *Socket;
    QBluetoothDeviceInfo CurrentDeviceInfo;
    QBluetoothLocalDevice *LocalDevice;
public slots:


private:
    QLatin1String ServiceUuid;
    QBluetoothDeviceDiscoveryAgent *DiscoverAgent;


private slots:
    void Connected();
    void Disconnected();
    //void ConnectError();
    void Discoverd(const QBluetoothDeviceInfo &info);

signals:
    void DisCoverdSignal(QBluetoothDeviceInfo);
    void ConnectOK(bool);
    void DisConnetOK(bool);
};

#endif // BLUETOOTH_H
