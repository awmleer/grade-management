#ifndef COURSE_H
#define COURSE_H
#include <QString>

class Course{
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
    static int create(QString name, QString description);//returns the courseId if success, else returns -1
    bool remove();

private:
    int id;
    QString name;
    QString description;
};

#endif // COURSE_H
