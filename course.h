#ifndef COURSE_H
#define COURSE_H
#include <QString>

class Course
{
public:
    Course(int id, QString name, QString description);
    int getId(){
        return id;
    }
    QString getName(){
        return name;
    }
    void setName(QString name);
    QString getDescription(){
        return description;
    }
    void setDescription(QString description);
    bool save();
private:
    int id;
    QString name;
    QString description;
};

#endif // COURSE_H
