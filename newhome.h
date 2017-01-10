#ifndef NEWHOME_H
#define NEWHOME_H
#include <widget.h>

#include <QWidget>

namespace Ui {
class newhome;
}

class newhome : public QWidget
{
    Q_OBJECT

public:
    explicit newhome(QWidget *parent = 0);
    ~newhome();

private slots:
 //   void on_ViewStaff_clicked();

private:
    Ui::newhome *ui;
    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // NEWHOME_H
