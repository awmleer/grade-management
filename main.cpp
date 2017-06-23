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
    Db::searchCourseById(2);
    Db::searchCourseByName("p");
    vector<Course> myCourses = Db::searchCourse();
//    Course::create("oop","first try!");
    if (myCourses.size()>0){
//        myCourses[0].remove();
//        qDebug()<<myCourses.size();
//        myCourses[0].setName("xxx");
//        qDebug()<<myCourses[0].getName();
//        myCourses[0].save();
    }


    w.setWindowTitle("学生成绩管理系统");
    w.show();

    vector<Student> res = Db::test();


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
