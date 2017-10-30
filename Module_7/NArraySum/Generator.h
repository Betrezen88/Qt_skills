#ifndef GENERATOR_H
#define GENERATOR_H

#include <QObject>
#include <QRunnable>
#include <QVector>
#include <QTime>

#include <QDebug>

class Generator : public QObject, public QRunnable
{
    Q_OBJECT
public:
    Generator(int size) : m_size(size) {}

    void run()
    {
        QVector<int> array;
        qsrand( QTime::currentTime().msec() );
        for ( int i=0; i<m_size; ++i )
             array.append( qrand() % 1000 + 1 );
        emit finished( array );
    }

signals:
    void finished(QVector<int> array);

private:
    int m_size;
};

#endif // GENERATOR_H