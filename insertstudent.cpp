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
