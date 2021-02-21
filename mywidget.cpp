#include "mywidget.h"
#include "ui_mywidget.h"
#include <QThread>
#include <QDebug>

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif


MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    mytimer = new QTimer(this);
    myt = new MyThread(this);


    connect(mytimer, &QTimer::timeout, [=]()
    {
        static int num = 0;
        ui->lcdNumber->display(num++);

    });

    // 子线程信号
    connect(myt, &MyThread::sigDone, mytimer, &QTimer::stop);

}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_begin_clicked()
{
    if(mytimer->isActive() == true)
    {
        return;
    }
    // 启动定时器

    mytimer->start(500); //ms

    // 启动线程
    myt->start();

//    // 复杂的操作
//    QThread::sleep(5); //s

//    // 关闭定时器
//    mytimer->stop();
//    qDebug() << "time is stop.....";


}
