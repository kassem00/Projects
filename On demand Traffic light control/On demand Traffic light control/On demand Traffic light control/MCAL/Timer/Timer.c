/*
 * Timer.c
 *
 * Created: 10/11/2022 11:52:07 ص
 *  Author: Kassem saber Lotfi Mohammed
 */

#include "Timer.h"
uint8_t ERROR_ARRY[4];
	void timer_inti(){

		TCCR0=0x00;//1.Normal mode
		if (TCCR0==0b00000000)
		{
			ERROR_ARRY[initialize_ERORR]=0;
	}else
	{
		ERROR_ARRY[initialize_ERORR]=1;
	}
}


	void timer_delay(uint8_t T_S){
		TCNT0 = 0xF6;//set timerset initial value
		T_S=(T_S*4);
			//set prescaler to 1024
		ACTIVE_H(TCCR0,0);
		ACTIVE_H(TCCR0,2);
		uint8_t overflow_counter=0;
	while (overflow_counter< T_S){
		while((TIFR &(1<<0))==0);//busy wait
		
		TIFR|= (1<<0);//clear overflow FLAG
		overflow_counter++;
	}
	if (overflow_counter==T_S)
	{
	ERROR_ARRY[TIMER_DELAY_ERROR]=0;

}else
{
	ERROR_ARRY[TIMER_DELAY_ERROR]=1;
}
	overflow_counter=0;
	TCCR0 =0x00;//timer stop
}
void LED_blink_delay(uint8_t led_port,uint8_t led_pin,uint8_t T_S){
		TCNT0 = 0xF6;
		T_S=T_S*4;
		ACTIVE_H(TCCR0,0);//set prescaler to 1024
		ACTIVE_H(TCCR0,2);
		uint8_t overflow_counter=0;

	//timer start -> setting the clock source
	
	while (overflow_counter< T_S){
		
		while((TIFR &(1<<0))==0);//busy wait
		
		TIFR|= (1<<0);//clear overflow FLAG
		overflow_counter++;
		LEDtoggle(led_port,led_pin);
	};
	if (overflow_counter==T_S)
	{
		ERROR_ARRY[TIMER_DELAY_BLINK]=0;

	}else
	{
		ERROR_ARRY[TIMER_DELAY_BLINK]=1;
	}
	overflow_counter=0;
	TCCR0 =0x00;//timer stop
	LEDOFF(led_port,led_pin);
}

void two_LED_blink_delay(uint8_t led_port1,uint8_t led_pin1,uint8_t led_port2,uint8_t led_pin2,uint8_t T_S){
	TCNT0 = 0xF6;
	T_S=T_S*4;
	ACTIVE_H(TCCR0,0);//set prescaler to 1024
	ACTIVE_H(TCCR0,2);
	uint8_t overflow_counter=0;

	//timer start -> setting the clock source
	
	while (overflow_counter< T_S){
		
		while((TIFR &(1<<0))==0);//busy wait
		
		TIFR|= (1<<0);//clear overflow FLAG
		overflow_counter++;
		LEDtoggle(led_port1,led_pin1);
		LEDtoggle(led_port2,led_pin2);
	};
	if (overflow_counter==T_S)
	{
		ERROR_ARRY[TWO_TIMER_DELAY_BLINK]=0;

	}else
	{
		ERROR_ARRY[TWO_TIMER_DELAY_BLINK]=1;
	}
	overflow_counter=0;
	TCCR0 =0x00;//timer stop
	LEDOFF(led_port1,led_pin1);
	LEDOFF(led_port2,led_pin2);
}
void timer_test_fun(){
	timer_inti();
	timer_delay(1);
LED_blink_delay(A_PORT,0,1);
two_LED_blink_delay(A_PORT,0,A_PORT,1,1);
	for (int i=0;i<4;i++)
	{
		DIO_INIT(C_PORT,i,OUTPUT);
	}
	for (int i=0;i<4;i++)
	{
		if (ERROR_ARRY[i]==1)
		{
	LEDON(C_PORT,i);
	}else
	{
	LEDOFF(C_PORT,i);
	}

	}
}
