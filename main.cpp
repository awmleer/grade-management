#include "mainwindow.h"
#include <QApplication>
#include "db.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    db::connect();//init sqlite database
    w.show();


    return a.exec();
}
