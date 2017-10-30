#ifndef ADDER_H
#define ADDER_H

#include <QObject>
#include <QRunnable>
#include <QVector>

class Adder : public QObject, public QRunnable
{
    Q_OBJECT
public:
    Adder(QVector<int> &array) : m_array(array) {}

    void run()
    {
        int sum = 0;
        for ( int i=0; i<m_array.size(); ++i )
            sum += m_array.at(i);
        finished( sum );
    }

signals:
    void finished(const int sum);

private:
    QVector<int> m_array;
};

#endif // ADDER_H
