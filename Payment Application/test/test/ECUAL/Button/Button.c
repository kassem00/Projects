/*
 * Button.c
 *
 * Created: 07/11/2022 02:17:49 م
 *  Author: Fannan
 */ 
#include "Button.h"


void BUT_init(uint8_t B_port,uint8_t B_pin){
DIO_INIT(B_port,B_pin,INPUT);
}
void BUT_state(uint8_t B_port,uint8_t B_pin,uint8_t *val){
	DIO_READ(B_port,B_pin,val);
}