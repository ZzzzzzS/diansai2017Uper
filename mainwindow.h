﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <configwindow.h>
#include "bluetooth.h"
#include <QDesktopServices>
#include <QtSensors/QAccelerometer>
#include <QTimer>
#include <QGyroscope>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    BlueTooth *PortBase;

private slots:
    void ConfigSlot();
    void ReceiveSlot();
    void PowerSlot();
    void DebugSlot();
    void UpSlot();
    void DownSlot();
    void LeftSlot();
    void RightSlot();
    void Slot1();
    void Slot2();
    void Slot3();
    void Slot4();
    void Slot5();
    void Slot6();
    void Slot7();
    void Slot8();
    void Slot9();
    void ConnetOKSlot();
    void DisconnetOKSlot();
    void AcceScan();
private:
    Ui::MainWindow *ui;

    QTimer AcceScanTimer;
    QAccelerometer AcceSensor;
    double x,y,z;
};
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#endif // MAINWINDOW_H
