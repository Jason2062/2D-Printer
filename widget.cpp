#include "Widget.h"
#include "ui_widget.h"
#include <QMouseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->estadoLineEdit->setReadOnly(true);
    ui->xPosSpinBox->setReadOnly(true);
    ui->yPosSpinBox->setReadOnly(true);
    ui->xPosSpinBox->setValue(cursor().pos().x());
    ui->yPosSpinBox->setValue(cursor().pos().y());
    configureSpinBox(ui->xPosSpinBox, -INT_MAX, +INT_MAX);
    configureSpinBox(ui->yPosSpinBox, -INT_MAX, +INT_MAX);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    onMouseEvent("DoubleClick", event->pos());
    QWidget::mouseDoubleClickEvent(event);
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    onMouseEvent("Move", event->pos());
    QWidget::mouseMoveEvent(event);
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    onMouseEvent("Press", event->pos());
    QWidget::mousePressEvent(event);
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    onMouseEvent("Release", event->pos());
    QWidget::mouseReleaseEvent(event);
}

void Widget::configureSpinBox(QSpinBox *spinBox, int min, int max) const
{
    spinBox->setMinimum(min);
    spinBox->setMaximum(max);
}

void Widget::onMouseEvent(const QString &eventName, const QPoint &pos)
{
    ui->estadoLineEdit->setText(eventName);
    ui->xPosSpinBox->setValue(pos.x());
    ui->yPosSpinBox->setValue(pos.y());
}
