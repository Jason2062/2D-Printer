#include "Widget.h"
#include "ui_Widget.h"
#include <QMouseEvent>
#include <QDebug>

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
    configureSpinBox(ui->xPosSpinBox, 0, 400);
    configureSpinBox(ui->yPosSpinBox, 0, 300);
    qDebug()<<"Hello"<<123;

}

Widget::~Widget()
{
    delete ui;
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
    int xValue=0;
    xValue=pos.x();
    if(xValue>100){
        ui->xPosSpinBox->setValue(pos.x());
    }

    ui->yPosSpinBox->setValue(pos.y());
}
