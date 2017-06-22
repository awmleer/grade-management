#include "course.h"
#include "db.h"

Course::Course(int id, QString name, QString description):
    id(id), name(name), description(description){}

void Course::setName(QString name){
    name=name;
}

void Course::setDescription(QString description){
    description=description;
}

bool Course::save(){
    return Db::updateCourse(id,name,description);
}


Course Course::create(QString name, QString description){
    int id=Db::insertCourse(name,description);
    return Course(id,name,description);
}

bool Course::remove(){
    return Db::deleteCourse(id);
}
