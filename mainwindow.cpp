#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "insertgrade.h"
#include<QDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    //btn = new QPushButton("成绩查询",this);
    //btn->setGeometry(220,20,70,36);
    //QObject::connect(btn,SIGNAL(clicked()),this,SLOT(showText()));

    ui->setupUi(this);
    //ui->pushButton->setText("新窗口"); //将界面上按钮的显示文本更改为“新窗口”
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showText(){
    //(tableWidget->show());
    //ui->pushButton_2
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
