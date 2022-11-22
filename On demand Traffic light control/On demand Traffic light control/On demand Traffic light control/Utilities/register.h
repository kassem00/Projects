/*
 * register.h
 *
 * Created: 10/11/2022 11:52:07 ص
 *  Author: Kassem saber Lotfi Mohammed
 */
/************************************************************************/
/*						 DIO REGISTER                                                                     */
/************************************************************************/
#ifndef REGISTER_H_

#define REGISTER_H_
#include "type.h"
//PORTA
#define	PORTA *((volatile uint8_t*)0X3B)
#define	DDRA *((volatile uint8_t*)0X3A)
#define	PINA *((volatile uint8_t*)0X39)
//PORTB
#define	PORTB *((volatile uint8_t*)0X38)
#define	DDRB *((volatile uint8_t*)0X37)
#define	PINB *((volatile uint8_t*)0X36)
//PORTC
#define	PORTC *((volatile uint8_t*)0X35)
#define	DDRC *((volatile uint8_t*)0X34)
#define	PINC *((volatile uint8_t*)0X33)
//PORTD
#define	PORTD *((volatile uint8_t*)0X32)
#define	DDRD *((volatile uint8_t*)0X31)
#define	PIND TCCR0

/************************************************************************/
/*							Timer register                              */
/************************************************************************/


#define TCCR0 *((volatile uint8_t*)0X53)/*
Timer/Counter Control Register
*/
#define TCNT0 *((volatile uint8_t*)0X52)
//timer flag
#define TIFR *((volatile uint8_t*)0X58)

//Configer watch do timer 
#define WDTCR *((volatile uint8_t*)0X41) 
/************************************************************************/
/*							interrupts REGISTER                         */
/************************************************************************/


#define SREG *((volatile uint8_t*)(0x5F))
/*
Enable GLoable Interrupt 
by set bit number 7 in this register 
 1=enable/ 0=disable  
*/
#define GIFR  *((volatile uint8_t*)(0x5A))/*
GIFR Interrupt flag
*/
#define GICR  *((volatile uint8_t*)(0x5B))/*
Enable Interrupt 
General Interrupt Control Register
*/
#define MCUCR  *((volatile uint8_t*)(0x55))/*
MCUCR – MCU Control Register
The MCU Control Register contains
 control bits for interrupt sense control 
 and general MCU functions.
*/
#endif /* REGISTER_H_ */	