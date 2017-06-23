#ifndef GRADE_H
#define GRADE_H

#include <QString>

class Grade{
public:
    Grade(int studentId, int courseId, QString takeTime, int grade);
    int getStudentId(){
        return studentId;
    }
    int getCourseId(){
        return courseId;
    }
    QString getTakeTime(){
        return takeTime;
    }
    void setTakeTime(QString takeTime);
    int getGrade(){
        return grade;
    }
    void setGrade(int grade);

    bool save();
    static int create(int studentId, int courseId, QString takeTime, int grade);//returns the courseId if success, else returns -1
    bool remove();

private:
    int studentId;
    int courseId;
    QString takeTime;
    int grade;
};

#endif // GRADE_H
