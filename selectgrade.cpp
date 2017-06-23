#include <QMessageBox>
#include "selectgrade.h"
#include "ui_selectgrade.h"

selectgrade::selectgrade(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectgrade)
{
    ui->setupUi(this);
    QMessageBox::warning(this,tr("Hint"),tr("You should only input one search condition."));
}

selectgrade::~selectgrade()
{
    delete ui;
}

void selectgrade::on_pushButton_clicked()
{
    this->hide();
    return;
}

void selectgrade::on_searchButton_clicked()
{

    if (!ui->Id->text().isEmpty()) {

        QString idStr =  ui->Id->text();
        int id =idStr.toInt();
        selGradeRes = Grade::searchById(id);

    }
    else if (!ui->studentId->text().isEmpty()) {
        QString idStr =  ui->studentId->text();
        int id =idStr.toInt();
        selGradeRes = Grade::searchByStudentId(id);
    }
    else if (!ui->courseId->text().isEmpty()) {
        QString idStr =  ui->courseId->text();
        int id =idStr.toInt();
        selGradeRes = Grade::searchByCourseId(id);
    }
    else if (!ui->takeTime->text().isEmpty()) {
        QString time1 =  ui->takeTime->text();
        selGradeRes = Grade::searchByTakeTime(time1);
    }
    else if (!ui->minScore->text().isEmpty()&&!ui->maxScore->text().isEmpty()) {
        QString scoreStr =  ui->minScore->text();
        int score1 =scoreStr.toInt();
        scoreStr =  ui->maxScore->text();
        int score2 =scoreStr.toInt();
        selGradeRes = Grade::searchByScore(score1,score2);
    }
    else {
        QMessageBox::warning(this,tr("Input illegal!"),tr("Please complete the search condition"));
        return;
    }

    ui->tableWidget->setRowCount(selGradeRes.size());
    ui->tableWidget->setColumnCount(5);

    QStringList header;
    header << "id" << "student id" << "course id " << "take time" << "score";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    for (unsigned i = 0;i < selGradeRes.size();i++) {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(selGradeRes[i].getId(),10)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(selGradeRes[i].getStudentId(),10)));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(selGradeRes[i].getCourseId(),10)));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(selGradeRes[i].getTakeTime()));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(selGradeRes[i].getScore(),10)));

    }

    ui->tableWidget->show();
}

void selectgrade::on_searchAllbutton_clicked()
{
    selGradeRes = Grade::all();

    ui->tableWidget->setRowCount(selGradeRes.size());
    ui->tableWidget->setColumnCount(5);




    QStringList header;
    header << "id" << "student id" << "course id " << "take time" << "score";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    for (unsigned i = 0;i < selGradeRes.size();i++) {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(selGradeRes[i].getId(),10)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(selGradeRes[i].getStudentId(),10)));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(selGradeRes[i].getCourseId(),10)));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(selGradeRes[i].getTakeTime()));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(selGradeRes[i].getScore(),10)));

    }

    ui->tableWidget->show();

}



void selectgrade::on_removeButton_clicked()
{
    int i = ui->tableWidget->currentRow();
    vector<Grade>::iterator i_grade = selGradeRes.begin();
    for (int j = 0;j < i;j++)
        i_grade++;
    ui->tableWidget->removeRow(i);
    selGradeRes[i].remove();
    selGradeRes.erase(i_grade);

    return;
}

void selectgrade::on_saveButton_clicked()
{
    int i = ui->tableWidget->currentRow();

    QString tempStr;

    selGradeRes[i].setTakeTime(ui->tableWidget->item(i,3)->text());
    selGradeRes[i].save();

    selGradeRes[i].setScore((tempStr = ui->tableWidget->item(i,4)->text()).toInt());
    selGradeRes[i].save();


    return;

}

