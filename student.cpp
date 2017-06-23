#include "student.h"
#include <QString>
#include "db.h"

//Student::Student(int id):
  //  id(id){}
//id(id), name(name), type(type), enrollmentYear(enrollmentYear){}
//Student::Student(){}
Student::Student(int id, QString name, QString type, int enrollmentYear):
    id(id), name(name), type(type), enrollmentYear(enrollmentYear){}

void Student::setName(QString name){
    this->name=name;
}

void Student::setType(QString type){
    this->type=type;
}

void Student::setEnrollmentYear(int enrollmentYear){
    this->enrollmentYear=enrollmentYear;
}



bool Student::save(){
    return Db::updateStudent(id,name,type,enrollmentYear);
}

int Student::create(int id, QString name, QString type, int enrollmentYear){
    return Db::insertStudent(id,name,type,enrollmentYear);
}

bool Student::remove(){
    return Db::deleteStudent(id);
}


