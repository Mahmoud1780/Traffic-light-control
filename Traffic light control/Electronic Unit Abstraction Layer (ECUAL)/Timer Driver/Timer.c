#include <stdio.h>
#include <math.h>
#include "Timer.h"
#include "..\..\Service Layer\BITS.h"

void TIMER0_init(){
	TCCR0 = Normal ; 
}

void TIMER0_delay (uint16_t MILL_SEC){
	uint16_t Num_Over_Flow , Time_Start, Over_flow_Counter = 0;
	double Timer_Max_delay,Timer_tick;
	TCCR0 |= Timer0_Pre_256;
	Timer_tick = 256.0/1000.0; // ms   //at 256 prescaler
	Timer_Max_delay = Timer_tick * 256;
	if (Timer_Max_delay < MILL_SEC){
		Num_Over_Flow = ceil ((double)MILL_SEC/Timer_Max_delay);
		Time_Start = 256 - ((double)MILL_SEC/Timer_tick)/Num_Over_Flow;
	}
	else {
		Time_Start = (Timer_Max_delay-MILL_SEC)/Timer_tick;
		Num_Over_Flow =1;
	}
	TCNT0 = Time_Start;
	while (Over_flow_Counter < Num_Over_Flow){
		while (READ_BIT (TIFR,0)==0);
		SET_BIT (TIFR,0);
		Over_flow_Counter++;
			
		
	}
	TCCR0 = TimerOFF;
}
