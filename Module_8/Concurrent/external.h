#ifndef EXTERNAL_H
#define EXTERNAL_H

#include <QString>
#include <QElapsedTimer>
#include <QTime>
#include <QVector>

QString myFunction()
{
    QElapsedTimer timer;
    timer.start();
    QString result;
    QVector<int> array;
    qsrand( QTime::currentTime().msec() );
    int size = qrand() % 100000 + 10000, i = 0;

    while ( i < size )
    {
        array.append( qrand() % 100 + 1 );
        ++i;
    }

    int sum = 0;
    for ( QVector<int>::iterator it=array.begin(); it != array.end(); ++it )
        sum += *it;

    result = "This example presents running function by QtConcurrent::run().\n";
    result += "This function generates array with random size(10000 - 100000) and fills it with random numbers (1 - 100).\n";
    result += "Sum of all elements of array is: " + QString::number( sum ) + ".\n";
    result += "Operation time: " + QString::number( timer.elapsed() ) + " nsec.";

    return result;
}

bool isLowerCase(const QString &string)
{
    return string.toLower() == string;
}

bool lessThen10(int value)
{
    return value < 10;
}

#endif // EXTERNAL_H
