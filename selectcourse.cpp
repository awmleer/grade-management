#include <QMessageBox>
#include <vector>
#include <QTableWidget>
#include "db.h"
#include "selectcourse.h"
#include "ui_selectcourse.h"

selectcourse::selectcourse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectcourse)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Course selection"));
}

selectcourse::~selectcourse()
{
    delete ui;
}

void selectcourse::on_buttonBox_accepted()
{

}

void selectcourse::on_pushButton_clicked()
{
    vector<Course> selCourseRes;
    if (!ui->CourseId->text().isEmpty()) {

        QString idStr =  ui->CourseId->text();
        int id =idStr.toInt();
        selCourseRes = Course::searchById(id);

    }

    else if (!ui->CourseName->text().isEmpty()) {
        selCourseRes = Course::searchByName(ui->CourseName->text());
    }
    else {
        QMessageBox::warning(this,tr("Input illegal!"),tr("Please complete the course id or course name"));
        return;
    }

    ui->tableWidget->setRowCount(selCourseRes.size());
    ui->tableWidget->setColumnCount(3);


    QStringList header;
    header << "id" << "name" << "description";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    for (unsigned i = 0;i < selCourseRes.size();i++) {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(selCourseRes[i].getId(),10)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(selCourseRes[i].getName()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(selCourseRes[i].getDescription()));


    }

    ui->tableWidget->show();

}
