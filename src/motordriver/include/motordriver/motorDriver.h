#include <cstdint>
//#include <cunistd>
#include <iostream>
#include <cmath>
#include <chrono>
extern "C" {
	#include <roboticscape.h>
	#include <rc_usefulincludes.h>
}

#define MAXPULSE 20000

class MotorDriver{
private:

    //the pins are to be set to gpio pins
    /*  pin1    pin2    speed
        0       0       x	Stop (brake)
        1       1       x	Vacant
        1       0       PWM	Forward at PWM speed
        0       1       PWM	Reverse at PWM speed*/
    int pin1, pin2;

    // servoCh
    int servoCh;

    // curPulse value between -20000 and 20000 with magnitude as pwm
    // and sign as direcion: negative is backward and positve is forward
    int curPulse;

public:

    void newPulse(int newPulse);
    void pulse();

};
