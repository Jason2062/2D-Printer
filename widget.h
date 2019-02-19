#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class QSpinBox;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event) ;


private:
    void configureSpinBox(QSpinBox *spinBox, int min, int max) const;
    void onMouseEvent(const QString &eventName, const QPoint &pos);
    Ui::Widget *ui;
};

#endif // WIDGET_H
