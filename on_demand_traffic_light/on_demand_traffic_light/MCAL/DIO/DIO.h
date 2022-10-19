/*
 * DIO.h
 *
 *  Created on: Sep 7, 2022
 *      Author: Nada Essam
 */

#ifndef DIO_H_
#define DIO_H_
#include "../../UTILITIES/REGISTERS.h"
#include "../../UTILITIES/MATH_BIT.h"
#include "../../UTILITIES/STD_TYPES.h"
#include "DIO_STD.h"
#include "Dio_config.h"

void Dio_init(void);
void Dio_write(channel_type channel,Dio_status_type state); //write either high or low to the pin
Dio_status_type Dio_read(channel_type channel); //read either high or low in the pin
void Dio_WritePort(Dio_port_type port, uint8 Level);
void Dio_FlipChannel(channel_type channel);


#endif /* DIO_H_ */
