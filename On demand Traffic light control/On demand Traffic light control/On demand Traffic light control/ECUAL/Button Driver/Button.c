/*
 * Button.c
 *
 * Created: 10/11/2022 11:52:07 ص
 *  Author: Kassem saber Lotfi Mohammed
 */
#include "Button.h"

uint8_t ERROR_ARRY[2];
void BUT_init(uint8_t B_port,uint8_t B_pin){
DIO_INIT(B_port,B_pin,INPUT);
}
void BUT_state(uint8_t B_port,uint8_t B_pin,uint8_t *val){
	DIO_READ(B_port,B_pin,val);
}
void but_fun_test(){
	uint8_t but_port=A_PORT;
	uint8_t but_pin=0;
	BUT_init(but_port,but_pin);
	uint8_t valu;
	switch (but_port){
		case A_PORT:
		if (DDRA==(1<<but_pin)){
			ERROR_ARRY[initialize_ERROR]=1;
		}break;
		case B_PORT:
		if (DDRB==(1<<but_pin)){
			ERROR_ARRY[initialize_ERROR]=1;
		}break;
		case C_PORT:
		if (DDRC==(1<<but_pin))
		{
			ERROR_ARRY[initialize_ERROR]=1;
		}break;
		case D_PORT:
		if (DDRD==(1<<but_pin))	{
		ERROR_ARRY[initialize_ERROR]=1;
		}
	break;}
	BUT_state(but_port,but_pin,&valu);
	switch (but_port){//test it When input is high
		case A_PORT:
		if (PINA!=(1<<but_pin)){
			ERROR_ARRY[STATE_ERROR]=1;
		}break;
		case B_PORT:
		if (PINB!=(1<<but_pin)){
		ERROR_ARRY[STATE_ERROR]=1;}
		break;
		case C_PORT:
		if (PINC!=(1<<but_pin)){
			ERROR_ARRY[STATE_ERROR]=1;
		}break;
		case D_PORT:
		if (PIND!=(1<<but_pin)){
			ERROR_ARRY[STATE_ERROR]=1;
		}break;}
		for (int i=0;i<2;i++){
			ACTIVE_H(DDRC,i);
			if (ERROR_ARRY[i]==1){
				ACTIVE_H(PORTC,i);
				}else{
			ACTIVE_L(PORTC,i);}
			}
}