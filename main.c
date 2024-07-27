
/**
 * [Amit kit LEDs PIN out]
 *
 * Right  led	- (PORTC)	(2)
 * Center led   - (PORTC)	(7)
 * Left   led   - (PORTD)	(3)
 * */

/******************** Include  Section Start ********************/
#include "MCAL/DIO/DIO_interface.h"
#include "HAL/LCD/LCD_HAL_interface.h"
/****************************************************************/



int main(){

	DIO_enuSetPinDirection(DIO_u8PortC, DIO_u8PIN2, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DIO_u8PortC, DIO_u8PIN7, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DIO_u8PortD, DIO_u8PIN3, DIO_u8OUTPUT);





	DIO_enuSetPinValue(DIO_u8PortD, DIO_u8PIN3, 0);
	DIO_enuSetPinValue(DIO_u8PortC, DIO_u8PIN2, 1);
	DIO_enuSetPinValue(DIO_u8PortC, DIO_u8PIN7, 0);

	while(1){

	}
}
