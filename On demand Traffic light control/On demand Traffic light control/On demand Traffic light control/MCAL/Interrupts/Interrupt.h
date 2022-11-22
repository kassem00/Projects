/*
 * Interrupt.h
 *
 * Created: 10/11/2022 11:52:07 ص
 *  Author: Kassem saber Lotfi Mohammed
 */
//#include <avr/interrupt.h>
#ifndef INTERRUPT_H_
#define INTERRUPT_H_
#include "../../Utilities/register.h"

#define EXT_INT_0 __vector_1
// #define EXT_INT_1 __vector_2
#define sei()  __asm__ __volatile__ ("sei" ::: "memory")
#define ISR(INT_VECT)\
void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)/*
to activate external intrubt
you must enable glouble intruders and enable external intrubt
*/



#endif /* INTERRUPT_H_ */