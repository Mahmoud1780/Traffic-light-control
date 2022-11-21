#ifndef APP_H
#define APP_H

#include "..\Electronic Unit Abstraction Layer (ECUAL)\LED Driver\LED.c"
#include "..\Electronic Unit Abstraction Layer (ECUAL)\Timer Driver\Timer.c"
#include "..\Electronic Unit Abstraction Layer (ECUAL)\Buttons Driver\Buttons.c"
#include "..\Service Layer\Interrupts.h"
#include "..\Service Layer\Registers.h"
#include "..\Service Layer\Types.h"

#define  normal      0
#define  Pedestrian  1

#define  red		 0
#define  yellow		 1
#define  green		 2

void APP_init(void);
void APP_start(void);

#endif