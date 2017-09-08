#include "mainwindow.h"
#include <QApplication>
#include "bluetooth.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BlueTooth MainBluetooth;
    MainWindow w;
    w.PortBase=&MainBluetooth;
    w.show();

    return a.exec();
}
