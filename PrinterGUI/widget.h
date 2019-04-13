#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "xaxisr.h"
#include "xaxisl.h"
#include "yaxisr.h"
#include "yaxisl.h"

namespace Ui {
class Widget;
}

class QSpinBox;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

protected slots:
    void on_pushButton_clicked();

private:
    void configureSpinBox(QSpinBox *spinBox, int min, int max) const;
    void onMouseEvent(const QString &eventName, const QPoint &pos);


    Ui::Widget *ui;
    //Motor rotate state threads
    xAxisR *xThreadr;
    xAxisL *xThreadl;
    yAxisR *yThreadr;
    yAxisL *yThreadl;
    //painter variables
    QImage m_image;
    QPoint m_prevPoint;
    QPoint m_curPoint;
};

#endif // WIDGET_H
