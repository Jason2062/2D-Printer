#ifndef XAXISR_H
#define XAXISR_H

#include <QThread>
// threads which turn the motor that controls the X direction to the right by 7.2°.
/**
 * @brief The xAxisR class thread which turn the motor that controls the X direction to the left by 7.2°.
 */
class xAxisR : public QThread
{

public:
    xAxisR();
    void run();
};

#endif // XAXISR_H
