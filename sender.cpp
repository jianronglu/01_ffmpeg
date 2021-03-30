
#include "sender.h"
#include <QDebug>

Sender::Sender(QObject *parent) : QObject(parent) {

}

Sender::~Sender()
{
    qDebug() << "Sender Release";
}
