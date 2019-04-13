#include "xaxisr.h"

#include "wiringPi.h"
#include <QDebug>

xAxisR::xAxisR()
{

}
//turn right by 7.2°.
void xAxisR::run()
{
    digitalWrite(22,LOW);
    digitalWrite(23,LOW);
    digitalWrite(24,LOW);
    digitalWrite(25,HIGH);
    delay(10);
    digitalWrite(22,LOW);
    digitalWrite(23,LOW);
    digitalWrite(24,HIGH);
    digitalWrite(25,LOW);
    delay(10);
    digitalWrite(22,LOW);
    digitalWrite(23,HIGH);
    digitalWrite(24,LOW);
    digitalWrite(25,LOW);
    delay(10);
    digitalWrite(22,HIGH);
    digitalWrite(23,LOW);
    digitalWrite(24,LOW);
    digitalWrite(25,LOW);
    delay(10);

}



