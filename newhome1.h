
#ifndef NEWHOME1_H
#define NEWHOME1_H

#include <QWidget>

namespace Ui {
class newhome1;
}

class newhome1 : public QWidget
{
    Q_OBJECT

public:
    explicit newhome1(QWidget *parent = 0);
    ~newhome1();

private:
    Ui::newhome1 *ui;
};

#endif // NEWHOME1_H
