#include "course.h"
#include "db.h"

using namespace std;

Course::Course(int id, QString name, QString description):
    id(id), name(name), description(description){}

void Course::setName(QString name){
    this->name=name;
}

void Course::setDescription(QString description){
    this->description=description;
}

bool Course::save(){
    return Db::updateCourse(id,name,description);
}


int Course::create(QString name, QString description){
    return Db::insertCourse(name,description);
}

bool Course::remove(){
    return Db::deleteCourse(id);
}

vector<Course> Course::all(){
    return Db::searchCourse();
}

vector<Course> Course::searchById(int id){
    return Db::searchCourseById(id);
}

vector<Course> Course::searchByName(QString name){
    return Db::searchCourseByName(name);
}



