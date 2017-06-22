#include <QToolBar>
#include <QMenu>
#include <QMenuBar>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "insertgrade.h"
#include<QDialog>
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


    QMenuBar *mBar = menuBar();

    QMenu *pStudent = mBar->addMenu("学生管理");

    QAction * pSfind = pStudent->addAction("学生查找");
    //pSfind->   setWindowTitle("学生查找");
    QAction * pSinsert = pStudent->addAction("学生添加");

    QMenu *pGrade = mBar->addMenu("成绩管理");

    QAction * pGfind = pGrade->addAction("成绩查找");
    QAction * pGinsert = pGrade->addAction("成绩添加");

    QToolBar *toolBar = addToolBar("toolbar");//创建工具栏
    connect(pSfind, SIGNAL(triggered()),this, SLOT(findStudentSlot()));
    connect(pSinsert, SIGNAL(triggered()),this, SLOT(insertStudentSlot()));
    connect(pGfind, SIGNAL(triggered()),this, SLOT(findGradeSlot()));
    connect(pGinsert, SIGNAL(triggered()),this, SLOT(insertGradeSlot()));


    toolBar->setAllowedAreas(Qt::LeftToolBarArea);

    toolBar->addAction(pSfind);//工具栏添加菜单项--快捷键
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
