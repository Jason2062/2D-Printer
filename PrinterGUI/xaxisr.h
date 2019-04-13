#ifndef XAXISR_H
#define XAXISR_H

#include <QThread>
// Create threads which turn the motor that controls the X direction to the right by 7.2°.
class xAxisR : public QThread
{

public:
    xAxisR();
    void run();
};

#endif // XAXISR_H
