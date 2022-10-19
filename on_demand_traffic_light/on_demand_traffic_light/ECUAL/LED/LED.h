/*
 * LED.h
 *
 *  Created on: Sep 27, 2022
 *      Author: Nada Essam
 */

#ifndef LED_H_
#define LED_H_
#include "LED_config.h"
#include "../../MCAL/DIO/DIO.h"

void LED_ON(TRAFFIC_LIGHT led_mode);
void LED_OFF(TRAFFIC_LIGHT led_mode);
void LED_TOGGLE (TRAFFIC_LIGHT led_mode);

#endif /* LED_H_ */
