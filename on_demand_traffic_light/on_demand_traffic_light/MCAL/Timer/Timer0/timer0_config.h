/*
 * timer_config.h
 *
 *  Created on: Sep 28, 2022
 *      Author: Nada Essam
 */

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_


#define NO_clk_source				0
#define clk							1
#define clk_8						2
#define clk_64						3
#define clk_256						4
#define clk_1024					5
#define External_clk_falling_edge	6
#define External_clk_raising_edge	7

#define Clk_Source_Selection	clk_1024
////////////////////////////////////
#define Normal_mode				0
#define CTC_mode				1
#define PWM_Phase_coreect_mode	2
#define PWM_fast_mode			3

#define Mode_Selection	 Normal_mode
//////////////////////////////////////




#endif /* TIMER_CONFIG_H_ */
