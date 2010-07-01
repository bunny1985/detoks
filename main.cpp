#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qApp->addLibraryPath( qApp->applicationDirPath() + "/plugins");
    a.setQuitOnLastWindowClosed(false);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("Windows-1250"));
    MainWindow w;
    w.show();

    return a.exec();
}
