#include <QMessageBox>
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

void selectstudent::on_pushButton_2_clicked()
{

    if (!ui->studentId->text().isEmpty()) {

        QString idStr =  ui->studentId->text();
        int id =idStr.toInt();
        selStudentRes = Student::searchById(id);

    }
    else if (!ui->studentName->text().isEmpty()) {
        selStudentRes = Student::searchByName(ui->studentName->text());
    }
    else if (!ui->studentType->text().isEmpty()) {
        selStudentRes = Student::searchByType(ui->studentType->text());
    }
    else {
        QMessageBox::warning(this,tr("Input illegal!"),tr("Please complete the course id or course name"));
        return;
    }

    ui->tableWidget->setRowCount(selStudentRes.size());
    ui->tableWidget->setColumnCount(4);


    QStringList header;
    header << "id" << "name" << "type" << "enrollment year";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    for (unsigned i = 0;i < selStudentRes.size();i++) {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(selStudentRes[i].getId(),10)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(selStudentRes[i].getName()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(selStudentRes[i].getType()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(selStudentRes[i].getEnrollmentYear()));

    }

    ui->tableWidget->show();
}

void selectstudent::on_pushButton_3_clicked()
{
    selStudentRes = Student::all();

    ui->tableWidget->setRowCount(selStudentRes.size());
    ui->tableWidget->setColumnCount(4);


    QStringList header;
    header << "id" << "name" << "type" << "enrollment year";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    for (unsigned i = 0;i < selStudentRes.size();i++) {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(selStudentRes[i].getId(),10)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(selStudentRes[i].getName()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(selStudentRes[i].getType()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(selStudentRes[i].getEnrollmentYear(),10)));

    }

    ui->tableWidget->show();

}

void selectstudent::on_removeButtom_clicked()
{
    int i = ui->tableWidget->currentRow();
    vector<Student>::iterator i_student = selStudentRes.begin();
    for (int j = 0;j < i;j++)
        i_student++;
    ui->tableWidget->removeRow(i);
    selStudentRes[i].remove();
    selStudentRes.erase(i_student);

    return;
}

void selectstudent::on_saveButton_clicked()
{
    int i = ui->tableWidget->currentRow();

    selStudentRes[i].setName(ui->tableWidget->item(i,1)->text());
    selStudentRes[i].save();

    selStudentRes[i].setType(ui->tableWidget->item(i,2)->text());
    selStudentRes[i].save();

    QString year = ui->tableWidget->item(i,3)->text();
    selStudentRes[i].setEnrollmentYear(year.toInt());
    selStudentRes[i].save();

}
