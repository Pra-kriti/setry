
#include "newhome.h"
#include "ui_newhome.h"

newhome::newhome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newhome)
{
    ui->setupUi(this);
    this->showMaximized();
}

newhome::~newhome()
{
    delete ui;
}
