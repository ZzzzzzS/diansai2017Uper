# 电赛上位机
## 2017全国大学生电子设计竞赛板球控制系统上位机
***
> 这是一个安卓版的蓝牙上位机,使用Qt on Android开发,原计划进入全国电赛总决赛时使用,可惜实力不够,没能进入全国总决赛.之后此上位机继续开发,供相关科技创新展示时控制板球系统使用.
# 项目地址
[https://github.com/ZzzzzzS/diansai2017Uper](https://github.com/ZzzzzzS/diansai2017Uper)
# 功能简介
* 蓝牙SPP协议连接HC-05等蓝牙串口模块
* 蓝牙串口调试接收数据
* 按键控制板球上球的移动
* 手势控制球移动

![调试界面](http://ww4.sinaimg.cn/large/0060lm7Tly1fkyep92vhcj30u01hc0yc.jpg)
调试界面
![手势控制](http://ww3.sinaimg.cn/large/0060lm7Tly1fkyepbkoosj30u01hc7bx.jpg)
手势控制
![按键控制](http://ww3.sinaimg.cn/large/0060lm7Tly1fkyepb2gqwj30u01hcdlc.jpg)

# 开发经历
1. 利用上位机控制板球这个想法是在做电赛的初期就有了,在板球的控制程序里面一直保留有串口控制的相关代码,在最初的省电赛时我们组就展示了蓝牙控制板球,不过那时采用的是网上找的上位机控制软件.省赛结束就开始用Qt安卓开发上位机,准备在国电赛的时候能够使用自己开发的上位机.
2.开发过程中遇到的第一个难点是串口数据的读取.原本认为安卓蓝牙和Windows平台上的一样,蓝牙连接后就会自动生成一个虚拟串口,使用QSerialport类即可读取.后来发现不是这样的,必须使用Qt的蓝牙类读取,蓝牙类配置蓝牙为SPP串口模式,配置好UUID等,通过蓝牙的socket类实现数据的读写,与Windows差别较大,Windows的Qt还没有QBluetooth类,不知道为什么.
3.第二个难点是在不同界面下蓝牙状态的确定.解决方法是每次生成一个页或者销毁一个页时都会向构造函数或者析构函数传入蓝牙的相关信息,有点类似于安卓的页面上下文切换.
4.另外在设计"神奇控制"模式时,研究了陀螺仪值的读取,发现非常简单,只需一句话即可读取.与单片机上陀螺仪读取的复杂形成鲜明对比.
5.有点遗憾的是这个上位机的界面设计太简陋了,以后有时间一定会优化界面布局.
6.由于ios系统限制,ios蓝牙无法使用普通蓝牙协议读取未经过MFi认证的蓝牙设备,读取未经认证的设备只能通过BLE低功耗蓝牙协议,也就是说基于蓝牙2.0的hc-05蓝牙模块无法被ios设备搜索到(经过实验确实检测不到),计划下一步换装cc2541蓝牙模块后开发ios版本的蓝牙上位机.

# 蓝牙连接以及读取过程简介
> 首先感谢[Qt on Android 蓝牙开发 ](http://www.cnblogs.com/sigma0/p/5769527.html)这篇博客的作者,他的博客让我学到很多.Qt安卓搞蓝牙串口的相关资料确实太少了,官方帮助文档也写得不够详细.

### Qt蓝牙支持的平台
查阅[Qt官方帮助文档](http://doc.qt.io/qt-5/qtbluetooth-index.html)可知,Qt蓝牙和BLE蓝牙支持如下平台
![支持的蓝牙平台](http://ww4.sinaimg.cn/large/0060lm7Tly1fkyfnvyvonj30v507l3zw.jpg)

### 蓝牙基本组成
Qt蓝牙主要有以下3个类
* QBluetoothDeviceDiscoveryAgent 负责蓝牙的查找
* QBluetoothLocalDevice 负责蓝牙设备开关状态以及工作模式
* QBluetoothSocket 负责蓝牙的数据传输

使用前需要在pro中添加
``QT += bluetooth `` 
添加头文件

```
#include <QtBluetooth> 
#include <QBluetoothAddress>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothLocalDevice>
#include <QBluetoothSocket> 
```

### 蓝牙的初始化
蓝牙初始化主要就是要配置好[UUID](http://blog.csdn.net/zf_c_cqupt/article/details/52177723)如果需要蓝牙串口的话使用我这个uuid即可,直接上代码
```
BlueTooth::BlueTooth(QWidget *parent) : QWidget(parent)
{
    this->ServiceUuid=QLatin1String("00001101-0000-1000-8000-00805F9B34FB");
    this->LocalDevice=new QBluetoothLocalDevice();
    this->DiscoverAgent=new QBluetoothDeviceDiscoveryAgent();
    this->Socket=new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
}
```
### 蓝牙打开与关闭
蓝牙打开与关闭很简单,需要注意的是部分安卓手机权限审核非常严格,可能还是需要在系统里面手动打开关闭蓝牙.
```
void BlueTooth::Power(bool Power)
{
    if(Power==true)
    {
        this->LocalDevice->powerOn();
    }
    else if(Power==false)
        this->LocalDevice->setHostMode(QBluetoothLocalDevice::HostPoweredOff);
}
```
**值得注意的是蓝牙关闭并不是写PowerOff**

### 蓝牙的查找
蓝牙查找只需要使用QBluetoothDeviceDiscoveryAgent类查找即可,查找后会自动发送信号,这样我们只需要写一个找到信号的槽函数,在槽函数里保存蓝牙的名称,**UUID**等等.一定要保存**UUID**我们知道蓝牙连接是使用UUID来连接的,后面连接时还需要用到所以一定要保存下来.由于不清楚找到的蓝牙设备个数,我使用一个向量来保存所有找到的蓝牙信息.由于涉及到信号槽的操作,需要仔细的分析信号槽的连接情况,不然可能导致信号槽不触发或者重复触发的情况.
##### 扫描设置函数
```
void BlueTooth::scan()
{
    if(this->LocalDevice->hostMode()==QBluetoothLocalDevice::HostPoweredOff)
    {
        QMessageBox::information(NULL,"蓝牙未打开","请打开蓝牙后重试",QMessageBox::Ok);
    }
    QObject::disconnect(this->DiscoverAgent,SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),this,SLOT(Discoverd(QBluetoothDeviceInfo)));
    this->DeviceInfo.clear();
    this->DiscoverAgent->stop();
    this->DiscoverAgent->start();
    QObject::connect(this->DiscoverAgent,SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),this,SLOT(Discoverd(QBluetoothDeviceInfo)));
}
```
##### 扫描到的槽函数
为了实现在不同的界面上显示蓝牙连接情况,我又自己设计了一下信号槽
```
void BlueTooth::Discoverd(const QBluetoothDeviceInfo &info)
{
    this->DeviceInfo.append(info);
    QBluetoothDeviceInfo send=info;
    emit DisCoverdSignal(send);
}

void ConfigWindow::DisCoveredSlot(QBluetoothDeviceInfo InfoBase)
{
    ui->BluetoothBox->addItem(InfoBase.name().toUtf8());
}
```

### 蓝牙的连接和断开
蓝牙的连接和断开操作类似.扫描完成后就进入连接操作,连接使用QBluetoothSocket类即可.与扫描类似,连接完成后可以设置在连接完成后发送信号,在槽函数中显示相应的提示信息.蓝牙也可以连接错误时发送错误信号,进入错误槽函数等.同样,由于涉及信号槽,需要仔细处理连接问题.
```
//蓝牙连接函数
void BlueTooth::BlueToothConnect(QBluetoothDeviceInfo Base)
{
    QObject::disconnect(this->Socket,SIGNAL(connected()),this,SLOT(Connected()));
    this->Socket->connectToService(Base.address(),QBluetoothUuid(this->ServiceUuid));
    QObject::connect(this->Socket,SIGNAL(connected()),this,SLOT(Connected()));
}
//连接完成槽函数
void BlueTooth::Connected()
{
    emit this->ConnectOK(true);
    QMessageBox::information(NULL,"连接","已连接成功!",QMessageBox::Ok);

}

//断开函数
void BlueTooth::BlueToothDisConnect()
{
    QObject::disconnect(this->Socket,SIGNAL(disconnected()),this,SLOT(Disconnected()));
    this->Socket->disconnectFromService();
    QObject::connect(this->Socket,SIGNAL(disconnected()),this,SLOT(Disconnected()));
}

//断开成功槽函数
void BlueTooth::Disconnected()
{
    emit this->DisConnetOK(true);
    QMessageBox::information(NULL,"断开","已断开成功!",QMessageBox::Ok);

}
```

###蓝牙的传输
到了这么久才到了正题,蓝牙的传输,蓝牙的传输主要借助于QBluetoothSocket类,和串口的传输很类似.这里主要分为传入和传出来讲
#### 传出
传出操作比较简单,直接写``Socket->write(data.toUtf8());``
```
void BlueTooth::SafeWrite(QString data)
{
    if(this->Socket->state()==QBluetoothSocket::ConnectedState)
    {
        Socket->write(data.toUtf8());
    }
    else if(this->Socket->state()==QBluetoothSocket::UnconnectedState)
    {
        QMessageBox::information(NULL,"蓝牙未连接","请连接蓝牙或检查是否被其他程序占用",QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(NULL,"错误","请检查蓝牙是否打开",QMessageBox::Ok);
    }
}
```
以上是我设计的一个安全读写函数,可以在蓝牙未连接的时候报错

#### 传入
蓝牙的传入就要相对复杂一些,和串口一样需要使用到信号槽实现,有点类似于单片机当中的UART中断
首先是初始化信号槽`` QObject::connect(this->PortBase->Socket,SIGNAL(readyRead()),this,SLOT(ReceiveSlot()));``
其次是槽函数

```
void ConfigWindow::ReceiveSlot()
{
    if(ui->HEXBox->isChecked())
    {
        QByteArray buf=this->PortBase->Socket->read(1);
        QString str=" "+buf.toHex();
        ui->ReceiveAera->insertPlainText(str);
        buf.clear();
    }
    else if(!ui->HEXBox->isChecked())
    {
        QByteArray buf;
        buf =this->PortBase->Socket->readAll();
        QString str="下位机:"+buf;
        QString test=buf;
        qDebug()<<test.toInt();
        ui->ReceiveAera->append(str);
        buf.clear();
    }
}
```

蓝牙部分大概就说这么多,其实这也只涉及Qt蓝牙操作当中的冰山一角,还有很多的部分值得我们去研究.
***
# Qt安卓读取加速度计简介
说起读取加速度计,那么一定要提到Qt的传感器类了.Qt的传感器类为我们提供了访问手机传感器的功能.读取传感器以前都需要在pro文件里面添加
``
QT       += sensors
``

### 陀螺仪读取
#### 初始化
由于我们是读取陀螺仪,那么就需要使用QAccelerometer类
需要包含头文件``#include <QtSensors/QAccelerometer>``
同理,如果我们读取陀螺仪,那么就需要使用QGyroscope类,包含 ``#include <QGyroscope>``
我初始化时设置成定时器周期读取加速度计的值,所以在初始化的过程中也用到了QTimer类,以下是代码
```
    this->AcceSensor.start();//初始化传感器
    this->AcceScanTimer.start(10);//初始化定时器
    QObject::connect(&AcceScanTimer,SIGNAL(timeout()),this,SLOT(AcceScan()));
```
###读取值
读取值非常简单,一句话即可搞定,以下是读取代码
```
//读取传感器的值
        this->x=AcceSensor.reading()->x();
        this->y=AcceSensor.reading()->y();
        this->z=AcceSensor.reading()->z();
```
需要注意,读取回来的类型实际上就是double类型,不要被Qt的typedef所迷惑

**到这里整个加速度计的使用就完了**相比单片机又要配置i2c,又要配置陀螺仪寄存器,读取回来还要自己计算角度,自己滤波,安卓上面确实简单了太多. 
    
***
# 写在最后
**其实写到这里我已经不想再写下去了,但是谁叫我强迫症突然发作呢**
虽然遗憾没能拿到国电赛一等奖,没能在总决赛上使用这个上位机.学习编写安卓上位机的整个过程却学习到了很多知识.毕竟学习知识的过程才是最重要的.我下一步计划开发ios版蓝牙上位机,研究cc2541蓝牙模块配合上位机使用.同时也计划开发一个功能更复杂,界面更精美,可以在线调试多种参数的上位机供18年智能汽车竞赛调试使用.

