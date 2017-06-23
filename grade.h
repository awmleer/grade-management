#ifndef GRADE_H
#define GRADE_H

#include <QString>

class Grade{
public:
    Grade(int studentId, int courseId, QString takeTime, int score);
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

    bool save();
    static int create(int studentId, int courseId, QString takeTime, int score);//returns the courseId if success, else returns -1
    bool remove();

private:
    int studentId;
    int courseId;
    QString takeTime;
    int score;
};

#endif // GRADE_H
