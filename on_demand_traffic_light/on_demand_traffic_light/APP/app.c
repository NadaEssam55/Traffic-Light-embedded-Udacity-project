/*
 * app.c
 *
 *  Created on: Sep 27, 2022
 *      Author: Nada Essam
 */
#include "app.h"
#include "avr/interrupt.h"
volatile uint8 mode =0;
static void MODE (void){
	Timer0_delayN(1000);
	if((Dio_read(PORTD_2)==0)){ //the button must be released after 1 sec
		mode =1;
	}
}
void app_init (void){
	Dio_init();									//initialization of DIO ,external interrupt and timer as well
	EXTI_init();
	Timer0_init();
	sei();
}

STATE app_start (void){
	 static uint8 Green_flag=1;  				//a variable for each color in the traffic light
	 static uint8 Yellow_flag=0;
	 static uint8 Red_flag=0;
	SetCallback_INT0(MODE);						//the isr function to call
///////////////////////////////////////
	if(Green_flag==1){							//start with the green light in the normal mode
		uint8 counter1=0;
		LED_ON(GREEN_CAR);
		LED_OFF(RED_CAR);
		LED_OFF(YELLOW_CAR);
		while(counter1<10){						//delay for 5 sec
			Timer0_delayN(500);
			counter1++;
			if(mode!=0)break;					//each 0.5 sec check if the button is not pressed
		}
		if (mode==1){							//if the button is pressed the light up the red pedestrian light
			LED_ON(RED_PED);
		}
		Yellow_flag =1;							//rise up the yellow light flag
		Green_flag =0;							//get the green flag be zero
	}
///////////////////////////////////////
	if (Yellow_flag == 1){
		static uint8 yellow_flag_counter =0;
		static uint8 yellow_flag_counter1=0;
		LED_OFF(GREEN_CAR);						//turn off the green light
		LED_OFF(RED_CAR);
		uint8 counter2=0;
		if(mode==0){							//for normal mode toggle the car yellow light for 5 sec
			LED_OFF(GREEN_PED);
			LED_OFF(RED_PED);
		while(counter2<20){						//delay for 5 sec and toggle each .25 sec
			Timer0_delayN(250);
			counter2++;
			LED_TOGGLE (YELLOW_CAR);
			if(mode !=0)break;
		}
		if (counter2 ==20){						//in case for normal mode check if we light up the yellow light after the red or green light to rise which flag
			if(yellow_flag_counter%2 ==0){
				Red_flag =1;
			}
			else {
				Green_flag = 1;
			}
			yellow_flag_counter++;
		}
		}
		if(mode == 1){					//for pedestrian light both yellow lights for car and pedestrian
			if(yellow_flag_counter1 %2==0){
				LED_ON(RED_PED);
			}
			else{
				LED_OFF(RED_PED);
			}
			counter2=0;
			LED_OFF(YELLOW_CAR);
			while(counter2<20){
				Timer0_delayN(250);
				counter2++;
				LED_TOGGLE (YELLOW_CAR);
				LED_TOGGLE(YELLOW_PED);
			}
			Red_flag =1;
			yellow_flag_counter1 ++;
		}
		Yellow_flag =0;					//put the yellow flag by zero
	}
/////////////////////////////////////////////
	if(Red_flag == 1){					//red flag for red light
		uint8 counter3 =0;
		static uint8 Red_flag_counter=0;
		LED_OFF(YELLOW_CAR);			//turn off the yellow light
		LED_OFF(YELLOW_PED);
		if(mode == 1){					//for pedestrian mode
		if(Red_flag_counter%2 == 0){	//a flag to decide what leds to turn on and off after turning off both pedestrian and car yellow leds
		LED_OFF(RED_PED);
		LED_ON(RED_CAR);
		LED_ON(GREEN_PED);
		while(counter3<20){			//delay for 5 sec
			Timer0_delayN(250);
			counter3++;
		}
		LED_OFF(RED_CAR);
		}
		else{					//after the yellow leds toggle for the second time so its time to get back to the normal mode
			LED_OFF(GREEN_PED);
			LED_ON(RED_PED);
			Green_flag =1;
			mode =0;
		}
		Red_flag_counter ++;
		}
		else{
			LED_ON(RED_CAR);		// in case for normal mode,turn on red car led and green pedestrian led
			LED_ON(GREEN_PED);
			while(counter3<20){
				Timer0_delayN(250);
				counter3++;
		}
			mode =0;
		}
		Yellow_flag=1;		//rise the yellow flag again
		Red_flag=0;
	}
	return TURE;


}
