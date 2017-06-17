#include "dialog.h"
#include "ui_dialog.h"
#include <QPainter>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

void Dialog::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QPixmap pix;
    pix.load("../mypixmap/logo.jpg");
    painter.drawPixmap(0,0,80,100,pix);
}

Dialog::~Dialog()
{
    delete ui;
}
