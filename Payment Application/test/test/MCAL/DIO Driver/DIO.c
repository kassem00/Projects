/*
 * DIO.c
 *
 * Created: 06/11/2022 07:29:45 م
 *  Author: Fannan
 */ 
#include "DIO.h"
void DIO_INIT(uint8_t port_num, uint8_t pin_num,uint8_t direct){//INitializ direction
if (direct==OUTPUT)
{
	switch (port_num)
	{
		case A_PORT:
		ACTIVE_H(DDRA,pin_num);
		break;
		case B_PORT:
		ACTIVE_H(DDRB,pin_num);
		break;
		case C_PORT:
 		ACTIVE_H(DDRC,pin_num);
		break;
		case D_PORT:
		ACTIVE_H(DDRD,pin_num);
		break;
	}

}else if (direct==INPUT)
{
	switch (port_num)
	{
		case A_PORT:
		ACTIVE_L(DDRA,pin_num);
		break;
		case B_PORT:
		ACTIVE_L(DDRB,pin_num);
		break;
		case C_PORT:
		ACTIVE_L(DDRC,pin_num);
		break;
		case D_PORT:
		ACTIVE_L(DDRD,pin_num);
		break;
	}

}else
{
	//error handeling 
}
}
void DIO_WRITE(uint8_t port_num, uint8_t pin_num,uint8_t val_in){//write from dio
if (val_in==HIGH)
{
	switch (port_num){
		case A_PORT:
		ACTIVE_H(PORTA,pin_num);
		break;
		case B_PORT:
		ACTIVE_H(PORTB,pin_num);
		break;
		case C_PORT:
		ACTIVE_H(PORTC,pin_num);
		break;
		case D_PORT:
		ACTIVE_H(PORTD,pin_num);
		break;}

}else if (val_in==LOW)
{
	switch (port_num)
	{
		case A_PORT:
		ACTIVE_L(PORTA,pin_num);
		break;
		case B_PORT:
		ACTIVE_L(PORTB,pin_num);
		break;
		case C_PORT:
		ACTIVE_L(PORTC,pin_num);
		break;
		case D_PORT:
		ACTIVE_L(PORTD,pin_num);
		break;
	}

}else
{
	//error handeling
}

}
void DIO_TOGGLE(uint8_t port_num, uint8_t pin_num){
		switch (port_num){
			case A_PORT:
			TOGGL(PORTA,pin_num);
			break;
			case B_PORT:
			TOGGL(PORTB,pin_num);
			break;
			case C_PORT:
			TOGGL(PORTC,pin_num);
			break;
			case D_PORT:
			TOGGL(PORTD,pin_num);
		break;
		}
}

void DIO_READ(uint8_t port_num, uint8_t pin_num,uint8_t *val){
	
		switch (port_num){
			case A_PORT:
			*val= READ(PINA,pin_num);
			break;
			case B_PORT:
			*val= READ(PINB,pin_num);
			break;
			case C_PORT:
			*val= READ(PINC,pin_num);
			break;
			case D_PORT:
			*val= READ(PIND,pin_num);
		break;}
}
