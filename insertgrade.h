#ifndef INSERTGRADE_H
#define INSERTGRADE_H

#include <QDialog>

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
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::insertgrade *ui;
};

#endif // INSERTGRADE_H
