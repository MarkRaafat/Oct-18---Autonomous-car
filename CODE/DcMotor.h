
#ifndef Dc.Motor.h
#define Dc.Motor.h
#include "avr/io.h"
#include <util/delay.h>


void motor_init(void);
void motor_1_forward(void);
void motor_2_forward(void);
void motor_stop(void);
void move(void);
void right(void);
void left(void);


#endif 