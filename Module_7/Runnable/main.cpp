#include <QCoreApplication>
#include <QThreadPool>

#include "HelloWorldTask.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    HelloWorldTask *hello = new HelloWorldTask();

    // QThreadPool takes ownership and deletes 'hello' automatically
    QThreadPool::globalInstance()->start(hello);

    return a.exec();
}
