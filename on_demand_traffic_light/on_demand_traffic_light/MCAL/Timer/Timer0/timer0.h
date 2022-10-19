/*
 * timer.h
 *
 *  Created on: Sep 28, 2022
 *      Author: Nada Essam
 */

#ifndef TIMER_H_
#define TIMER_H_
#include "timer0_config.h"
#include "../../../UTILITIES/STD_TYPES.h"


void Timer0_init(void);
void Timer0_delayN(uint16 delay_ms);
void Timer0_Enable_Interrupt_OV(void);
void Timer0_Enable_Interrupt_CTC(void);
void SetCallBack_Timer0_OV(void(*p2f)(void));
void SetCallBack_Timer0_CTC(void(*p2f)(void));
void Timer0_Set_OCR0(uint8 value);


#endif /* TIMER_H_ */
