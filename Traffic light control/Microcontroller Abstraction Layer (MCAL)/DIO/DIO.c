#include <stdio.h>
#include "dio.h"

void DIO_init(uint8_t Port_Number, uint8_t Pin_Number, uint8_t Direction)
{
	switch(Port_Number){
		case PORT_A:
			if(Direction == IN){
				CLEAR_BIT(DDRA,Pin_Number);
			}else if (Direction == OUT){
				SET_BIT(DDRA,Pin_Number);
			}
			break;
		case PORT_B:
			if(Direction == IN){
				CLEAR_BIT(DDRB,Pin_Number);
			}else if (Direction == OUT){
				SET_BIT(DDRB,Pin_Number);
			}
			break;
			
		case PORT_C:
			if(Direction == IN){
				CLEAR_BIT(DDRC,Pin_Number);
			}else if (Direction == OUT){
				SET_BIT(DDRC,Pin_Number);
			}
			break;
		case PORT_D:
			if(Direction == IN){
				CLEAR_BIT(DDRD,Pin_Number);
			}else if (Direction == OUT){
				SET_BIT(DDRD,Pin_Number);
			}
			break;
	}
}
void DIO_read(uint8_t Port_Number, uint8_t Pin_Number, uint8_t* value)
{
	switch(Port_Number){
		case PORT_A:
			*value = READ_BIT(PINA,Pin_Number);
		break;
		case PORT_B:
			*value = READ_BIT(PINB,Pin_Number);
		break;
		case PORT_C:
			*value = READ_BIT(PINC,Pin_Number);
		break;
		case PORT_D:
			*value = READ_BIT(PIND,Pin_Number);
		break;
	}
}
void DIO_write(uint8_t Port_Number, uint8_t Pin_Number, uint8_t value)
{
	switch(Port_Number){
		case PORT_A:
		if(value == LOW){
			CLEAR_BIT(PORTA,Pin_Number);
			}else if (value == HIGH){
			SET_BIT(PORTA,Pin_Number);
			}
		break;
		
		case PORT_B:
		if(value == LOW){
			CLEAR_BIT(PORTB,Pin_Number);
			}else if (value == HIGH){
			SET_BIT(PORTB,Pin_Number);
			}
		break;
		
		case PORT_C:
		if(value == LOW){
			CLEAR_BIT(PORTC,Pin_Number);
			}else if (value == HIGH){
			SET_BIT(PORTC,Pin_Number);
			}
		break;
		
		case PORT_D:
		if(value == LOW){
			CLEAR_BIT(PORTD,Pin_Number);
			}else if (value == HIGH){
			SET_BIT(PORTD,Pin_Number);
			}
		break;
	}
}
void DIO_toggle(uint8_t Port_Number, uint8_t Pin_Number)
{
	switch(Port_Number){
		case PORT_A:
		TOGGLE_BIT(PORTA,Pin_Number);
		break;
		case PORT_B:
		TOGGLE_BIT(PORTB,Pin_Number);
		break;
		case PORT_C:
		TOGGLE_BIT(PORTC,Pin_Number);
		break;
		case PORT_D:
		TOGGLE_BIT(PORTD,Pin_Number);
		break;
	}
}