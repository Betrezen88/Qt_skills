#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>
#include <QTime>
#include <QElapsedTimer>

class WorkerThread : public QThread
{
    Q_OBJECT

    void run()
    {
        QElapsedTimer timer;
        timer.start();
        QString result;

        qsrand( QTime::currentTime().msec() );
        int wait = qrand() % 1000 + 1;
        while ( wait != 0 )
            --wait;

        result = "Result generated in: "
                + QString::number( timer.nsecsElapsed() )
                + " nsecs.";

        emit resultReady( result );
    }

signals:
    void resultReady(const QString &result);
};

#endif // WORKERTHREAD_H
