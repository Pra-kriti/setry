#include <QSqlQueryModel>
#include "newhome.h"
#include "ui_newhome.h"
#define deflabel "HOVER OVER THE BUTTONS \n FOR MORE INFORMATION "
newhome::newhome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newhome)
{
    ui->setupUi(this);
    this->showMaximized();
    ui->SearchBar->hide();
    ui->SearchBar1->hide();
    ui->SearchLabel->hide();
    ui->tableView->hide();
    ui->SearchButton->hide();
    ui->InfoLabel->setMaximumHeight(16777215);
    ui->InfoLabel->setMaximumWidth(16777215);

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

void newhome::on_ViewStaff_clicked()
{
   ui->ViewSuper->hide();
   ui->GTS->hide();
   ui->VS->hide();
   update1();
}
void newhome::update1()
{
    selector=1;
    ui->tableView->show();
    ui->InfoLabel->hide();
    ui->SearchBar->show();
    ui->SearchBar1->show();
    ui->SearchLabel->show();
    ui->SearchButton->show();
    ui->tableView->setMaximumWidth(16777215);
    ui->tableView->setMaximumHeight(16777215);
    ui->tableView->setStyleSheet("background-color:rgb(231, 231, 231)");
    Widget conn;
    QSqlQueryModel * modal=new QSqlQueryModel();
            conn.connOpen();
            QSqlQuery *qry=new QSqlQuery(conn.myDB);
    qry->prepare("SELECT* FROM staff");
    qry->exec();
    qDebug()<<(qry->size());
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    conn.connClose();
    qDebug()<<(modal->rowCount());

}

void newhome::on_SearchButton_clicked()
{
    Widget conn;
    QSqlQueryModel * modal=new QSqlQueryModel();
            conn.connOpen();
            QSqlQuery *qry=new QSqlQuery(conn.myDB);
    if (selector==1)
    {
        QString Firstname= ui->SearchBar->text();
        QString Lastname= ui->SearchBar1->text();


        qry->prepare("SELECT* FROM staff WHERE LOWER(firstname)=LOWER(\'"+Firstname+"\') OR LOWER(lastname)=LOWER(\'"+Lastname+"\')");
          qry->exec();
          modal->setQuery(*qry);
    }
    else if (selector==3)
    {
        QString Items_name= ui->SearchBar->text();
        QString Location_name= ui->SearchBar1->text();


        qry->prepare("SELECT* FROM [table] WHERE LOWER(ITEMSNAME_1) LIKE LOWER(\'\%"+Items_name+"\%\') OR LOWER(LOCATION_NAME) LIKE LOWER(\'\%"+Location_name+"\%\') ");
   qry->exec();
   qDebug()<<(qry->size());
   modal->setQuery(*qry);
    }
    else{}

    qDebug()<<(qry->size());
    if(modal->rowCount()==0)
    {
        QMessageBox::warning(this, "!!ALERT!! ","No such record found in the staff directory!!");
    }
    ui->tableView->setModel(modal);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    conn.connClose();
    qDebug()<<(modal->rowCount());


}

void newhome::on_BackButton_clicked()
{
    newhome *admin=new newhome;
    admin->showMaximized();
    this->close();
}

void newhome::on_GTS_clicked()
{
    ui->ViewSuper->hide();
    ui->ViewStaff->hide();
    ui->VS->hide();
    update2();
}
void newhome::update2()
{
    selector=3;
    ui->tableView->show();
    ui->InfoLabel->hide();
    ui->SearchBar->show();
    ui->SearchBar1->show();
    ui->SearchLabel->show();
    ui->SearchButton->show();
    ui->tableView->setMaximumWidth(16777215);
    ui->tableView->setMaximumHeight(16777215);
    ui->tableView->setStyleSheet("background-color:rgb(231, 231, 231)");
    Widget conn;
    QSqlQueryModel * modal=new QSqlQueryModel();
            conn.connOpen();
            QSqlQuery *qry=new QSqlQuery(conn.myDB);
    qry->prepare("SELECT* FROM [table]");
    qry->exec();
    qDebug()<<(qry->size());
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    conn.connClose();
    qDebug()<<(modal->rowCount());
}
