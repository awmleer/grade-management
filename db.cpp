#include "db.h"

#include <QtSql>
#include <QtDebug>

namespace Db {
    QSqlDatabase db;
}

bool Db::connect(){
    Db::db = QSqlDatabase::addDatabase("QSQLITE");
    Db::db.setDatabaseName("db.sqlite");
    if (!Db::db.open()){
        qDebug() << "Database Error!";
        return false;
    }
    return true;
}

bool Db::test(){
    QSqlQuery query("SELECT * FROM student");
    int idName = query.record().indexOf("name");
    while (query.next())
    {
       QString name = query.value(idName).toString();
       qDebug() << name;
    }
    return true;
}
