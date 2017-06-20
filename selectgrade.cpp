#include "selectgrade.h"
#include "ui_selectgrade.h"

selectgrade::selectgrade(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectgrade)
{

    /*QTableWidget * tableWidget = new QTableWidget(res.size(),4,&w);
    tableWidget->setWindowTitle("Student result display");
    tableWidget->resize(900,300);
    QStringList header;
    header << "id" << "name" << "type" << "enrollmentYear";
    tableWidget->setHorizontalHeaderLabels(header);
    for (int i = 0;i < res.size();i++) {
        tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(res[i].getId(),10)));
        tableWidget->setItem(i,1,new QTableWidgetItem(res[i].name));
        tableWidget->setItem(i,2,new QTableWidgetItem(res[i].type));
        tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(res[i].enrollmentYear,10)));
    }


    tableWidget->show();*/
    ui->setupUi(this);
}

selectgrade::~selectgrade()
{
    delete ui;
}
