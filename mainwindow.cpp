#include <QToolBar>
#include <QMenu>
#include <QMenuBar>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDialog>
#include "insertcourse.h"
#include "ui_insertcourse.h"
#include "selectcourse.h"
#include "ui_selectcourse.h"
#include "selectstudent.h"
#include "ui_selectstudent.h"
#include "insertstudent.h"
#include "ui_insertstudent.h"
#include "selectgrade.h"
#include "ui_selectgrade.h"
#include "insertgrade.h"
#include "ui_insertgrade.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    //btn = new QPushButton("成绩查询",this);
    //btn->setGeometry(220,20,70,36);
    //QObject::connect(btn,SIGNAL(clicked()),this,SLOT(showText()));

    ui->setupUi(this);

    this->setWindowTitle("Student Grades Management");


    QMenuBar *mBar = menuBar();

    QMenu *pCourse = mBar->addMenu("课程管理");
    QAction * pCfind = pCourse->addAction("课程查找");
    QAction * pCinsert = pCourse->addAction("课程添加");


    QMenu *pStudent = mBar->addMenu("学生管理");
    QAction * pSfind = pStudent->addAction("学生查找");
    //pSfind->   setWindowTitle("学生查找");
    QAction * pSinsert = pStudent->addAction("学生添加");

    QMenu *pGrade = mBar->addMenu("成绩管理");
    QAction * pGfind = pGrade->addAction("成绩查找");
    QAction * pGinsert = pGrade->addAction("成绩添加");

    QToolBar *toolBar = addToolBar("toolbar");//创建工具栏

    connect(pCfind, SIGNAL(triggered()),this, SLOT(findCourseSlot()));
    connect(pCinsert, SIGNAL(triggered()),this, SLOT(insertCourseSlot()));
    connect(pSfind, SIGNAL(triggered()),this, SLOT(findStudentSlot()));
    connect(pSinsert, SIGNAL(triggered()),this, SLOT(insertStudentSlot()));
    connect(pGfind, SIGNAL(triggered()),this, SLOT(findGradeSlot()));
    connect(pGinsert, SIGNAL(triggered()),this, SLOT(insertGradeSlot()));


    toolBar->setAllowedAreas(Qt::LeftToolBarArea);

    toolBar->addAction(pCfind);//工具栏添加菜单项--快捷键
    toolBar->addAction(pCinsert);
    toolBar->addAction(pSfind);
    toolBar->addAction(pSinsert);
    toolBar->addAction(pGfind);
    toolBar->addAction(pGinsert);


   // setWindowFlags(Qt::FramelessWindowHint);
    //m_pTitleBar = new TitleBar(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    insertgrade ig;
    if(ig.exec()==QDialog::Accepted)
    {
        //w.show();
        return ;//a.exec();
    }

}

void MainWindow::findCourseSlot()
{
   selectcourse a;
   a.show();
   a.exec();
   return;
}

void MainWindow::insertCourseSlot()
{
    insertcourse a;
    a.show();
    a.exec();
    return;
}

void MainWindow::findStudentSlot()
{
   selectstudent a;
   a.setWindowTitle("学生查找");
   a.show();
   a.exec();
   return;
}

void MainWindow::insertStudentSlot()
{
    insertStudent a;
    a.setWindowTitle("学生添加");
    a.show();
    a.exec();
    return;
}

void MainWindow::findGradeSlot()
{
    selectgrade a;
    a.setWindowTitle("成绩查找");
    a.show();
    a.exec();
    return;
}

void MainWindow::insertGradeSlot()
{
    insertgrade a;
    a.setWindowTitle("成绩添加");
    a.show();
    a.exec();
    return;

}
