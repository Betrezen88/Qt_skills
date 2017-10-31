#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QElapsedTimer>
#include <QTime>

class Worker : public QObject
{
    Q_OBJECT

signals:
    void finished();
    void resultReady(const QString &result);

public slots:
    void process()
    {
        QElapsedTimer timer;
        timer.start();
        QString result;
        qsrand( QTime::currentTime().msec() );
        int wait = qrand() % 10000000 + 1000000;
        while ( wait > 0 )
            --wait;
        result = "Result generated in " + QString::number( timer.elapsed() ) + " nsec.";
        emit resultReady( result );
        emit finished();
    }
};

#endif // WORKER_H
