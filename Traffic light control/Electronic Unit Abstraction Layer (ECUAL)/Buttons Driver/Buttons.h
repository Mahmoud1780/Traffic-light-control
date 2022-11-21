#ifndef BUTTON_H
#define BUTTON_H

#define Button_Port PORT_D
#define Button_Pin PIN2

void BUTTON_init(uint8_t ButtonPort,uint8_t ButtonPin);
void BUTTON_read(uint8_t ButtonPort,uint8_t ButtonPin,uint8_t *value);


#endif