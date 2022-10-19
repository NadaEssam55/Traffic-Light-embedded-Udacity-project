#include "DIO_STD.h"
#include "DIO.h"
#include "Dio_config.h"
// initialization for all pins used in the project
PINCONFIG pin_conf[7]={
		{PORT_A,PIN_0,OUTPUT,PULLUP_OFF},
		{PORT_A,PIN_1,OUTPUT,PULLUP_OFF},
		{PORT_A,PIN_2,OUTPUT,PULLUP_OFF},
		{PORT_B,PIN_0,OUTPUT,PULLUP_OFF},
		{PORT_B,PIN_1,OUTPUT,PULLUP_OFF},
		{PORT_B,PIN_2,OUTPUT,PULLUP_OFF},
		{PORT_D,PIN_2,INPUT,PULLUP_OFF}
};
