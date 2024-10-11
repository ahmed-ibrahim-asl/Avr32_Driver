#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/TIMER/TIMER_interface.h"


int main(){
	TIMER1_voidInit();

	TIMER1_voidSetPWM_16bit(6.25, 50);
	while(1){}
}
