#include <stdio.h>
#include "LED.h"
#include "..\..\Microcontroller Abstraction Layer (MCAL)\DIO\DIO.c"

void LED_init(uint8_t LED_Port,uint8_t LED_Pin){
	DIO_init(LED_Port,LED_Pin,OUT);
}
void LED_on(uint8_t LED_Port,uint8_t LED_Pin){
	DIO_write(LED_Port,LED_Pin,HIGH);
}
void LED_off(uint8_t LED_Port,uint8_t LED_Pin){
	DIO_write(LED_Port,LED_Pin,LOW);
}
void LED_toggle(uint8_t LED_Port,uint8_t LED_Pin){
	DIO_toggle(LED_Port,LED_Pin);
}