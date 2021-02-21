﻿#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif


class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);

protected:
    void run(); // 入口函数 -- 需要start（）启动

signals:
    void sigDone();

public slots:
};

#endif // MYTHREAD_H
