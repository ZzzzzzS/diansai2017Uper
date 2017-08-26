#ifndef PORT_H
#define PORT_H

#include <QObject>
#include <QWidget>

class port : public QObject
{
    Q_OBJECT
public:
    explicit port(QObject *parent = nullptr);

signals:

public slots:
};

#endif // PORT_H