# 01_ffmpeg

##### 练习自定义槽函数
## 注意: Sender 参数个数可以 >= Receiver 的，但是反过来不行。假如 Receiver 接收参数个数比 Sender 传的多，则不会使用不安全内存地址，导致不可预知结果。
##### 1、Sender 
```c++
// sender.h
#ifndef SENDER_H
#define SENDER_H

#include <QObject>

class Sender : public QObject {
    Q_OBJECT //Q_OBJECT用以支持自定义信号和槽
public:
    explicit Sender(QObject *parent = nullptr);
    ~Sender();

signals: // 自定义的信号需要写在signals:下面
    void exit(); //自定义的信号只需要声明，不需要实现
    int exit_2(int a, int b); //有返回函数，入参的函数
};

#endif // SENDER_H
```
```c++
// sender.cpp
#include "sender.h"
#include <QDebug>

Sender::Sender(QObject *parent) : QObject(parent) {

}

Sender::~Sender()
{
    qDebug() << "Sender Release";
}
```
##### 2、Receiver
```c++
// Receiver.h
#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>

class Receiver : public QObject {
    Q_OBJECT
public:
    explicit Receiver(QObject *parent = nullptr);
    ~Receiver();

public slots: //自定义的槽建议写在public slots:下面
    void handleExit();
    int handleExit_2(int a, int b);

};

#endif // RECEIVER_H
```
```c++
#include "receiver.h"
#include <QDebug>

Receiver::Receiver(QObject *parent) : QObject(parent)
{

}

void Receiver::handleExit() {
    qDebug() << "自定的槽函数 Receiver::handleExit()";
}

int Receiver::handleExit_2(int a, int b) {
    return a+b;
}

Receiver::~Receiver()
{
    qDebug() << "Receiver Release";
}
```
##### 3、usage
```c++
#include "sender.h"
#include "receiver.h"

void xxxx()
{
    Sender *sender = new Sender;
    Receiver *receiver = new Receiver;

    connect(sender, &Sender::exit, receiver, &Receiver::handleExit);

    sender->exit();

    connect(sender, &Sender::exit_2, receiver, &Receiver::handleExit_2);

    int a = sender->exit_2(10,30);

    qDebug() << a;

    delete sender;
    delete receiver;
}
```
