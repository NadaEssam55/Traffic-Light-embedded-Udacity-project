/*
 * REGISTERS.h
 *
 *  Created on: Sep 27, 2022
 *      Author: Nada Essam
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "STD_TYPES.h"


#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7



//PortA registers
#define PORTA (*(volatile uint8*)(0x3B))
#define DDRA (*(volatile uint8*)(0x3A))
#define PINA (*(volatile uint8*)(0x39))

//PortB registers
#define PORTB (*(volatile uint8*)(0x38))
#define DDRB (*(volatile uint8*)(0x37))
#define PINB (*(volatile uint8*)(0x36))

//PortC registers
#define PORTC (*(volatile uint8*)(0x35))
#define DDRC (*(volatile uint8*)(0x34))
#define PINC (*(volatile uint8*)(0x33))

//PortD registers
#define PORTD (*(volatile uint8*)(0x32))
#define DDRD (*(volatile uint8*)(0x31))
#define PIND (*(volatile uint8*)(0x30))

//timer registers
#define TCCR0 (*(volatile uint8*)(0x53))
#define TCNT0 (*(volatile uint8*)(0x52))
#define TIFR (*(volatile uint8*)(0x58))
#define TIMSK (*(volatile uint8*)(0x59))


//interrupt register
#define SREG (*(volatile uint8*)(0x5F))
#define GICR (*(volatile uint8*)(0x5B))
#define MCUCR (*(volatile uint8*)(0x55))


#endif /* REGISTERS_H_ */
