#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <QObject>

/*
 * (F)irtst way of communication between C++ and Qml is exposing
 * C++ object attributes as properties in Qml. Rules to achive that are:
 */

class Message : public QObject // (F)1) C++ object must be child of QObject
{
    Q_OBJECT                                                                        // (F)2) Must have Q_OBJECT macro
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged) // (F)3) Attributes must be exposed by Q_PROPERTY macro
    Q_PROPERTY(int counter READ counter NOTIFY counterChanged)

public:
    Message() { m_counter = 0; }

    void setMessage(const QString &message)
    {
        if ( message != m_message )
        {
            ++m_counter;
            m_message = message;
            emit messageChanged();
            emit counterChanged();
        }
    }

    QString message() { return m_message; }
    int counter() { return m_counter; }

signals:
    void messageChanged();
    void counterChanged();

private:
    QString m_message;
    int m_counter;          // (F)4) They can't be static.
};

#endif // MESSAGE_HPP
