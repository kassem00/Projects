/*
 * LED.h
 *
 * Created: 07/11/2022 12:18:04 م
 *  Author: Fannan
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO Driver/DIO.h"//UPER LYER CALL LOWER LAYER
void LED_init(uint8_t led_port,uint8_t led_pin);
void LEDON(uint8_t led_port,uint8_t led_pin);
void LEDOFF(uint8_t led_port,uint8_t led_pin);
void LEDtoggle(uint8_t led_port,uint8_t led_pin);

#endif /* LED_H_ */