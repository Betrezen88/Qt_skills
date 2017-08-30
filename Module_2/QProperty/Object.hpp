#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <QObject>
#include <QString>

class Object : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString dummy READ dummy WRITE setDummy NOTIFY dummyChanged)
public:
    Object();

    QString dummy() const;
    void setDummy(const QString &dummy);

signals:
    void dummyChanged(const QString &dummy);

public slots:
    void dummyDebug(const QString &dummy);

private:
    QString m_dummy;
};

#endif // OBJECT_HPP
