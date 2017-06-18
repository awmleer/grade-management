#ifndef SELECTSTUDENT_H
#define SELECTSTUDENT_H

#include <QDialog>

namespace Ui {
class selectstudent;
}

class selectstudent : public QDialog
{
    Q_OBJECT

public:
    explicit selectstudent(QWidget *parent = 0);
    ~selectstudent();

private:
    Ui::selectstudent *ui;
};

#endif // SELECTSTUDENT_H
