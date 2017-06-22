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


}

insertcourse::~insertcourse()
{
    delete ui;
}

void insertcourse::on_buttonBox_accepted()
{
    if (ui->CourseName->text().isEmpty()||ui->Description->text().isEmpty()) {
        //QMessageBox::warning(this,tr("添加失败"),tr("请将课程名称和课程编号填写完整"));
        QMessageBox::warning(this,tr("Insertion failed!"),tr("Please complete the course name and description!"));
        return;
    }

    m_name = ui->CourseName->text();
    m_description = ui->Description->text();
    int id = Db::insertCourse(m_name,m_description);
    QMessageBox::warning(this,tr("Insertion successed!"),tr(qPrintable("The course id of "+m_name+" is "+QString::number(id,10))));
    return;
}
