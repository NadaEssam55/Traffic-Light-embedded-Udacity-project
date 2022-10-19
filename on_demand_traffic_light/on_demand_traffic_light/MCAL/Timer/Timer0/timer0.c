/*
 * timer.c
 *
 *  Created on: Sep 28, 2022
 *      Author: Nada Essam
 */

#include <math.h>
#include <avr/interrupt.h>
#include "timer0.h"
#include "../../../UTILITIES/MATH_BIT.h"
#include "../../../UTILITIES/REGISTERS.h"
#include "../../../UTILITIES/STD_TYPES.h"
void (*Timer0_p2f_OV)(void);
void (*Timer0_p2f_CTC)(void);
void Timer0_init(void){
#if (Clk_Source_Selection == NO_clk_source)
	Clear_Bit(TCCR0,CS00);
	Clear_Bit(TCCR0,CS01);
	Clear_Bit(TCCR0,CS02);
#elif (Clk_Source_Selection == clk)
	Set_Bit(TCCR0,CS00);
	Clear_Bit(TCCR0,CS01);
	Clear_Bit(TCCR0,CS02);
#elif (Clk_Source_Selection == clk_8)
	Clear_Bit(TCCR0,CS00);
	Set_Bit(TCCR0,CS01);
	Clear_Bit(TCCR0,CS02);
#elif (Clk_Source_Selection == clk_64)
	Set_Bit(TCCR0,CS00);
	Set_Bit(TCCR0,CS01);
	Clear_Bit(TCCR0,CS02);
#elif (Clk_Source_Selection == clk_256)
	Clear_Bit(TCCR0,CS00);
	Clear_Bit(TCCR0,CS01);
	Set_Bit(TCCR0,CS02);
#elif (Clk_Source_Selection == clk_1024)
	Set_Bit(TCCR0,CS00);
	Clear_Bit(TCCR0,CS01);
	Set_Bit(TCCR0,CS02);
#elif (Clk_Source_Selection == External_clk_falling_edge)
	Clear_Bit(TCCR0,CS00);
	Set_Bit(TCCR0,CS01);
	Set_Bit(TCCR0,CS02);
#elif (Clk_Source_Selection == External_clk_raising_edge)
	Set_Bit(TCCR0,CS00);
	Set_Bit(TCCR0,CS01);
	Set_Bit(TCCR0,CS02);
#endif

#if (Mode_Selection == Normal_mode)
	Clear_Bit(TCCR0,WGM00);
	Clear_Bit(TCCR0,WGM01);
#elif (Mode_Selection == CTC_mode)
	Set_Bit(TCCR0,WGM00);
	Clear_Bit(TCCR0,WGM01);
#elif (Mode_Selection == PWM_Phase_coreect_mode)
	Clear_Bit(TCCR0,WGM00);
	Set_Bit(TCCR0,WGM01);
#elif (Mode_Selection == PWM_Phase_coreect_mode)
	Set_Bit(TCCR0,WGM00);
	Set_Bit(TCCR0,WGM01);
#endif
	TCNT0=0x00;
}

void Timer0_delayN(uint16 delay_ms){ //NORMAL MODE
	f64 Ttick;
	f64 f_cpu=8000000.0;
	f64 delay = delay_ms * 0.001;
	uint16 counter;
	if (Clk_Source_Selection == clk){
		Ttick=1.0/f_cpu;
	}
	else if (Clk_Source_Selection == clk_8){
		Ttick=8.0/f_cpu;
	}
	else if (Clk_Source_Selection == clk_64){
		Ttick=64.0/f_cpu;
	}
	else if (Clk_Source_Selection == clk_256){
		Ttick=256.0/f_cpu;
	}
	else if (Clk_Source_Selection == clk_1024){
		Ttick=1024.0/f_cpu;
	}
	counter = ceil(delay/(Ttick*256));
	for (int i=0;i<counter;i++){
	while(Get_Bit(TIFR,TOV0)==0);
	Set_Bit(TIFR,TOV0);
	}
}
void Timer0_Enable_Interrupt_OV(void){
	Set_Bit(TIMSK,TOIE0);
}
void Timer0_Enable_Interrupt_CTC(void){
	Set_Bit(TIMSK,OCIE0);
}
void Timer0_Set_OCR0(uint8 value){
	OCR0=value;
}
void SetCallBack_Timer0_OV(void(*p2f)(void)){
	Timer0_p2f_OV =p2f;

}
void SetCallBack_Timer0_CTC(void(*p2f)(void)){
	Timer0_p2f_CTC=p2f;
}

ISR(TIMER0_OVF_vect){
	if (Timer0_p2f_OV !=0){
		Timer0_p2f_OV();
	}
}
ISR(TIMER0_COMP_vect){
	if (Timer0_p2f_CTC !=0){
		Timer0_p2f_CTC();
	}
}
