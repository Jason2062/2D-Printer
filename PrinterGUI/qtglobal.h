#ifndef QTGLOBAL_H
#define QTGLOBAL_H

//define global variables

class qtGlobal
{
public:
    qtGlobal();
   ~qtGlobal();
public:
    //store coordinate (x,y);
    static int xValue;
    static int yValue;
    //servoMotor state;
    static bool servoState;
};

#endif // QTGLOBAL_H
