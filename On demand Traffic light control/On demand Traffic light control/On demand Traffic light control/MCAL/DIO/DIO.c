/*
 * DIO.c
 *
 * Created: 10/11/2022 11:52:07 ص
 *  Author: Kassem saber Lotfi Mohammed
 */
#include "DIO.h"
uint8_t ERROR_ARRY[4];
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
		default:
		ERROR_ARRY[DIO_initialize_ERROR]=1;
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
		default:
		ERROR_ARRY[DIO_initialize_ERROR]=1;
	}

}else
{
ERROR_ARRY[DIO_initialize_ERROR]=1;
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
		break;
		default:
		ERROR_ARRY[DIO_WRITER_ERROR]=1;
		}

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
			default:
			ERROR_ARRY[DIO_WRITER_ERROR]=1;
	}

}else
{
	
		ERROR_ARRY[DIO_WRITER_ERROR]=1;
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
		default:
		ERROR_ARRY[DIO_TOGGLE_ERROR]=1;
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
			break;
			default:
			ERROR_ARRY[DIO_READ_ERROR]=1;
		}
}

void DIO_test_fun(){
	uint8_t valu;
	DIO_INIT(A_PORT,0,OUTPUT);
		DIO_INIT(A_PORT,1,INPUT);
		DIO_WRITE(A_PORT,0,HIGH);
		DIO_WRITE(A_PORT,0,LOW);
		DIO_TOGGLE(A_PORT,0);
		DIO_READ(A_PORT,1,&valu);
		
	for (int i=0;i<4;i++)
	{
		ACTIVE_H(DDRC,i);
	}
	for (int i=0;i<4;i++)
	{
		if (ERROR_ARRY[i]==1)
		{
			ACTIVE_H(PORTC,i);
		}else
		{
			ACTIVE_L(PORTC,i);
		}

	}
}