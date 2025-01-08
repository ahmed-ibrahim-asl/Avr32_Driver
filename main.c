#include "MCAL/DIO/DIO_interface.h"
#include "HAL/LCD/LCD_HAL_interface.h"

#include "HAL/servoMotor/servo_interface.h"
#include "HAL/ultraSonic/ultraSonic_interface.h"

#include <util/delay.h>

#define F_CPU 16000000


/************************ UltraSonic Pins ************************/
#define ultraSonic_ECHO_PORT			DIO_u8PortC
#define ultraSonic_ECHO_PIN				DIO_u8PIN0

#define ultraSonic_TRIG_PORT			DIO_u8PortC
#define ultraSonic_TRIG_PIN				DIO_u8PIN1
/*****************************************************************/


int main(){
	LCD_enuInit();


    ultraSonic_t ultraSonic_Sensor ;
    ultraSonic_Sensor.ECHO_PORT = ultraSonic_ECHO_PORT;
    ultraSonic_Sensor.ECHO_PIN = ultraSonic_ECHO_PIN;

    ultraSonic_Sensor.TRIG_PORT = ultraSonic_TRIG_PORT;
    ultraSonic_Sensor.TRIG_PIN = ultraSonic_TRIG_PIN;

    ultraSonic_Sensor.measuredDistance_InCm = 0;

    // Initialize the ultrasonic sensor
    ultraSonic_enuInit(ultraSonic_Sensor);



	while(1){
		ultraSonic_u16GetDistance(&ultraSonic_Sensor);
        uint16_t distanceFront = ultraSonic_Sensor.measuredDistance_InCm;


        // Display distance on LCD
        LCD_enuClearDisplay();
        LCD_u8SendString("Dist:");
        LCD_enuIntegerToString(distanceFront, 10);

        _delay_ms(500);
	}


}




