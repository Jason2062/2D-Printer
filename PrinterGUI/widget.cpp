#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
#include "qtglobal.h"

#include "xaxisr.h"
#include "xaxisl.h"

#include "yaxisr.h"
#include "yaxisl.h"

#include "wiringPi.h"
#include "softPwm.h"
/**
 * @brief Widget::Widget
 * @param parent
 */
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    //create motor Threads
    xThreadr = new xAxisR(); //!< turn right xmotor threads
    xThreadl = new xAxisL(); //!< turn left  xmotor threads

    yThreadr = new yAxisR(); //!< turn right ymotor threads
    yThreadl = new yAxisL(); //!M turn left  ymotor threads

    //set painter

    //set backcolor=white
    QColor backcolor =qRgb(255,255,255);//!<set the color of paint board.
    //set the size of paint board
    m_image =QImage(2000,2000,QImage::Format_RGB32);//!< set the size of paint board.
    //fill the white board
    m_image.fill(backcolor);

    ui->setupUi(this);
    //display coordinates of mouse
    ui->estadoLineEdit->setReadOnly(true);
    ui->xPosSpinBox->setReadOnly(true);
    ui->yPosSpinBox->setReadOnly(true);

    ui->xPosSpinBox->setValue(cursor().pos().x());
    ui->yPosSpinBox->setValue(cursor().pos().y());
    //set the range of coordinates
    configureSpinBox(ui->xPosSpinBox, 0, +INT_MAX);//!< configure the display range of spinBox
    configureSpinBox(ui->yPosSpinBox, 0, +INT_MAX);//!< configure the display range of spinBox
    qDebug()<<"Hello"<<123;

    //set pinMode which controls the stepper motor rotation and servo motor.
    /**
     * @brief wiringPiSetup set pinMode which controls the stepper motor ration and servo motor.
     */
    wiringPiSetup();
    //stepper motor on x axis
    pinMode(22,OUTPUT);
    pinMode(23,OUTPUT);
    pinMode(24,OUTPUT);
    pinMode(25,OUTPUT);
    //stepper motor on y axis
    pinMode(26,OUTPUT);
    pinMode(27,OUTPUT);
    pinMode(28,OUTPUT);
    pinMode(29,OUTPUT);
    //servo motor pinMode
    pinMode(1,OUTPUT);
    softPwmCreate(1,0,100);
}

Widget::~Widget()
{
    delete ui;
}



/**
 * @brief Widget::mousePressEvent Create a mousePressEvent function. In this function, the servoState(pen) movement can be switched by mousePress event.
 * @param event
 */
void Widget::mousePressEvent(QMouseEvent *event)
{
    //painter: when mousePress happen, record the fisrt coordinate. mousePress always happens before mouseMove
    m_prevPoint = event->pos();

    //Control the up and down movement of the pen by give different PWM signal to pin 1.
    //Two different PWM period, 1ms and 2ms can be switched by mousePress

    if(qtGlobal::servoState==true)
    {
        //generate 2ms PWM period. When the on-time is 2ms the motor will be in 180°.
        softPwmWrite(1,20);
        qDebug()<<"20";
        //change the state of servoState, s
        qtGlobal::servoState=false;
    }
    else if(qtGlobal::servoState==false)
    {
        //generate 1ms PWM period. When the on-time is 1ms the motor will be in 0°.
        softPwmWrite(1,10);
        qDebug()<<"10";
        qtGlobal::servoState=true;
    }


    onMouseEvent("Press", event->pos());

    QWidget::mousePressEvent(event);

}
/**
 * @brief Widget::mouseMoveEvent define a mouseMoveEvent function. In this function, the path of mouseMove can be recorded by painter when the state of servomotor is true.
 * @param event
 */
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    //when mouseMove happens, record the second coordinates. and connected with the first coordinate by painter.

    m_curPoint=event->pos();

    QPainter painter(&m_image);
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(2);
    painter.setPen(pen);

    //when servoState is true which means the pen is writing. The line will be connected.
    if(qtGlobal::servoState==true)
    {
        painter.drawLine(m_prevPoint,m_curPoint);
    }
    update();
    m_prevPoint = m_curPoint;


    //onMouseEvent

    onMouseEvent("Move", event->pos());

    QWidget::mouseMoveEvent(event);
}

/**
 * @brief Widget::configureSpinBox In this function, the display range can be set.
 * @param spinBox name of spinBox
 * @param min min number
 * @param max max number
 */
void Widget::configureSpinBox(QSpinBox *spinBox, int min, int max) const
{
    spinBox->setMinimum(min);
    spinBox->setMaximum(max);
}
/**
 * @brief Widget::onMouseEvent In this function, the coordinate of mouse will be recorded and compared with previous number when mouseMoveEvent and mousePressEvent happens.
 * @param eventName
 * @param pos
 */
void Widget::onMouseEvent(const QString &eventName, const QPoint &pos)
{
    //display the event of mouse
    ui->estadoLineEdit->setText(eventName);

    //
    qDebug()<<qtGlobal::xValue;
    qDebug()<<pos.x();

    //if the current x value larger than the previous value. The xThreadr thread start.
    if(pos.x()>qtGlobal::xValue)
    {
        xThreadr->start();
    }
    //if the current x value smaller than the previous value. The xThreadl thread start.
    else if(pos.x()<qtGlobal::xValue)
    {
        xThreadl->start();
    }
    //if the current y value larger than the previous value. The xThreadr thread start.
    if(pos.y()>qtGlobal::yValue)
   {
       yThreadr->start();
    }
    //if the current y value smaller than the previous value. The xThreadl thread start.
    else if (pos.y()<qtGlobal::yValue)
    {
        yThreadl->start();
    }
    //assign the current coordinate to xValue and yValue.
    qtGlobal::xValue=pos.x();
    qtGlobal::yValue=pos.y();
    ui->xPosSpinBox->setValue(pos.x());
    ui->yPosSpinBox->setValue(pos.y());
}
/**
 * @brief Widget::paintEvent draw image of mousepath
 */
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawImage(0,0,m_image);
}
/**
 * @brief Widget::on_pushButton_clicked In this function, the paint board will be reset once the refresh button is clicked.
 */
void Widget::on_pushButton_clicked()
{
    //When press click refresh button, reset backboard.
    QColor backcolor=qRgb(255,255,255);
    m_image=QImage(2000,2000,QImage::Format_RGB32);
    m_image.fill(backcolor);
    update();
}

