#ifndef DB_H
#define DB_H
#include <QtSql>
#include "student.h"

using namespace std;

namespace Db {
    bool connect();
    bool init();
    vector<Student> test();
    bool testInsert();
}



#endif // DB_H
