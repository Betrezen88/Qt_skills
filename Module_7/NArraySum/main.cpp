/*
 * App will generate N-element array.
 * User enters N as parameter.
 * In QRunnable object will sum elements.
 * UI will show progress bar of sum operation.
 * UI will show sum result.
 */

#include "MainDialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainDialog w;
    w.show();

    return a.exec();
}
