#ifndef CONFIGWINDOW_H
#define CONFIGWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include "port.h"

namespace Ui {
class ConfigWindow;
}

class ConfigWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigWindow(QWidget *parent = 0);
    ~ConfigWindow();

private slots:
    void PortChackSlot();
    void PortOpenSlot();
    void PortSaveSlot();
    void ReceiveSlot();
    void SendSlot();


private:
    Ui::ConfigWindow *ui;
    void PortToRight();
};

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#endif // CONFIGWINDOW_H
