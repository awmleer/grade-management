#ifndef STUDENT_H
#define STUDENT_H
#include <QString>
#include <vector>

using namespace std;

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

    bool save();
    bool remove();

    static int create(int id, QString name, QString type, int enrollmentYear);//returns the studentId if success, else returns -1
    static vector<Student> all();
    static vector<Student> searchById(int id);
    static vector<Student> searchByName(QString name);
    static vector<Student> searchByType(QString type);

private:
    int id;
    QString name;
    QString type;
    int enrollmentYear;
};

#endif // STUDENT_H
