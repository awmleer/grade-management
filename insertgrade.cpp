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
