#ifndef INSERTGRADE_H
#define INSERTGRADE_H

#include <QDialog>
#include "grade.h"

namespace Ui {
class insertgrade;
}

class insertgrade : public QDialog
{
    Q_OBJECT

public:
    explicit insertgrade(QWidget *parent = 0);
    ~insertgrade();

private slots:
    void on_insertGrade_clicked();

private:
    Ui::insertgrade *ui;

};

#endif // INSERTGRADE_H
