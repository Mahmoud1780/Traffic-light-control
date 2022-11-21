#ifndef LED_H
#define LED_H
#include "..\..\Microcontroller Abstraction Layer (MCAL)/DIO/DIO.h"

#define LED_Car_Port			   PORT_A
#define LED_Car_red_pin            PIN0
#define LED_Car_Yellow_pin         PIN1
#define LED_Car_Green_Pin          PIN2

#define LED_Pedestrian_Port        PORT_B
#define LED_Pedestrian_red_pin     PIN0
#define LED_Pedestrian_Yellow_pin  PIN1
#define LED_Pedestrian_Green_Pin   PIN2

void LED_init(uint8_t LED_Port,uint8_t LED_Pin);
void LED_on(uint8_t LED_Port,uint8_t LED_Pin);
void LED_off(uint8_t LED_Port,uint8_t LED_Pin);
void LED_toggle(uint8_t LED_Port,uint8_t LED_Pin);


#endif