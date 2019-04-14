#include "xaxisl.h"

#include "wiringPi.h"
#include <QDebug>

xAxisL::xAxisL()
{

}

//turn left by 7.2°.
/**
 * @brief xAxisL::run run threads which turn left the x Motor by 7.2°.
 */
void xAxisL::run()
{

    digitalWrite(22,HIGH);
    digitalWrite(23,LOW);
    digitalWrite(24,LOW);
    digitalWrite(25,LOW);
    delay(10);
    digitalWrite(22,LOW);
    digitalWrite(23,HIGH);
    digitalWrite(24,LOW);
    digitalWrite(25,LOW);
    delay(10);
    digitalWrite(22,LOW);
    digitalWrite(23,LOW);
    digitalWrite(24,HIGH);
    digitalWrite(25,LOW);
    delay(10);
    digitalWrite(22,LOW);
    digitalWrite(23,LOW);
    digitalWrite(24,LOW);
    digitalWrite(25,HIGH);
    delay(10);

}
