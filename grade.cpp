#include "grade.h"
#include "db.h"
#include <vector>

Grade::Grade(int id, int studentId, int courseId, QString takeTime, int score)
    :id(id),studentId(studentId),courseId(courseId),takeTime(takeTime),score(score){}

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


vector<Grade> Grade::all(){
    return Db::searchGrade();
}

vector<Grade> Grade::searchById(int id){
    return Db::searchGradeById(id);
}

vector<Grade> Grade::searchByCourseId(int courseId){
    return Db::searchGradeByCourseId(courseId);
}

vector<Grade> Grade::searchByStudentId(int studentId){
    return Db::searchGradeByStudentId(studentId);
}

vector<Grade> Grade::searchByTakeTime(QString takeTime){
    return Db::searchGradeByTakeTime(takeTime);
}

vector<Grade> Grade::searchByScore(int min, int max){
    return Db::searchGradeByScore(min,max);
}



