

#include <avr/io.h>		/* Include AVR std. library file */
#include <stdio.h>		/* Include std. library file */
#include <util/delay.h> /* Include Delay header file */
#define F_CPU 16000000UL


#include "Servo.h"
#include "ultrasonic.h"
#include "LCD.h"
#include "DcMotor.h"


uint8_t distance_strr[10];
uint32_t dist;

int main()
{



	servo_init();
	lcd_init();
	ultrasonic_init();
	motor_init();

	sei(); //enable the globla interrupt

	while(1)

	{
		//type the distance on the lcd
	    lcd_goto_xy(0,0);
		lcd_write_word("Distance is ");
	    lcd_goto_xy(1,0);
	    itoa(get_distance(),distance_strr,10);
	    strcat(distance_strr, " cm ");
	    lcd_write_word(distance_strr);


		servo_move(Angle90); //make the ultrasonic looks towards

	    if(get_distance()<min_allowed_distance)
	    {
	    	motor_stop(); //stop all motors
	    	lcd_clear();
	    	lcd_write_word("Searching...");
	    	_delay_ms(10);

	    	all_backward();//reverse the motors
	    	char done=0;
	    		servo_move(Angle0);
	    		_delay_ms(1000);

	    		if(get_distance()>min_allowed_distance)// cm between the ultrasonic and the object
	    		{
	    			_delay_ms(200);
	    			right();//turn right
	    			done=1;
	    		}
	    		else if(1)
	    		{
	    			servo_move(Angle180);
	    			_delay_ms(1000);
	    			if(get_distance()>min_allowed_distance)// cm between the ultrasonic and the object
	    				{
	    					left();//turn left.
	    					done=1;
	    				}
	    		}


	    		if(done==1)
	    			{
	    				servo_move(Angle90);
	    				move();
	    				lcd_clear();
	    				done=0;
	    			}
	    		else all_backward();
	    }
	    else move();


	}

}

