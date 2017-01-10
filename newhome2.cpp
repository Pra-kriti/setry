#include "newhome2.h"
#include "ui_newhome2.h"

newhome2::newhome2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newhome2)
{
    ui->setupUi(this);
    this->showMaximized();
}

newhome2::~newhome2()
{
    delete ui;
}
