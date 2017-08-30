#include <QCoreApplication>
#include <QVariant>

#include "Object.hpp"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    Object object;
    // By connection we are always informed about dummy property changed.
    object.setDummy("testDummy");

    // Thanks to inheretance we can cast our object to QObject.
    QObject *obj = &object;
    // Thanks to Q_PROPERTY macro after cast we can change our dummy property.
    obj->setProperty("dummy", QVariant("dummyTest"));

    return 0;
}
