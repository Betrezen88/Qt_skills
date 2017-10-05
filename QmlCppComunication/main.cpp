#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QDebug>

#include "Message.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Message msg;

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty( "Message", &msg); // (F)5) We need to pass our C++ object as contect property.

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
