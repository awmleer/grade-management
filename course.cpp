#include "course.h"
#include "db.h"

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
