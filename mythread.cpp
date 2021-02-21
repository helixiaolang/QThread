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
    for(int i = 0; i < 1000000; i++)
    {
        for(int j = 0; j < 123456789; j++)
        {

        }
    }
    emit sigDone();
}
