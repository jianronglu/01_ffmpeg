#ifndef SENDER_H
#define SENDER_H

#include <QObject>

class Sender : public QObject {
    Q_OBJECT //Q_OBJECT用以支持自定义信号和槽
public:
    explicit Sender(QObject *parent = nullptr);

signals: // 自定义的信号需要写在signals:下面
    void exit(); //自定义的信号只需要声明，不需要实现
    int exit_2(int a, int b); //有返回函数，入参的函数
};

#endif // SENDER_H
