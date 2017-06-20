#include "insertstudent.h"
#include "ui_insertstudent.h"

insertStudent::insertStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::insertStudent)
{
    ui->setupUi(this);
}

insertStudent::~insertStudent()
{
    delete ui;
}

void insertStudent::on_pushButton_clicked()
{
    //do the actual insertion here
    this->hide();
    return;
}

void insertStudent::on_pushButton_2_clicked()
{
    this->hide();
    return;
}
