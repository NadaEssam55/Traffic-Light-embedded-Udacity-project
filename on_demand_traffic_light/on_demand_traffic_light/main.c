/*
 * on_demand_traffic_light.c
 *
 * Created: 9/29/2022 5:30:46 PM
 * Author : Nada Essam
 */ 
#include <avr/io.h>
#include "APP/app.h"
STATE system_state;
int main(){
	app_init();
	while(1){
		system_state=app_start();
	}
}
////////////////////API_TEST
/*uint8 flag=0;
void EX_off(void){
	flag=1;
}
int main(void)
{
	EXTI_init();
	sei();
	
	//////////////////// DIO TEST
    Dio_init();
	Timer0_init();
	SetCallback_INT0(EX_off);
    while (1) 
    {
		//////////////////INTERRUPT TEST
		if(flag==0){
		LED_ON(YELLOW_CAR);	
		}
		else if(flag ==1){
		////////////////LED TEST
		LED_OFF(YELLOW_CAR);
		}
		///////////////////////TIMER TEST
		LED_TOGGLE(YELLOW_CAR);	
		Timer0_delayN(3000);		
}
}
*/
