#include "motorDriver.h"

/*Default ctor*/
MotorDriver::MotorDriver(){
    pin1 = 113;
    pin2 = 116;
    servoCh = 1;
    curPulse = 0;
}

/*ctor*/
MotorDriver::MotorDriver(int newPin1, int newPin2, int newServo)
:pin1(newPin1),pin2(newPin2),newServo(servoCh),curPulse(0){
    rc_initialize();

    rc_set_default_pinmux();
    rc_gpio_export(pin1);
    rc_gpio_set_dir(pin1, OUTPUT_PIN);
    rc_gpio_export(pin2);
    rc_gpio_set_dir(pin2, OUTPUT_PIN);
}

/*Sets pulse to a value between -20000 and 20000us*/
MotorDriver::newPulse(int newPulse){

    curPulse = newPulse;

    if (curPulse < 0) {
        //backward
		curPulse *= -1 ;
		rc_gpio_set_value(pin2, HIGH);
		rc_gpio_set_value(pin1, LOW);
	} else {
        //forward
		rc_gpio_set_value(pin1, HIGH);
		rc_gpio_set_value(pin2, LOW);
	}

    curPulse = (curPulse > MAXPULSE)? MAXPULSE :curPulse;
}

/*This is meant to be called at a frequency of 50hz or every 20000 us*/
MotorDriver::pulse(){
    rc_send_servo_pulse_us(servoCh, curPulse);
}
