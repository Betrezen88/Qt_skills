#include "Object.hpp"

#include <QDebug>

Object::Object()
{
    // Connecting signal and slots in new style
    connect(this, &Object::dummyChanged, this, &Object::dummyDebug);
    // Connecting signal and slots in old style
    //connect(this, SIGNAL(dummyChanged(QString)), this, SLOT(dummyDebug(QString));
}

QString Object::dummy() const
{
    return m_dummy;
}

void Object::setDummy(const QString &dummy)
{
    m_dummy = dummy;
    emit dummyChanged(dummy);
}

void Object::dummyDebug(const QString &dummy)
{
    qDebug() << "Dummy changed to: " << dummy;
}
