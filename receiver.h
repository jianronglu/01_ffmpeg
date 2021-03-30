#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>

class Receiver : public QObject {
    Q_OBJECT
public:
    explicit Receiver(QObject *parent = nullptr);

public slots: //自定义的槽建议写在public slots:下面
    void handleExit();
    int handleExit_2(int a, int b);
};

#endif // RECEIVER_H
