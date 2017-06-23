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
    if (ui->CourseId->text().isEmpty()) {
        //QMessageBox::warning(this,tr("添加失败"),tr("请将课程名称和课程编号填写完整"));
        QMessageBox::warning(this,tr("Input inlegal!"),tr("Please complete the course id or course name"));
        return;
    }

    QString idStr =  ui->CourseId->text();
    int id =idStr.toInt();
    vector<Course> selCourseRes = Db::searchCourseById(id);

    QTableWidget * tableWidget = new QTableWidget(selCourseRes.size(),4);
    //tableWidget->setWindowTitle("Student result display");
    //w.setCentralWidget(tableWidget);

    tableWidget->resize(900,300);

    QStringList header;
    header << "id" << "name" << "description";
    tableWidget->setHorizontalHeaderLabels(header);
    for (unsigned i = 0;i < selCourseRes.size();i++) {
        tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(selCourseRes[i].getId(),10)));
        tableWidget->setItem(i,1,new QTableWidgetItem(selCourseRes[i].getName()));
        tableWidget->setItem(i,2,new QTableWidgetItem(selCourseRes[i].getDescription()));

    }

    tableWidget->show();


//    m_name = ui->CourseName->text();
//    m_description = ui->Description->text();
//    int id = Db::insertCourse(m_name,m_description);
//    QMessageBox::warning(this,tr("Insertion successed!"),tr(qPrintable("The course id of "+m_name+" is "+QString::number(id,10))));
//    return;
}
