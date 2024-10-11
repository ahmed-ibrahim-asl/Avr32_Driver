#include "MCAL/DIO/DIO_interface.h"

#include "HAL/LCD/LCD_HAL_interface.h"
#include "HAL/ultraSonic/ultraSonic_interface.h"
#include <util/delay.h>

int main(void) {

	LCD_enuInit();



	ultraSonic_t ultraSonic_1;
	ultraSonic_1.ECHO_PORT = DIO_u8PortD;
	ultraSonic_1.ECHO_PIN = DIO_u8PIN6;

	ultraSonic_1.TRIG_PORT = DIO_u8PortD;
	ultraSonic_1.TRIG_PIN = DIO_u8PIN7;
	ultraSonic_enuInit(ultraSonic_1);



    while (1) {
        // Main loop

    	ultraSonic_u16GetDistance(&ultraSonic_1);


        LCD_enuClearDisplay();
    	LCD_enuIntegerToString(ultraSonic_1.measuredDistance_InCm, 10);

        _delay_ms(1000);  // Delay before the next reading
    }

    return 0;
}
