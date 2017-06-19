#include "selectgrade.h"
#include "ui_selectgrade.h"

selectgrade::selectgrade(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectgrade)
{
    ui->setupUi(this);
}

selectgrade::~selectgrade()
{
    delete ui;
}
