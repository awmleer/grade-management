#ifndef STUDENT_H
#define STUDENT_H
#include <QString>

class Student{
public:
    Student(int id, QString name, QString type, int enrollmentYear);
    int getId(){
        return id;
    }
    QString getName(){
        return name;
    }
    QString getType(){
        return type;
    }
    int getEnrollmentYear(){
        return enrollmentYear;
    }

    //Student();
    //Student(int id);
//    Student(int id, QString name, QString type, int enrollmentYear);
//private:
    int id;
    QString name;
    QString type;
    int enrollmentYear;
};

#endif // STUDENT_H
