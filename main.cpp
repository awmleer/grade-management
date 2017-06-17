#include "mainwindow.h"
#include <QApplication>
#include "db.h"
#include "student.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <vector>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Db::connect();//init sqlite database
    Db::test();
    w.setWindowTitle("query result");
    w.show();

    std::vector<Student> res;
    res.push_back({1,"zhao","graduate",2016});
    res.push_back({2,"zhao","graduate",2016});

    QTableWidget * tableWidget = new QTableWidget(res.size(),4,&w);
    tableWidget->setWindowTitle("Student result display");
    tableWidget->resize(350,200);
    QStringList header;
    header << "id" << "name" << "type" << "enrollmentYear";
    tableWidget->setHorizontalHeaderLabels(header);
    for (int i = 0;i < res.size();i++) {
        tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(res[i].id,10)));
        tableWidget->setItem(i,1,new QTableWidgetItem(res[i].name));
        tableWidget->setItem(i,2,new QTableWidgetItem(res[i].type));
        tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(res[i].enrollmentYear,10)));
    }


       tableWidget->show();

    return a.exec();
}
