#include <QMessageBox>
#include <QString>
#include "insertcourse.h"
#include "ui_insertcourse.h"
#include "db.h"


insertcourse::insertcourse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::insertcourse)
{
    ui->setupUi(this);
    this->setWindowTitle("Course management");

}

insertcourse::~insertcourse()
{
    delete ui;
}

void insertcourse::on_buttonBox_accepted()
{

}

void insertcourse::on_pushButton_clicked()
{
    if (ui->CourseName->text().isEmpty()||ui->Description->text().isEmpty()) {
        //QMessageBox::warning(this,tr("添加失败"),tr("请将课程名称和课程编号填写完整"));
        QMessageBox::warning(this,tr("Insertion failed!"),tr("Please complete the course name and description!"));
        return;
    }

    m_name = ui->CourseName->text();
    m_description = ui->Description->text();
    int id = Course::create(m_name,m_description);
    QMessageBox::warning(this,tr("Insertion successed!"),tr(qPrintable("The course id of "+m_name+" is "+QString::number(id,10))));
    return;
}

void insertcourse::on_pushButton_2_clicked()
{
     vector<Course> selCourseRes;

    if (!ui->delCourseId->text().isEmpty()) {

        QString idStr =  ui->delCourseId->text();
        int id =idStr.toInt();
        selCourseRes = Course::searchById(id);

        if (selCourseRes.size()) {
            if (selCourseRes[0].remove())
                 QMessageBox::warning(this,tr("Removal succeed"),tr("Please input the course id"));
        }
        else
            QMessageBox::warning(this,tr("Removal failed"),tr("Please make sure the course exists."));

    }
    else {
         QMessageBox::warning(this,tr("Removal failed"),tr("Please input the course id"));
    }


    return;
}
