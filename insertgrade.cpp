#include <QMessageBox>
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

void insertgrade::on_insertGrade_clicked()
{
    //do the actual insertion here
    if (ui->studentId->text().isEmpty()||ui->courseId->text().isEmpty()||ui->takeTime->text().isEmpty()||ui->score->text().isEmpty()) {

        QMessageBox::warning(this,tr("Insertion failed!"),tr("Please complete the grade information!"));
        return;
    }

    QString idStr =  ui->studentId->text();
    int sId =idStr.toInt();
    idStr =  ui->courseId->text();
    int cId =idStr.toInt();
    QString timeStr = ui->takeTime->text();
    QString scoreStr = ui->score->text();
    int score = scoreStr.toInt();

    if (Grade::create(sId,cId,timeStr,score))
         QMessageBox::warning(this,tr("Insertion succeed!"),tr("The grade information has been added"));
    else
         QMessageBox::warning(this,tr("Insertion failed!"),tr("Make sure the grade doesn't exist."));


    this->hide();
    return;
}
