#include "mainwindow.h"
#include <QApplication>
#include<QLabel>
#include "db.h"
#include "insertgrade.h"
#include "student.h"
#include "course.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

//    QFont font = a.font();
//    font.setPointSize(11);
//    a.setFont(font);

    MainWindow w;

    bool dbInitResult=Db::init();//init sqlite database
    if (dbInitResult==false){
        qDebug() << "db init failed";
    }else{
        qDebug() << "db init success";
    }


    /*some tests*/
//    qDebug()<<Course::create("name","d");
//    vector<Grade> grades = Grade::all();
//    qDebug()<<grades[0].remove();
//    Grade::create(1003,1,"2016first",98);
//    vector<Grade> grades = Grade::searchByScore(40,70);
//    qDebug()<<grades[0].fetchStudent().getName();
//    Student::create(1003,"小王","master",2016);
//    Course::all();
//    Student::all();
//    Db::searchStudent();
//    Db::searchStudentById(1001);
//    Db::searchStudentByName("Bart");
//    Db::searchStudentByType("master");

//    Db::searchCourseById(2);
//    Db::searchCourseByName("p");
//    vector<Course> myCourses = Db::searchCourse();
//    Course::create("oop","first try!");
//    if (myCourses.size()>0){
//        myCourses[0].remove();
//        qDebug()<<myCourses.size();
//        myCourses[0].setName("xxx");
//        qDebug()<<myCourses[0].getName();
//        myCourses[0].save();
//    }


    w.setWindowTitle("学生成绩管理系统");
    w.show();


   // QLabel label(&w);
    //label.setGeometry(100,200,600,100);
    //label.setText("Welcome");
//    Student student(1,"zhao","graduate",2016);
//    res.push_back(student);
//    res.push_back(student);

/*    QTableWidget * tableWidget = new QTableWidget(res.size(),4,&w);
    tableWidget->setWindowTitle("Student result display");
    w.setCentralWidget(tableWidget);

    tableWidget->resize(900,300);

    QStringList header;
    header << "id" << "name" << "type" << "enrollmentYear";
    tableWidget->setHorizontalHeaderLabels(header);
    for (int i = 0;i < res.size();i++) {
        tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(res[i].getId(),10)));
        tableWidget->setItem(i,1,new QTableWidgetItem(res[i].name));
        tableWidget->setItem(i,2,new QTableWidgetItem(res[i].type));
        tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(res[i].enrollmentYear,10)));
    }*/


    //tableWidget->show();

    //QObject::connect((w.ui->pushButton_3),SIGNAL(clicked()),&tableWidget,SLOT(show()));

    return a.exec();
}
