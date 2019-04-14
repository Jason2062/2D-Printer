#ifndef XAXISL_H
#define XAXISL_H

#include <QThread>
// Create threads which turn the motor that controls the X direction to the left by 7.2°.
/**
 * @brief The xAxisL class  thread which turn the motor that controls the X direction to the left by 7.2°.
 */
class xAxisL : public QThread
{
public:
    xAxisL();
    void run();
};

#endif // XAXISL_H
