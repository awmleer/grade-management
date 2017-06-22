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
    void setName(QString name);
    QString getType(){
        return type;
    }
    void setType(QString type);
    int getEnrollmentYear(){
        return enrollmentYear;
    }
    void setEnrollmentYear(int enrollmentYear);

//TODO: set these properties private
//private:
    int id;
    QString name;
    QString type;
    int enrollmentYear;
};

#endif // STUDENT_H
