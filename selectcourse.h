#ifndef SELECTCOURSE_H
#define SELECTCOURSE_H

#include <QDialog>

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

private:
    Ui::selectcourse *ui;
};

#endif // SELECTCOURSE_H
