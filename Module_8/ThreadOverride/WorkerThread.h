#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>

class WorkerThread : public QThread
{
    Q_OBJECT

    void run()
    {

    }

signals:
    void resultReady(const QString &result);
};

#endif // WORKERTHREAD_H
