#ifndef INSERTSTUDENT_H
#define INSERTSTUDENT_H

#include <QDialog>

namespace Ui {
class insertStudent;
}

class insertStudent : public QDialog
{
    Q_OBJECT

public:
    explicit insertStudent(QWidget *parent = 0);
    ~insertStudent();

private:
    Ui::insertStudent *ui;
};

#endif // INSERTSTUDENT_H
