#ifndef COURSE_H
#define COURSE_H
#include <QString>
#include <vector>

using namespace std;

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
    bool remove();
    static int create(QString name, QString description);//returns the courseId if success, else returns -1
    static vector<Course> all();
    static vector<Course> searchById(int id);
    static vector<Course> searchByName(QString name);

private:
    int id;
    QString name;
    QString description;
};

#endif // COURSE_H
