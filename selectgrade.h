#ifndef SELECTGRADE_H
#define SELECTGRADE_H

#include <QDialog>
#include <vector>
#include "grade.h"

namespace Ui {
class selectgrade;
}

class selectgrade : public QDialog
{
    Q_OBJECT

public:
    explicit selectgrade(QWidget *parent = 0);
    ~selectgrade();

private slots:
    void on_pushButton_clicked();

    void on_searchAllbutton_clicked();

    void on_searchButton_clicked();

    void on_removeButton_clicked();

    void on_saveButton_clicked();


private:
    Ui::selectgrade *ui;
    vector<Grade> selGradeRes;
};

#endif // SELECTGRADE_H
