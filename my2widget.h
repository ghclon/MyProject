#ifndef MY2WIDGET_H
#define MY2WIDGET_H

#include <QWidget>

namespace Ui {
class My2Widget;
}

class My2Widget : public QWidget
{
    Q_OBJECT

public:
    explicit My2Widget(QWidget *parent = 0);
    ~My2Widget();

private:
    Ui::My2Widget *ui;
};

#endif // MY2WIDGET_H
