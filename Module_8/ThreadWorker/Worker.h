#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QElapsedTimer>
#include <QTime>

class Worker : public QObject
{
signals:
    void finished();
    void resultReady(const QString &result);

public slots:
    void process()
    {

    }
};

#endif // WORKER_H
