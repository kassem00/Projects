/*
 * test.c
 *
 * Created: 06/11/2022 01:58:42 م
 * Author : kassem 
 */ 
/************************************************************************/
/*practice makes everything perfect                                                                */
/************************************************************************/
#define F_CPU 1000000UL
#define NUMBER_OF_OVER_FLOW 2000
//#include <avr/io.h>
//#include <util/delay.h>

#include "ECUAL/LED/LED.h"
#include "ECUAL/Button/Button.h"
#include "Utilites/Interrupt.h"
//#include <avr/interrupt.h>
uint8_t lednum;
int main(void)
{
	LED_init(A_PORT,0);
	LED_init(A_PORT,1);
	LED_init(A_PORT,2);
	sei();
	
	ACTIVE_H(MCUCR,0);
	ACTIVE_H(MCUCR,1);
	
	
	ACTIVE_H(GICR,6);//3.
	lednum=0;
	while (1)
	{
			switch (lednum)
			{	
				case 0:
				LEDOFF(A_PORT,0);
				LEDOFF(A_PORT,1);
				LEDOFF(A_PORT,2);
				break;
				case 1:
				LEDON(A_PORT,0);
				break;
				case 2:
				LEDON(A_PORT,1);
				break;
				case 3:
				LEDON(A_PORT,2);
				break;
				default:
				/* Your code here */
				break;
			}
	};
}
ISR(EXT_INT_0){
	if (lednum<3)
	{
		lednum++;
		
}else
{
	lednum=0;
}
	}
/************************************************************************
DDRA =0b00000001;

// Replace with your application code 
while(1){
	if(PINB==0b00000001){
		PORTA|=(1<<0);//set pin A0 to high
		_delay_ms(100);
		PORTA&=~(1<<0);//set pin A0 to low
		_delay_ms(100);
}
}   




//320ms
LED_init(A_PORT,0);
	TCCR0=0X00;//Normal mode 
	//time set intial value
	TCNT0=0X00;
	//TIMMER START
		**
	*512ms 
	**   
    while(1){
		TCCR0 |= (1<<0); //set no prescaler
		while((TIFR &(1<<0))==0);//busy wait	
		}
		
		TIFR|= (1<<0);//clear overflow 
		TCCR0 =0x00;//timer stop
		
************************************************************************/
/************************************************************************/
/* 
//536ms timer

#define F_CPU 1000000UL
#define NUMBER_OF_OVER_FLOW 2000
//#include <avr/io.h>
//#include <util/delay.h>

#include "ECUAL/LED/LED.h"
#include "ECUAL/Button/Button.h"

int main(void)
{
	unsigned int overflow_counter=0;
	LED_init(A_PORT,0);
	TCCR0=0X00;//Normal mode
	//time set intial value
	TCNT0=0X00;//TIMMER START
	while(1){
		//2. led toggle
		LEDtoggle(A_PORT,0);
		//3.delay 512ms
		//timer start -> setting the clock source
		TCCR0 |= (1<<0); //set no prescaler
		while (overflow_counter< NUMBER_OF_OVER_FLOW)
		{
			while((TIFR &(1<<0))==0);//busy wait
			
			TIFR|= (1<<0);//clear overflow FLAG
			overflow_counter++;
		}
		
		
		
		overflow_counter=0;
		TCCR0 =0x00;//timer stop
	}
}

                                                                     */
/************************************************************************/