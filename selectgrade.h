#ifndef SELECTGRADE_H
#define SELECTGRADE_H

#include <QDialog>

namespace Ui {
class selectgrade;
}

class selectgrade : public QDialog
{
    Q_OBJECT

public:
    explicit selectgrade(QWidget *parent = 0);
    ~selectgrade();

private:
    Ui::selectgrade *ui;
};

#endif // SELECTGRADE_H
