/*
 * external_interrupts.c

 *
 *  Created on: Sep 20, 2022
 *      Author: Nada Essam
 */
#include "external_interrupts.h"
#include "../DIO/DIO.h"
#include "../../UTILITIES/REGISTERS.h"
#include <avr/interrupt.h>

void (*p2f_INT0)(void);
void (*p2f_INT1)(void);
void (*p2f_INT2)(void);

void EXTI_init(void){
#if EXT_INT0_MODE == ENABLE
	EXTI_enable(EXTI0);
#if INT0_SENSE_MODE == LOW_LEVEL_TRIG
	Clear_Bit(MCUCR,ISC00);
	Clear_Bit(MCUCR,ISC01);
#elif INT0_SENSE_MODE == ANY_LOGIC_TRIG
	Set_Bit(MCUCR,ISC00);
	Clear_Bit(MCUCR,ISC01);
#elif INT0_SENSE_MODE == FALLING_EDGE_TRIG
	Clear_Bit(MCUCR,ISC00);
	Set_Bit(MCUCR,ISC01);
#elif INT0_SENSE_MODE == RAISING_EDGE_TRIG
	Set_Bit(MCUCR,ISC00);
	Set_Bit(MCUCR,ISC01);
#endif
#endif

#if EXT_INT1_MODE == ENABLE
	EXTI_enable(EXTI1);
#if INT1_SENSE_MODE == LOW_LEVEL_TRIG
	Clear_Bit(MCUCR,ISC10);
	Clear_Bit(MCUCR,ISC11);
#elif INT1_SENSE_MODE == ANY_LOGIC_TRIG
	Set_Bit(MCUCR,ISC10);
	Clear_Bit(MCUCR,ISC11);
#elif INT1_SENSE_MODE == FALLING_EDGE_TRIG
	Clear_Bit(MCUCR,ISC10);
	Set_Bit(MCUCR,ISC11);
#elif INT1_SENSE_MODE == RAISING_EDGE_TRIG
	Set_Bit(MCUCR,ISC10);
	Set_Bit(MCUCR,ISC11);
#endif
#endif

#if EXT_INT2_MODE == ENABLE
	EXTI_enable(EXTI2);
#if INT1_SENSE_MODE == FALLING_EDGE_TRIG
	Clear_Bit(MCUCSR,ISC2);
#elif INT1_SENSE_MODE == RAISING_EDGE_TRIG
	Set_Bit(MCUCSR,ISC2);
#endif
#endif
}

void EXTI_enable(EXTI_type interrupt){
	switch (interrupt){
	case EXTI0 :
		Set_Bit(GICR,INT0);
		break;
	case EXTI1 :
		Set_Bit(GICR,INT1);
		break;
	case EXTI2 :
		Set_Bit(GICR,INT2);
		break;
	}
}

void EXTI_disable(EXTI_type interrupt){
	switch (interrupt){
	case EXTI0 :
		Clear_Bit(GICR,INT0);
		break;
	case EXTI1 :
		Clear_Bit(GICR,INT1);
		break;
	case EXTI2 :
		Clear_Bit(GICR,INT2);
		break;
	}
}

void SetCallback_INT0(void(*p2f)(void)){
	p2f_INT0=p2f;
}
void SetCallback_INT1(void(*p2f)(void)){    //then we call this function and pass to it the function
	p2f_INT1=p2f;							//we want to implement ex:(toggle led) it in the isr,
}											// so we are saving the address of toggle led to p2f_INTx
void SetCallback_INT2(void(*p2f)(void)){	//which which will get called in the isr
	p2f_INT2=p2f;
}

ISR(INT0_vect){
	if(p2f_INT0 !=0){
		p2f_INT0();
	}
}
ISR(INT1_vect){
	if(p2f_INT1 !=0){
		p2f_INT1();
	}
}
ISR(INT2_vect){
	if(p2f_INT2 !=0){
		p2f_INT2();
	}
}

