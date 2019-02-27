#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window mainWin;
    mainWin.show();
    return a.exec();
}
