#ifndef DB_H
#define DB_H
#include <QtSql>
#include "student.h"
#include "course.h"

using namespace std;

namespace Db {
    bool connect();
    bool init();
    bool updateCourse(int id, QString name, QString description);
    vector<Student> test();
    bool testInsert();
    bool testUpdate();
    bool testDelete();
    bool testDeleteall();
}



#endif // DB_H
