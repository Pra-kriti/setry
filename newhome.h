#ifndef NEWHOME_H
#define NEWHOME_H

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

private:
    Ui::newhome *ui;
};

#endif // NEWHOME_H
