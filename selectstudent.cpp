#include "selectstudent.h"
#include "ui_selectstudent.h"

selectstudent::selectstudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectstudent)
{
    ui->setupUi(this);
}

selectstudent::~selectstudent()
{
    delete ui;
}

void selectstudent::on_pushButton_clicked()
{
    this->hide();
    return;
}
