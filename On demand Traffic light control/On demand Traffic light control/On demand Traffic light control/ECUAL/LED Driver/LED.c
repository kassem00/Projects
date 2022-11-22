/*
 * LED.c
 *
 * Created: 10/11/2022 11:52:07 ص
 *  Author: Kassem saber Lotfi Mohammed
 */
#include "LED.h"
uint8_t ERROR_ARRY[4];

void LED_init(uint8_t led_port,uint8_t led_pin){
//		uint8_t arr[8]={00000001,00000010,00000011,00000100,00000101,00000110,00000111,00001000};
		DIO_INIT(led_port,led_pin,OUTPUT);
}
void LEDON(uint8_t led_port,uint8_t led_pin){
		DIO_WRITE(led_port,led_pin,HIGH);
}
void LEDOFF(uint8_t led_port,uint8_t led_pin){
		DIO_WRITE(led_port,led_pin,LOW);
}
void LEDtoggle(uint8_t led_port,uint8_t led_pin){
		DIO_TOGGLE(led_port,led_pin);
}
void LED_TEST_FUN(){
	uint8_t led_port=A_PORT;
	uint8_t led_pin=0;
	LED_init(led_port,led_pin);
		switch (led_port){
			case A_PORT:
			if (DDRA!=(1<<led_pin)){
				ERROR_ARRY[LED_initialize_ERORR]=1;
			}break;
			case B_PORT:
			if (DDRB!=(1<<led_pin)){
				ERROR_ARRY[LED_initialize_ERORR]=1;
			}break;
			case C_PORT:
			if (DDRC!=(1<<led_pin))
			{
				ERROR_ARRY[LED_initialize_ERORR]=1;
			}break;
			case D_PORT:
		if (DDRD!=(1<<led_pin))	{
			ERROR_ARRY[LED_initialize_ERORR]=1;}
			break;}
		LEDON(led_port,led_pin);
		switch (led_port)
		{
			case A_PORT:
			if (PORTA!=(1<<led_pin)){
				ERROR_ARRY[LED_ON_ERROR]=1;
			}break;
			case B_PORT:
			if (PORTB!=(1<<led_pin)){
				ERROR_ARRY[LED_ON_ERROR]=1;}
			break;
			case C_PORT:
			if (PORTC!=(1<<led_pin)){
				ERROR_ARRY[LED_ON_ERROR]=1;
			}break;
			case D_PORT:
			if (PORTD!=(1<<led_pin)){
				ERROR_ARRY[LED_ON_ERROR]=1;
			}break;}
		LEDOFF(led_port,led_pin);
		switch (led_port){
			case A_PORT:
			if (PORTA==(1<<led_pin)){
				ERROR_ARRY[LED_OFF_ERROR]=1;
			}
			break;
			case B_PORT:
			if (PORTB==(1<<led_pin)){
				ERROR_ARRY[LED_OFF_ERROR]=1;}
			break;
			case C_PORT:
			if (PORTC==(1<<led_pin))	{
				ERROR_ARRY[LED_OFF_ERROR]=1;
			}break;
			case D_PORT:
			if (PORTD==(1<<led_pin))
			{
				ERROR_ARRY[LED_OFF_ERROR]=1;
			}break;
		}
		/*after the of the pin must be low so
		 i test it by check if it high after toggling
		*/LEDtoggle(led_port,led_pin);
		switch (led_port){
		case A_PORT:
		if (PORTA!=(1<<led_pin)){
			ERROR_ARRY[LED_TOGGLE_ERROR]=1;
	}
		break;
		case B_PORT:
		if (PORTB!=(1<<led_pin)){
			ERROR_ARRY[LED_TOGGLE_ERROR]=1;
		}
		break;
		case C_PORT:
		if (PORTC!=(1<<led_pin)){
			ERROR_ARRY[LED_TOGGLE_ERROR]=1;
		}
		break;
		case D_PORT:
		if (PORTD!=(1<<led_pin)){
			ERROR_ARRY[LED_TOGGLE_ERROR]=1;
		}break;}
	for (int i=0;i<4;i++){
	ACTIVE_H(DDRC,i);
	if (ERROR_ARRY[i]==1){
		ACTIVE_H(PORTC,i);
	}else{
		ACTIVE_L(PORTC,i);}}}