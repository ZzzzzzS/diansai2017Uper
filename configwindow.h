#ifndef CONFIGWINDOW_H
#define CONFIGWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include "bluetooth.h"

namespace Ui {
class ConfigWindow;
}

class ConfigWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigWindow(QWidget *parent = 0);
    ~ConfigWindow();
    BlueTooth *PortBase;

private slots:
    void PowerSlot();
    void ScanSlot();
    void ConnetSlot();
    void DisCoveredSlot(QBluetoothDeviceInfo InfoBase);
    void ReceiveSlot();
    void SendSlot();
    void SaveSlot();

private:
    Ui::ConfigWindow *ui;
};

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#endif // CONFIGWINDOW_H
