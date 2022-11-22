/*
 * Interrupt.h
 *
 * Created: 09/11/2022 01:07:30 م
 *  Author: Fannan
 */ 

//#include <avr/interrupt.h>
#ifndef INTERRUPT_H_
#define INTERRUPT_H_


 #define EXT_INT_0 __vector_1
// #define EXT_INT_1 __vector_2

#define sei()  __asm__ __volatile__ ("sei" ::: "memory")
#define cli()  __asm__ __volatile__ ("cli" ::: "memory")

#define ISR(INT_VECT)\
void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)
/*
to activate external intrubt
you must enable glouble intrubte and enable external intrubt
*/

#endif /* INTERRUPT_H_ */