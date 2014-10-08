#ifndef CONTROLWIDGET_HPP
#define CONTROLWIDGET_HPP

#include <QWidget>
#include <QKeyEvent>
#include <QDebug>

namespace Ui {
    class ControlWidget;
}

class ControlWidget : public QWidget
{
    Q_OBJECT
public:
    ControlWidget(QWidget *parent = NULL);
    ~ControlWidget();

    void closeEvent(QCloseEvent *event);

signals:
//    void closing();
    void speedChanged(int speed);
    void rotaionChanged(int x, int y, int z);


private:
    Ui::ControlWidget *ui;

};

#endif  // CONTROLWIDGET_HPP
