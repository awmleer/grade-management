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
                              "name VARCHAR(30) UNIQUE,"
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
                              "takeTime VARCHAR(20),"
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


QString Db::getLastExecutedQuery(const QSqlQuery& query)
{
    QString str = query.lastQuery();
    QMapIterator<QString, QVariant> it(query.boundValues());
    while (it.hasNext())
    {
        it.next();
        str.replace(it.key(),it.value().toString());
    }
    return str;
}


vector<Course> Db::queryToCourseVector(QSqlQuery &query){
    vector<Course> courses;
    int idNo = query.record().indexOf("id");
    int nameNo = query.record().indexOf("name");
    int descriptionNo = query.record().indexOf("description");
    while (query.next()){
        Course course(
                    query.value(idNo).toInt(),
                    query.value(nameNo).toString(),
                    query.value(descriptionNo).toString()
                    );
        courses.push_back(course);
    }
    qDebug() <<"Got "<<courses.size()<<" courses";
    return courses;
}
vector<Student> Db::queryToStudentVector(QSqlQuery &query){
    vector<Student> students;
    int idNo = query.record().indexOf("id");
    int nameNo = query.record().indexOf("name");
    int typeNo = query.record().indexOf("type");
    int enrollmentYearNo = query.record().indexOf("enrollmentYear");
    while (query.next()){
        Student student(
                    query.value(idNo).toInt(),
                    query.value(nameNo).toString(),
                    query.value(typeNo).toString(),
                    query.value(enrollmentYearNo).toInt()
                    );
        students.push_back(student);
    }
    qDebug() <<"Got "<<students.size()<<" students";
    return students;
}



/*
 * Course Search
*/
vector<Course> Db::searchCourse(){
    qDebug()<<"Running Db::searchCourse()";
    QSqlQuery query("SELECT * FROM course;");
    return queryToCourseVector(query);
}
vector<Course> Db::searchCourseById(int id){
    qDebug()<<"Running Db::searchCourseById(int id)";
    QSqlQuery query;
    query.prepare("SELECT * FROM course WHERE id = :id ;");
    query.bindValue(":id",id);
    query.exec();
    return queryToCourseVector(query);
}
vector<Course> Db::searchCourseByName(QString name){
    qDebug()<<"Running Db::searchCourseByName(QString name)";
    QSqlQuery query;
    qDebug()<<name;
    query.prepare("SELECT * FROM course WHERE name LIKE :name ;");
    query.bindValue(":name","%"+name+"%");
    qDebug()<<getLastExecutedQuery(query);
    query.exec();
    return queryToCourseVector(query);
}

/*
 * Course Operation
*/
bool Db::updateCourse(int id, QString name, QString description){
    QSqlQuery query;
    query.prepare("UPDATE course SET name = :name, description = :description WHERE id = :id ;");
    query.bindValue(":id",id);
    query.bindValue(":name",name);
    query.bindValue(":description",description);
    return query.exec();
}
int Db::insertCourse(QString name, QString description){
    QSqlQuery query;
    query.prepare("INSERT INTO course (name, description) "
                  "VALUES (:name, :description);"
                  );
    query.bindValue(":name",name);
    query.bindValue(":description",description);
    if(query.exec()==false){
        return -1;
    }
    query.prepare("select max(id) from grade;");
    query.next();
    return query.value(0).toInt();
}
bool Db::deleteCourse(int id){
    QSqlQuery query;
    query.prepare("DELETE FROM course WHERE id = :id");
    query.bindValue(":id",id);
    return query.exec();
}



/*
 * Student Search
*/
vector<Student> Db::searchStudent(){
    qDebug()<<"Running Db::searchStudent()";
    QSqlQuery query("SELECT * FROM student;");
    return queryToStudentVector(query);
}
vector<Student> Db::searchStudentById(int id){
    qDebug()<<"Running Db::searchStudentById(int id)";
    QSqlQuery query;
    query.prepare("SELECT * FROM student WHERE id = :id ;");
    query.bindValue(":id",id);
    query.exec();
    return queryToStudentVector(query);
}
vector<Student> Db::searchStudentByName(QString name){
    qDebug()<<"Running Db::searchStudentByName(QString name)";
    QSqlQuery query;
    query.prepare("SELECT * FROM student WHERE name LIKE :name ;");
    query.bindValue(":name","%"+name+"%");
    qDebug()<<getLastExecutedQuery(query);
    query.exec();
    return queryToStudentVector(query);
}
vector<Student> Db::searchStudentByType(QString type){
    qDebug()<<"Running Db::searchStudentByName(QString type)";
    QSqlQuery query;
    query.prepare("SELECT * FROM student WHERE type = :type ;");
    query.bindValue(":type",type);
    qDebug()<<getLastExecutedQuery(query);
    query.exec();
    return queryToStudentVector(query);
}

/*
 * Student Operation
*/
bool Db::updateStudent(int id, QString name, QString type, int enrollmentYear){
    QSqlQuery query;
    query.prepare("UPDATE student SET name = :name, type = :type, enrollmentYear = :enrollmentYear WHERE id = :id ;");
    query.bindValue(":id",id);
    query.bindValue(":name",name);
    query.bindValue(":type",type);
    query.bindValue(":enrollmentYear",enrollmentYear);
    return query.exec();
}
int Db::insertStudent(int id, QString name, QString type, int enrollmentYear){
    QSqlQuery query;
    query.prepare("INSERT INTO student (id, name, type, enrollmentYear) "
                  "VALUES ( :id, :name, :type, :enrollmentYear );"
                  );
    query.bindValue(":id",id);
    query.bindValue(":name",name);
    query.bindValue(":type",type);
    query.bindValue(":enrollmentYear",enrollmentYear);
    if(query.exec()==false){
        return -1;
    }
    return id;
}
bool Db::deleteStudent(int id){
    QSqlQuery query;
    query.prepare("DELETE FROM student WHERE id = :id");
    query.bindValue(":id",id);
    return query.exec();
}






/*
 * Test Functions
*/

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
