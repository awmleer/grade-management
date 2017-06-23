#ifndef INSERTSTUDENT_H
#define INSERTSTUDENT_H

#include <QDialog>
#include "student.h"

namespace Ui {
class insertStudent;
}

class insertStudent : public QDialog
{
    Q_OBJECT

public:
    explicit insertStudent(QWidget *parent = 0);
    ~insertStudent();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::insertStudent *ui;
};

#endif // INSERTSTUDENT_H
