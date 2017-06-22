#ifndef INSERTCOURSE_H
#define INSERTCOURSE_H

#include <QDialog>

namespace Ui {
class insertcourse;
}

class insertcourse : public QDialog
{
    Q_OBJECT

public:
    explicit insertcourse(QWidget *parent = 0);
    ~insertcourse();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::insertcourse *ui;

    QString m_name;
    QString m_description;
};

#endif // INSERTCOURSE_H
