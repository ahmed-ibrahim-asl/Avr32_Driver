/*
 * ultraSonic_interface.h
 *
 *  Created on: Sep 7, 2024
 *      Author: ad
 */

#ifndef HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_
#define HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_


//! This very critcial,  Ensure the system runs at the specified frequency


#define F_CPU 16000000

typedef struct{
	uint8_t ECHO_PORT;
	uint8_t ECHO_PIN;

	uint8_t TRIG_PORT;
	uint8_t TRIG_PIN;

	uint16  measuredDistance_InCm;
}ultraSonic_t;


ErrorStatus_t ultraSonic_enuInit(ultraSonic_t ultraSonic_Instance);
void ultraSonic_u16GetDistance(ultraSonic_t* ultraSonic_Instance);


#endif /* HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_ */
