/*
 * LED.c

 *
 *  Created on: Sep 27, 2022
 *      Author: Nada Essam
 */
#include "LED.h"
#include "../../MCAL/Timer/timer0/timer0.h"
void LED_ON(TRAFFIC_LIGHT led_mode){
	Dio_write(led_mode,HIGH);
}

void LED_OFF(TRAFFIC_LIGHT led_mode){
	Dio_write(led_mode,LOW);
}

void LED_TOGGLE (TRAFFIC_LIGHT led_mode){
		Dio_FlipChannel(led_mode);
}
