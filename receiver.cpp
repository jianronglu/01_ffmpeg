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
