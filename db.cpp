#include "db.h"
#include <QtSql>
#include <QtDebug>
#include <QApplication>
#include <vector>
#include "student.h"

namespace Db {
QSqlDatabase db;
}

using namespace Db;

bool Db::connect(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("db.sqlite");
    if (!db.open()){
        qDebug() << "Database Error!";
        return false;
    }
    return true;
}

vector<Student> Db::test(){
    QSqlQuery query("SELECT * FROM student");
    int idNo = query.record().indexOf("id");
    int nameNo = query.record().indexOf("name");
    int typeNo = query.record().indexOf("type");
    int enrollmentYearNo = query.record().indexOf("enrollmentYear");
    vector<Student> students;
    while (query.next())
    {
        Student student(
                    query.value(idNo).toInt(),
                    query.value(nameNo).toString(),
                    query.value(typeNo).toString(),
                    query.value(enrollmentYearNo).toInt()
                    );
        students.push_back(student);
//        QString name = query.value(nameNo).toString();
        qDebug() << students.size();
    }
    return students;
}
