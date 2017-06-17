#ifndef DB_H
#define DB_H
#include <QtSql>
#include <string>

using namespace std;

namespace Db {
    bool connect();
    bool test();
}

//class Student{
//    int id;
//    string name;
//    string type;
//    short enrollmentYear;
//};


#endif // DB_H
