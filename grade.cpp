#include "grade.h"
#include "db.h"

Grade::Grade(int studentId, int courseId, QString takeTime, int score)
    :studentId(studentId),courseId(courseId),takeTime(takeTime),score(score){}

void Grade::setTakeTime(QString takeTime){
    this->takeTime=takeTime;
}

void Grade::setScore(int score){
    this->score=score;
}


Student Grade::fetchStudent(){
    return Db::searchStudentById(studentId)[0];
}
Course Grade::fetchCourse(){
    return Db::searchCourseById(courseId)[0];
}


bool Grade::save(){
    return Db::updateGrade(id,takeTime,score);
}

int Grade::create(int studentId, int courseId, QString takeTime, int score){
    return Db::insertGrade(studentId,courseId,takeTime,score);
}

bool Grade::remove(){
    return Db::deleteGrade(id);
}

