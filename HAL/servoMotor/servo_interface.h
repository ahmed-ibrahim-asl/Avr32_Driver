/*
 * servo_interface.h
 *
 *  Created on: Oct 11, 2024
 *      Author: ad
 */

#include "../../MCAL/DIO/DIO_interface.h"


void servo_init();

void servo_SetAngle(uint8_t copy_u8Angle, uint8_t copy_u8Channel);
