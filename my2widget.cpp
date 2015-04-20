#include "my2widget.h"
#include "ui_my2widget.h"

My2Widget::My2Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::My2Widget)
{
    ui->setupUi(this);
}

My2Widget::~My2Widget()
{
    delete ui;
}
