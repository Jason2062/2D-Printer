#ifndef YAXISR_H
#define YAXISR_H

#include <QThread>
// Create threads which turn the motor that controls the y direction to the right by 7.2°.
/**
 * @brief The yAxisR class threads which turn the motor that controls the X direction to the left by 7.2°.
 */
class yAxisR : public QThread
{

public:
    yAxisR();
    void run();
};

#endif // YAXISR_H
