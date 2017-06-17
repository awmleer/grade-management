#include "mainwindow.h"
#include <QApplication>
#include "db.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Db::connect();//init sqlite database
    Db::test();
    w.show();


    return a.exec();
}
