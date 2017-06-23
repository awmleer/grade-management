#ifndef SELECTSTUDENT_H
#define SELECTSTUDENT_H

#include <QDialog>
#include <vector>
#include "student.h"

namespace Ui {
class selectstudent;
}

class selectstudent : public QDialog
{
    Q_OBJECT

public:
    explicit selectstudent(QWidget *parent = 0);
    ~selectstudent();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::selectstudent *ui;
    vector<Student> selStudentRes;
};

#endif // SELECTSTUDENT_H
