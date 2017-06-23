#include "grade.h"

Grade::Grade(int studentId, int courseId, QString takeTime, int score)
    :studentId(studentId),courseId(courseId),takeTime(takeTime),score(score){}

void Grade::setTakeTime(QString takeTime){
    this->takeTime=takeTime;
}

void Grade::setScore(int score){
    this->score=score;
}


//bool Grade::save(){

//}

//int Grade::create(int studentId, int courseId, QString takeTime, int grade){

//}

//bool Grade::remove(){

//}

