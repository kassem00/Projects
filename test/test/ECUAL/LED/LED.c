/*
 * LED.c
 *
 * Created: 07/11/2022 12:17:11 م
 *  Author: Fannan
 */ 
#include "LED.h"

void LED_init(uint8_t led_port,uint8_t led_pin){
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

