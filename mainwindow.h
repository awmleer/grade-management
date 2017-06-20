#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <vector>
#include <QPushButton>
#include <QApplication>
#include <QDebug>
#include <QTableWidgetItem>
#include"db.h"
#include "student.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//public slots:
   // void showText();

private slots:
    void on_pushButton_clicked();

private slots:
    void findStudentSlot();

    void insertStudentSlot();

    void findGradeSlot();

    void insertGradeSlot();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
