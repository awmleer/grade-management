#include "grade.h"

Grade::Grade(int studentId, int courseId, QString takeTime, int grade)
    :studentId(studentId),courseId(courseId),takeTime(takeTime),grade(grade){}

void Grade::setTakeTime(QString takeTime){
    this->takeTime=takeTime;
}

void Grade::setGrade(int grade){
    this->grade=grade;
}


bool Grade::save(){

}

int Grade::create(int studentId, int courseId, QString takeTime, int grade){

}

bool Grade::remove(){

}

