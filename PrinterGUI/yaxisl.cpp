#include "yaxisl.h"

#include "wiringPi.h"
#include <QDebug>

yAxisL::yAxisL()
{

}
//turn left by 7.2°.
/**
 * @brief yAxisL::run run yAxisl thread which turn left y Motro by 7.2°.
 */
void yAxisL::run()
{
    digitalWrite(26,LOW);
    digitalWrite(27,LOW);
    digitalWrite(28,LOW);
    digitalWrite(29,HIGH);
    delay(10);
    digitalWrite(26,LOW);
    digitalWrite(27,LOW);
    digitalWrite(28,HIGH);
    digitalWrite(29,LOW);
    delay(10);
    digitalWrite(26,LOW);
    digitalWrite(27,HIGH);
    digitalWrite(28,LOW);
    digitalWrite(29,LOW);
    delay(10);
    digitalWrite(26,HIGH);
    digitalWrite(27,LOW);
    digitalWrite(28,LOW);
    digitalWrite(29,LOW);
    delay(10);
}
