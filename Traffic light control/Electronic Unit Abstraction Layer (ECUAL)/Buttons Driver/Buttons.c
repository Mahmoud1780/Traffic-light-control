#include <stdio.h>
#include "Buttons.h"

void BUTTON_init(uint8_t ButtonPort,uint8_t ButtonPin){
		DIO_init(ButtonPort,ButtonPin,IN);

}

void BUTTON_read(uint8_t ButtonPort,uint8_t ButtonPin,uint8_t *value){
	DIO_read(ButtonPort,ButtonPin,value);
}
