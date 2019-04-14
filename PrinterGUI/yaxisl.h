#ifndef YAXISL_H
#define YAXISL_H

#include <QThread>
// Create thread which turn the motor that controls the y direction to the left by 7.2°.
/**
 * @brief The yAxisL class thread which turn the motor that controls the X direction to the left by 7.2°.
 */
class yAxisL : public QThread
{

public:
    yAxisL();
    void run();
};

#endif // YAXISL_H

