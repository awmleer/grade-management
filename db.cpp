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

bool Db::init(){
    bool connectResult = Db::connect();
    if (connectResult==false) return false;
    qDebug() << "db connect: " << connectResult;
    QSqlQuery query;
    //create student table
    qDebug() << query.prepare("CREATE TABLE IF NOT EXISTS student ("
                              "id INTEGER PRIMARY KEY,"
                              "name VARCHAR(30),"
                              "type VARCHAR(10),"
                              "enrollmentYear SMALLINT"
                              ");"
                              );
    if(query.exec()==false){
        return false;
    }
    //create course table
    qDebug() << query.prepare("CREATE TABLE IF NOT EXISTS course ("
                              "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                              "name VARCHAR(30),"
                              "description VARCHAR(200)"
                              ");"
                              );
    if(query.exec()==false){
        return false;
    }
    //create grade table
    qDebug() << query.prepare("CREATE TABLE IF NOT EXISTS grade ("
                              "studentId INTEGER NOT NULL,"
                              "courseId INTEGER NOT NULL,"
                              "takeTime VARCHAR(20), -- eg. '2016first', '2015second'"
                              "grade INTEGER,"
                              "PRIMARY KEY (studentId, courseId),"
                              "FOREIGN KEY (courseId) REFERENCES course(id),"
                              "FOREIGN KEY (studentId) REFERENCES student(id)"
                              ");"
                              );
    if(query.exec()==false){
        return false;
    }
    return true;
}


bool Db::updateCourse(int id, QString name, QString description){
    QSqlQuery query;
    query.prepare("update course set name = :name, description = :description where id = :id");
    query.bindValue(":id",id);
    query.bindValue(":name",name);
    query.bindValue(":description",description);
    return query.exec();
}


bool Db::testInsert(){
    QSqlQuery query;
    query.prepare("INSERT INTO student (id, name, type, enrollmentYear) "
                  "VALUES (:id, :name, :type, :enrollmentYear)"
                  );
    query.bindValue(":id", 1001);
    query.bindValue(":name", "Bart");
    query.bindValue(":type", "master");
    query.bindValue(":enrollmentYear",2016);
    return query.exec();
}

bool Db::testUpdate(){
    QSqlQuery update;
    update.prepare("update student set name = :name where id = :id");
    update.bindValue(":name","Justin");
    update.bindValue(":id",1002);
    return update.exec();
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
    }
    qDebug() << students.size();
    return students;
}

bool Db::testDelete(){
    QSqlQuery SQLdelete;
    SQLdelete.prepare("delete from student where id = :id");
    SQLdelete.bindValue(":id",1003);
    if(!SQLdelete.exec()){
        qDebug() << "delete failed!";
    } else {
        qDebug() << "delete success!";
    }
    return SQLdelete.exec();
}

bool Db::testDeleteall(){
    QSqlQuery SQLdeleteall;
    SQLdeleteall.prepare("delete from student");
    if(!SQLdeleteall.exec()){
        qDebug() << "delete-all failed!";
    } else {
        qDebug() << "delete-all success!";
    }
    return SQLdeleteall.exec();
}
