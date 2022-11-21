#ifndef DIO_H
#define DIO_H
#include "..\..\Service Layer\BITS.h"
#include "..\..\Service Layer\Registers.h"
#include "..\..\Service Layer\Types.h"

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

#define LOW 0
#define HIGH 1

#define IN 0
#define OUT 1

void DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction);
void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value); 
void DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t* value); 
void DIO_toggle(uint8_t portNumber, uint8_t pinNumber); 


#endif 