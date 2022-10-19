/*
 * external_interrupts.h
 *
 *  Created on: Sep 20, 2022
 *      Author: Nada Essam
 */

#ifndef EXTERNAL_INTERRUPTS_H_
#define EXTERNAL_INTERRUPTS_H_
#include "external_interrupt_config.h"

void EXTI_init(void);
void EXTI_enable(EXTI_type interrupt);
void EXTI_disable(EXTI_type interrupt);
void SetCallback_INT0(void(*p2f)(void));
void SetCallback_INT1(void(*p2f)(void));
void SetCallback_INT2(void(*p2f)(void));



#endif /* EXTERNAL_INTERRUPTS_H_ */
