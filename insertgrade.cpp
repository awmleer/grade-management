#include "insertgrade.h"
#include "ui_insertgrade.h"

insertgrade::insertgrade(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::insertgrade)
{
    ui->setupUi(this);
}

insertgrade::~insertgrade()
{
    delete ui;
}

void insertgrade::on_pushButton_2_clicked()
{
    this->hide();
    return;
}

void insertgrade::on_pushButton_clicked()
{
    this->hide();
    return;
}
