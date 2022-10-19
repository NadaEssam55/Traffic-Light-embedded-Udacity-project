/*
 * app.h
 *
 *  Created on: Sep 27, 2022
 *      Author: Nada Essam
 */

#ifndef APP_H_
#define APP_H_
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/external_interrupts/external_interrupts.h"
#include "../ECUAL/LED/LED.h"
#include "../MCAL/Timer/timer0/timer0.h"
typedef enum{
	TURE,
	FALSE
}STATE;

void app_init (void);
STATE app_start (void);


#endif /* APP_H_ */
