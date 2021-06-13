#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
//    this->setWindowOpacity(1);
    //    this->setAttribute(Qt::WA_TranslucentBackground);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event){
    if (event->key()==Qt::Key_Escape){
        this->close();
    }
}
