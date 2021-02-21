#include "mythread.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif


MyThread::MyThread(QObject *parent) : QThread(parent)
{

}

void MyThread::run()
{
    // 这是一个复杂的操作
    sleep(5);
    emit sigDone();
}
