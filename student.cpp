#include "student.h"
#include <QString>

//Student::Student(int id):
  //  id(id){}
//id(id), name(name), type(type), enrollmentYear(enrollmentYear){}
//Student::Student(){}
Student::Student(int id, QString name, QString type, int enrollmentYear):
    id(id), name(name), type(type), enrollmentYear(enrollmentYear){}
