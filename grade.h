#ifndef GRADE_H
#define GRADE_H

#include <QString>
#include "student.h"
#include "course.h"

class Grade{
public:
    Grade(int id, int studentId, int courseId, QString takeTime, int score);
    int getId(){
        return id;
    }
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
    int getScore(){
        return score;
    }
    void setScore(int score);

    Student fetchStudent();
    Course fetchCourse();


    bool save();
    static int create(int studentId, int courseId, QString takeTime, int score);//returns the courseId if success, else returns -1
    bool remove();

    static vector<Grade> all();
    static vector<Grade> searchById(int id);
    static vector<Grade> searchByCourseId(int courseId);
    static vector<Grade> searchByStudentId(int studentId);
    static vector<Grade> searchByTakeTime(QString takeTime);
    static vector<Grade> searchByScore(int min, int max);//score>=min && score<=max

private:
    int id;
    int studentId;
    int courseId;
    QString takeTime;
    int score;
};

#endif // GRADE_H
