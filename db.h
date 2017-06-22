#ifndef DB_H
#define DB_H
#include <QtSql>
#include "student.h"
#include "course.h"

using namespace std;

namespace Db {
    bool connect();
    bool init();
    vector<Course> queryToCourseVector(QSqlQuery &query);
    vector<Course> searchCourse();
    vector<Course> searchCourse(int id);
    bool updateCourse(int id, QString name, QString description);
    int insertCourse(QString name, QString description);//returns id of the new course
    bool deleteCourse(int id);

    vector<Student> test();
    bool testInsert();
    bool testUpdate();
    bool testDelete();
    bool testDeleteall();
}




#endif // DB_H
