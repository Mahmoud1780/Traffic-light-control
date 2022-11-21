/*
 * Traffic light control.c
 *
 * Created: 10/13/2022 9:37:11 PM
 * Author : DELL
 */ 

#include <avr/io.h>

#include "App/App.c"


void main(void)
{
	APP_init();

    while (1) 
    {
		APP_start();
    }
}

/*int main(void){
	BUTTON_init(Button_Port,Button_Pin);
	LED_init(LED_Car_Port,LED_Car_Green_Pin);
	LED_init(LED_Pedestrian_Port,LED_Pedestrian_Green_Pin);
	TIMER0_init();
	uint8_t value;
	while(1){
	BUTTON_read(Button_Port,Button_Pin,&value);
	if(value==HIGH){
	LED_toggle(LED_Car_Port,LED_Car_Green_Pin);
	LED_on(LED_Pedestrian_Port,LED_Pedestrian_Green_Pin);
	TIMER0_delay(500);
	LED_off(LED_Pedestrian_Port,LED_Pedestrian_Green_Pin);
	TIMER0_delay(500);
	
	}else{
	LED_on(LED_Car_Port,LED_Car_Green_Pin);
	}
	
	}
	}
*/
/*
int main(void)
{
	DDRB = 0xFF;
	PORTB = 1 << PORTB5;

	while (1)
	{
	}
}*/