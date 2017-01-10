<<<<<<< HEAD
#include "newhome1.h"
#include "ui_newhome1.h"

newhome1::newhome1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newhome1)
{
    ui->setupUi(this);
    this->showMaximized();
}

newhome1::~newhome1()
{
    delete ui;
}
=======
#include "newhome1.h"
#include "ui_newhome1.h"

newhome1::newhome1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newhome1)
{
    ui->setupUi(this);
    this->showMaximized();
}

newhome1::~newhome1()
{
    delete ui;
}
>>>>>>> origin/master
