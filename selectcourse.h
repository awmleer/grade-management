#ifndef SELECTCOURSE_H
#define SELECTCOURSE_H

#include <QDialog>
#include <vector>
#include "course.h"

namespace Ui {
class selectcourse;
}

class selectcourse : public QDialog
{
    Q_OBJECT

public:
    explicit selectcourse(QWidget *parent = 0);
    ~selectcourse();

private slots:
    void on_buttonBox_accepted();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::selectcourse *ui;
    vector<Course> selCourseRes;
};

#endif // SELECTCOURSE_H
