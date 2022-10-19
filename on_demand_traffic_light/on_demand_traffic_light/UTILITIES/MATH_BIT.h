/*
 * MATH_BIT.h
 *
 *  Created on: Sep 7, 2022
 *      Author: Nada Essam
 */

#ifndef MATH_BIT_H_
#define MATH_BIT_H_

#define Clear_Bit(reg,pin)   ((reg) &=~(1<<pin))
#define Set_Bit(reg,pin)     ((reg) |=(1<<pin))
#define Get_Bit(reg,pin)     ((reg>>pin)&1)
#define Toggle_Bit(reg, pin) ((reg) ^=(1<<pin))
#define rotate_left(reg,pin_num) ((reg<<pin_num)|(reg>>(8-pin_num)))
#define rotate_right(reg,pin_num) ((reg>>pin_num)|(reg<<(8-pin_num)))

#endif /* MATH_BIT_H_ */
