#ifndef TIMER_H
#define TIMER_H

#include "..\..\Service Layer\Registers.h"

#define Normal   0x00

#define TimerOFF			    0x00
#define NoPrescalar		        0x01
#define Timer0_Pre_8            0x02
#define Timer0_Pre_64           0x03
#define Timer0_Pre_256          0x04
#define Timer0_Pre_1024         0x05

void TIMER0_init();
void TIMER0_delay (uint16_t MILL_SEC);

#endif