#ifndef DB_H
#define DB_H
#include <QtSql>
#include "student.h"

using namespace std;

namespace Db {
    bool connect();
    vector<Student> test();
}



#endif // DB_H
