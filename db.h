#ifndef DB_H
#define DB_H
#include <QtSql>
#include "student.h"
#include "course.h"
#include "grade.h"

using namespace std;

namespace Db {
    bool connect();
    bool init();

    QString getLastExecutedQuery(const QSqlQuery& query);//for DEBUG

    vector<Course> queryToCourseVector(QSqlQuery &query);
    vector<Student> queryToStudentVector(QSqlQuery &query);
    vector<Grade> queryToGradeVector(QSqlQuery &query);


    vector<Course> searchCourse();
    vector<Course> searchCourseById(int id);
    vector<Course> searchCourseByName(QString name);

    bool updateCourse(int id, QString name, QString description);
    int insertCourse(QString name, QString description);//returns id of the new course
    bool deleteCourse(int id);

    vector<Student> searchStudent();
    vector<Student> searchStudentById(int id);
    vector<Student> searchStudentByName(QString name);
    vector<Student> searchStudentByType(QString type);

    bool updateStudent(int id, QString name, QString type, int enrollmentYear);
    int insertStudent(int id, QString name, QString type, int enrollmentYear);
    bool deleteStudent(int id);

    vector<Grade> searchGrade();
    vector<Grade> searchGradeById(int id);
    vector<Grade> searchGradeByCourseId(int courseId);
    vector<Grade> searchGradeByStudentId(int studentId);
    vector<Grade> searchGradeByTakeTime(QString takeTime);
    vector<Grade> searchGradeByScore(int min, int max);

    bool updateGrade(int id, QString takeTime, int score);
    int insertGrade(int studentId, int courseId, QString takeTime, int score);
    bool deleteGrade(int id);

}




#endif // DB_H
