#ifndef HELLOWORLDTASK_H
#define HELLOWORLDTASK_H

#include <QRunnable>
#include <QThread>
#include <QDebug>

class HelloWorldTask : public QRunnable
{
public:
    void run()
    {
        qDebug() << "Hello World from thread" << QThread::currentThread();
    }
};

#endif // HELLOWORLDTASK_H
