#include <QMessageBox>
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
    if (ui->studentId->text().isEmpty()||ui->studentName->text().isEmpty()||ui->studentType->currentText() == -1||ui->studentEnrollmentYear->text().isEmpty()) {
        //QMessageBox::warning(this,tr("添加失败"),tr("请将课程名称和课程编号填写完整"));
        QMessageBox::warning(this,tr("Insertion failed!"),tr("Please complete the student information!"));
        return;
    }
    QString typeArray[] = {"master","graduate","doctor"};

    QString idStr =  ui->studentId->text();
    int id =idStr.toInt();
    QString name = ui->studentName->text();
    QString type = typeArray[ui->studentType->currentIndex()+1];
    QString yearStr = ui->studentEnrollmentYear->text();
    int year = yearStr.toInt();

    if (Student::create(id,name,type,year) > 0)
         QMessageBox::warning(this,tr("Insertion succeed!"),tr("The student has been added"));
    else
         QMessageBox::warning(this,tr("Insertion failed!"),tr("Make sure the student doesn't exist."));


    this->hide();
    return;
}

void insertStudent::on_pushButton_2_clicked()
{
    this->hide();
    return;
}
