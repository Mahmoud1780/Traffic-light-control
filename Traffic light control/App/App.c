#include <stdio.h>
#include "App.h"


uint8_t Car_LED = green,Car_prev_LED = yellow, mode = normal;
void APP_init(void){
	LED_init(LED_Car_Port,LED_Car_red_pin);
	LED_init(LED_Car_Port,LED_Car_Yellow_pin);
	LED_init(LED_Car_Port,LED_Car_Green_Pin);
	
	LED_init(LED_Pedestrian_Port,LED_Pedestrian_red_pin);
	LED_init(LED_Pedestrian_Port,LED_Pedestrian_Yellow_pin);
	LED_init(LED_Pedestrian_Port,LED_Pedestrian_Green_Pin);
	
	TIMER0_init();
	
	BUTTON_init(Button_Port,Button_Pin);
	
	sei();
	RISING_EDGE_SETUP();
	SETUP_INT0 ();
	
}
void APP_start(void){
	
	if (mode == normal || Car_LED == green || Car_LED == yellow){
		if (mode == Pedestrian){
			Car_LED = yellow;
		}
		
		LED_off(LED_Pedestrian_Port,LED_Pedestrian_red_pin);
		LED_off(LED_Pedestrian_Port,LED_Pedestrian_Yellow_pin);
		LED_off(LED_Pedestrian_Port,LED_Pedestrian_Green_Pin);
		
		switch(Car_LED){
						
			case yellow :
			if (mode == Pedestrian){
				if (Car_prev_LED!= red){
					LED_on(LED_Pedestrian_Port,LED_Pedestrian_red_pin);
					for (uint8_t i;i<5;i++){
						LED_on(LED_Car_Port,LED_Car_Yellow_pin);
						LED_on(LED_Pedestrian_Port,LED_Pedestrian_Yellow_pin);
						TIMER0_delay(390);
						LED_off(LED_Car_Port,LED_Car_Yellow_pin);
						LED_off(LED_Pedestrian_Port,LED_Pedestrian_Yellow_pin);
						TIMER0_delay(190);
						LED_on(LED_Car_Port,LED_Car_Yellow_pin);
						LED_on(LED_Pedestrian_Port,LED_Pedestrian_Yellow_pin);
						TIMER0_delay(390);
					}
				}
				Car_prev_LED = yellow;
				Car_LED = red;
				LED_on(LED_Car_Port,LED_Car_red_pin);
			}
			else{
				for (uint8_t i = 0 ; i<5;i++){
					LED_on(LED_Car_Port,LED_Car_Yellow_pin);
					TIMER0_delay(380);
					LED_off(LED_Car_Port,LED_Car_Yellow_pin);
					TIMER0_delay(180);
					LED_on(LED_Car_Port,LED_Car_Yellow_pin);
					TIMER0_delay (380);
					if (mode == Pedestrian){
						Car_prev_LED = yellow;
						break;
					}
				}
			}
			LED_off(LED_Car_Port,LED_Car_Yellow_pin);
			LED_off(LED_Pedestrian_Port,LED_Pedestrian_Yellow_pin);
			if (Car_prev_LED == red){
				Car_LED = green;
				Car_prev_LED = yellow;
			}
			else if (Car_prev_LED == green)
			{
				Car_LED = red;
				Car_prev_LED = yellow;
			}
			break;
			
			case red :
			LED_on(LED_Car_Port,LED_Car_red_pin);
			LED_off(LED_Car_Port,LED_Car_Yellow_pin);
			LED_off(LED_Car_Port,LED_Car_Green_Pin);
			for (uint8_t i=0; i<50 ;i++)
			{
				TIMER0_delay(68);
				if (mode == Pedestrian){
					break;
				}
			}
			Car_prev_LED = red;
			Car_LED = yellow;
			break;
			
			
			case green :
			LED_on(LED_Car_Port,LED_Car_Green_Pin);
			LED_off(LED_Car_Port,LED_Car_red_pin);
			LED_off(LED_Car_Port,LED_Car_Yellow_pin);
			
			
			for (uint8_t i; i<150;i++){
				TIMER0_delay(68);
				if(mode == Pedestrian) {
					break;
				}
			}
			
			Car_prev_LED = green;
			Car_LED = yellow;
			break;
			
			default:
			Car_LED = red;
			Car_prev_LED = yellow;
			break;
			
		}

	}
	else {
		LED_off (LED_Pedestrian_Port,LED_Pedestrian_red_pin);
		LED_off (LED_Pedestrian_Port,LED_Pedestrian_Yellow_pin);
		LED_on (LED_Pedestrian_Port,LED_Pedestrian_Green_Pin);
		
		LED_on(LED_Car_Port,LED_Car_red_pin);
		LED_off(LED_Car_Port,LED_Car_Yellow_pin);
		LED_off(LED_Car_Port,LED_Car_Green_Pin);
		
		TIMER0_delay(5000);
		
		LED_off(LED_Car_Port,LED_Car_red_pin);
		
		for (uint8_t i;i<5;i++){
			LED_on(LED_Car_Port,LED_Car_Yellow_pin);
			LED_on(LED_Pedestrian_Port,LED_Pedestrian_Yellow_pin);
			TIMER0_delay(390);
			LED_off(LED_Car_Port,LED_Car_Yellow_pin);
			LED_off(LED_Pedestrian_Port,LED_Pedestrian_Yellow_pin);
			TIMER0_delay(190);
			LED_on(LED_Car_Port,LED_Car_Yellow_pin);
			LED_on(LED_Pedestrian_Port,LED_Pedestrian_Yellow_pin);
			TIMER0_delay(390);
		}
		LED_off(LED_Car_Port,LED_Car_Yellow_pin);
		LED_off(LED_Pedestrian_Port,LED_Pedestrian_Yellow_pin);
		
		LED_on(LED_Pedestrian_Port, LED_Pedestrian_red_pin);
		
		mode = normal;
		Car_LED = green;
		Car_prev_LED = yellow;
	}
}
ISR(EXT_INT_0){
	mode = Pedestrian;
}
