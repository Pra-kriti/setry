
#include "newhome.h"
#include "ui_newhome.h"
#define deflabel "HOVER OVER THE BUTTONS \n FOR MORE INFORMATION "
newhome::newhome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newhome)
{
    ui->setupUi(this);
    this->showMaximized();
    ui->InfoLabel->setText(deflabel);
    ui->ViewStaff->installEventFilter(this);
    ui->ViewSuper->installEventFilter(this);
    ui->GTS->installEventFilter(this);
    ui->VS->installEventFilter(this);
}

bool newhome::eventFilter(QObject *obj, QEvent *event)
{
    if(obj==ui->ViewStaff)
    {
        if(event->type()==QEvent::HoverEnter)
        {
            ui->InfoLabel->setText("View the detailed information of the staffs");
        }
        else if(event->type()==QEvent::HoverLeave)
        {
            ui->InfoLabel->setText(deflabel);
        }
    }
    else if(obj==ui->ViewSuper)
    {
        if(event->type()==QEvent::HoverEnter)
        {
            ui->InfoLabel->setText("View the detailed information of the supervisor \n and add the supervisor");
        }
        else if(event->type()==QEvent::HoverLeave)
        {
            ui->InfoLabel->setText(deflabel);
        }
    }

    else if(obj==ui->GTS)
    {
        if(event->type()==QEvent::HoverEnter)
        {
            ui->InfoLabel->setText("View the overall stock of medicines in the pharmacy");
        }
        else if(event->type()==QEvent::HoverLeave)
        {
            ui->InfoLabel->setText(deflabel);
        }
    }
    else if(obj==ui->VS)
    {
        if(event->type()==QEvent::HoverEnter)
        {
            ui->InfoLabel->setText("Show the monthly sales and transactions \n and calculate profit ");
        }
        else if(event->type()==QEvent::HoverLeave)
        {
            ui->InfoLabel->setText(deflabel);
        }

    }
    else
    {
        event->ignore();
    }
    return 0;

}

newhome::~newhome()
{
    delete ui;
}

//void newhome::on_ViewStaff_clicked()
//{

//}
