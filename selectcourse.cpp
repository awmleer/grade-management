#include <QMessageBox>
#include "selectcourse.h"
#include "ui_selectcourse.h"

selectcourse::selectcourse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectcourse)
{
    ui->setupUi(this);
}

selectcourse::~selectcourse()
{
    delete ui;
}

void selectcourse::on_buttonBox_accepted()
{
    if (ui->CourseId->text().isEmpty()&&ui->CourseName->text().isEmpty()) {
        //QMessageBox::warning(this,tr("添加失败"),tr("请将课程名称和课程编号填写完整"));
        QMessageBox::warning(this,tr("Input inlegal!"),tr("Please complete the course id or course name"));
        return;
    }

//    m_name = ui->CourseName->text();
//    m_description = ui->Description->text();
//    int id = Db::insertCourse(m_name,m_description);
//    QMessageBox::warning(this,tr("Insertion successed!"),tr(qPrintable("The course id of "+m_name+" is "+QString::number(id,10))));
//    return;
}
