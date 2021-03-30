#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


#include "sender.h"
#include "receiver.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

MainWindow::~MainWindow()
{
    delete ui;
}

// on_控件的变量名_事件名
void MainWindow::on_firstButton_clicked()
{
    qDebug() << ui->firstButton->text();
}
