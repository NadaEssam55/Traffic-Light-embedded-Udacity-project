/*
 * Dio_config.h
 *
 *  Created on: Sep 10, 2022
 *      Author: Nada Essam
 */

#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_
#include "DIO.h"

typedef struct {
	Dio_port_type port;
	Dio_pin_type pin;
	DIRCTION direction;
	PULLUP pullup;
}PINCONFIG;
extern PINCONFIG pin_conf[7];

#endif /* DIO_CONFIG_H_ */
