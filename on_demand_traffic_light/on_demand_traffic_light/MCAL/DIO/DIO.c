/*
 * DIO.c

 *
 *  Created on: Sep 7, 2022
 *      Author: Nada Essam
 */
#include "DIO.h"
#include "Dio_config.h"
void Dio_init(void){
 // we may not use a pointer since the array is global
uint32 size=sizeof(pin_conf)/sizeof(pin_conf[0]);
for (int i=0;i<size;i++){
	if(pin_conf[i].port==PORT_A){
		if(pin_conf[i].direction==OUTPUT)
			Set_Bit(DDRA,pin_conf[i].pin);
		else{
			Clear_Bit(DDRA,pin_conf[i].pin);
		    if (pin_conf[i].pullup==PULLUP_ON){
		    	Set_Bit(PORTA,pin_conf[i].pin);
		    }
		}
	}
	else if(pin_conf[i].port==PORT_B){
		if(pin_conf[i].direction==OUTPUT)
			Set_Bit(DDRB,pin_conf[i].pin);
		else{
			Clear_Bit(DDRB,pin_conf[i].pin);
			 if (pin_conf[i].pullup==PULLUP_ON){
				 Set_Bit(PORTB,pin_conf[i].pin);
			 }
		}
	}
	else if(pin_conf[i].port==PORT_C){
		if(pin_conf[i].direction==OUTPUT)
			Set_Bit(DDRC,pin_conf[i].pin);
		else{
			Clear_Bit(DDRC,pin_conf[i].pin);
			 if (pin_conf[i].pullup==PULLUP_ON){
				 Set_Bit(PORTC,pin_conf[i].pin);
			 }
		}
	}
	else if(pin_conf[i].port==PORT_D){
		if(pin_conf[i].direction==OUTPUT)
			Set_Bit(DDRD,pin_conf[i].pin);
		else{
			Clear_Bit(DDRD,pin_conf[i].pin);
			 if (pin_conf[i].pullup==PULLUP_ON){
				 Set_Bit(PORTD,pin_conf[i].pin);
			 }
		}

	}
}
}

/////////////////////////////////////////////////////////////////

void Dio_write(channel_type channel,Dio_status_type state){
	Dio_port_type port = channel/8;
	Dio_pin_type pin = channel%8;
	if(port==PORT_A){
		if(state==HIGH)
			Set_Bit(PORTA,pin);
		else
			Clear_Bit(PORTA,pin);
	}
	else if(port==PORT_B){
		if(state==HIGH)
			Set_Bit(PORTB,pin);
		else
			Clear_Bit(PORTB,pin);
	}
	else if(port==PORT_C){
		if(state==HIGH)
			Set_Bit(PORTC,pin);
		else
			Clear_Bit(PORTC,pin);
	}
	else if(port==PORT_D){
		if(state==HIGH)
			Set_Bit(PORTD,pin);
		else
			Clear_Bit(PORTD,pin);
	}
}
/////////////////////////////////////////////////////////

Dio_status_type Dio_read(channel_type channel){
	Dio_port_type port = channel/8;
	Dio_pin_type pin = channel%8;
	Dio_status_type status=0;
	if(port==PORT_A){
		status=Get_Bit(PINA,pin);
	}
	else if(port==PORT_B){
		status=Get_Bit(PINB,pin);
	}
	else if(port==PORT_C){
			status=Get_Bit(PINC,pin);
		}
	else if(port==PORT_D){
			status=Get_Bit(PIND,pin);
		}
	return status;
}
////////////////////////////////////////////////////////////
void Dio_WritePort(Dio_port_type port, uint8 Level){
	    if(port==PORT_A){
			PORTA=Level; // EX:level=0xff
		}
		else if(port==PORT_B){
			PORTB=Level;
		}
		else if(port==PORT_C){
			PORTC=Level;
		}
		else if(port==PORT_D){
			PORTD=Level;
		}
}
//////////////////////////////////////////////////////////////
void Dio_FlipChannel(channel_type channel){
	Dio_port_type port = channel/8;
		Dio_pin_type pin = channel%8;
		if(port==PORT_A){
			Toggle_Bit(PORTA, pin);
		}
		else if(port==PORT_B){
			Toggle_Bit(PORTB, pin);

		}
		else if(port==PORT_C){
			Toggle_Bit(PORTC, pin);
		}
		else if(port==PORT_D){
			Toggle_Bit(PORTD, pin);
		}
}
