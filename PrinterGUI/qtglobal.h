#ifndef QTGLOBAL_H
#define QTGLOBAL_H

//define global variables
/**
 * @brief The qtGlobal class
 */
class qtGlobal
{
public:
    qtGlobal();
   ~qtGlobal();
public:

    //store coordinate (x,y);
    /**
     * @brief xValue define global variable, store coordinate x.
     */
    static int xValue;
    /**
     * @brief yValue define global variable, store coordinate y.
     */
    static int yValue;
    //servoMotor state;
    /**
     * @brief servoState servoMotor state, which control the up and down movement of pen.
     */
    static bool servoState;
};

#endif // QTGLOBAL_H
