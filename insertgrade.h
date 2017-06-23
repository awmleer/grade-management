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

private:
    Ui::insertgrade *ui;

};

#endif // INSERTGRADE_H
