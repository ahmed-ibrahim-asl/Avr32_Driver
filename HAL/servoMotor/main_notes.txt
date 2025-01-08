#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/TIMER/TIMER_interface.h"

#include "HAL/servoMotor/servo_interface.h"
int main(){

	servo_init();

	servo_SetAngle(40, 'A');

	servo_SetAngle(50, 'B');




	while(1){


	}


	return 0;
}
