#include "student.h"
#include <QString>
#include "db.h"

using namespace std;

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

vector<Student> Student::all(){
    return Db::searchStudent();
}

vector<Student> Student::searchById(int id){
    return Db::searchStudentById(id);
}

vector<Student> Student::searchByName(QString name){
    return Db::searchStudentByName(name);
}

vector<Student> Student::searchByType(QString type){
    return Db::searchStudentByType(type);
}


