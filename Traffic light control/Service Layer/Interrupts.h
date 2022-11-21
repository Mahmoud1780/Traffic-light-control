#ifndef INTERRUPTS_H
#define INTERRUPTS_H
#include "registers.h"
#include "Types.h"

#define EXT_INT_0 __vector_1
#define EXT_INT_1 __vector_2

#define sei()  __asm__ __volatile__ ("sei" ::: "memory")
#define cli()  __asm__ __volatile__ ("cli" ::: "memory")

#define RISING_EDGE_SETUP() MCUCR|= (1<<ISC01) | (1<<ISC00)

#define SETUP_INT0() GICR|=(1<<6)

#define ISR(INT_VECT) \
void INT_VECT(void) __attribute__ ((signal,used)); \
void INT_VECT(void)

#endif 