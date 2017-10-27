#ifndef GENERATOR_H
#define GENERATOR_H

#include <QRunnable>
#include <QVector>
#include <QTime>

#include <QDebug>

class Generator : public QRunnable
{
public:
    Generator(QVector<int> &array) : m_array(array) {}

    void run()
    {
        qDebug() << "run()" << m_array.size();
        qsrand( QTime::currentTime().msec() );
        for ( int i=0; i<m_array.size(); ++i )
            qDebug() << "Number is:" << qrand() % 1000 + 1;
    }

private:
    QVector<int> m_array;
};

#endif // GENERATOR_H
