#include "mainwindow.h"
#include <QApplication>
#include "db.h"
#include "student.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    bool dbInitResult=Db::init();//init sqlite database
    if (dbInitResult==false){
        qDebug() << "db init failed";
    }else{
        qDebug() << "db init success";
    }
    Db::testInsert();
    w.setWindowTitle("query result");
    w.show();

    vector<Student> res = Db::test();

//    Student student(1,"zhao","graduate",2016);
//    res.push_back(student);
//    res.push_back(student);

    QTableWidget * tableWidget = new QTableWidget(res.size(),4,&w);
    tableWidget->setWindowTitle("Student result display");
    tableWidget->resize(900,300);
    QStringList header;
    header << "id" << "name" << "type" << "enrollmentYear";
    tableWidget->setHorizontalHeaderLabels(header);
    for (int i = 0;i < res.size();i++) {
        tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(res[i].getId(),10)));
        tableWidget->setItem(i,1,new QTableWidgetItem(res[i].name));
        tableWidget->setItem(i,2,new QTableWidgetItem(res[i].type));
        tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(res[i].enrollmentYear,10)));
    }


    tableWidget->show();

    return a.exec();
}
