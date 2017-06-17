#include "db.h"
#include <QApplication>
#include <QtSql>
#include <QtDebug>

bool db::connect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("db.sqlite");
    if (!db.open()){
        qDebug() << "Database Error!";
        return false;
    }
    return true;
}
