/*
 * LED.h
 *
 * Created: 10/11/2022 11:52:07 ص
 *  Author: Kassem saber Lotfi Mohammed
 */

#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO/DIO.h"//UPER LYER CALL LOWER LAYER

typedef enum EN_LED_ERROR{
	LED_initialize_ERORR,LED_ON_ERROR,LED_OFF_ERROR,LED_TOGGLE_ERROR
}EN_LED_ERROR;
void LED_init(uint8_t led_port,uint8_t led_pin);/*
take port and pin
and initialize as OUTPUT
*/
void LEDON(uint8_t led_port,uint8_t led_pin);/*
take port and pin
and initialize as HIGH
*/
void LEDOFF(uint8_t led_port,uint8_t led_pin);/*
take port and pin
and initialize as LOW
*/
void LEDtoggle(uint8_t led_port,uint8_t led_pin);/*
take port and pin
and TOGGLE pin state
*/
void LED_TEST_FUN();/*
this funcation test if thire any error in LED funcation
if found error it will turn on led
in port_ C
error in LED_init(uint8_t led_port,uint8_t led_pin); pin 0 will be on
error in LEDON(uint8_t led_port,uint8_t led_pin);  pin 1 will be on
error in LEDOFF(uint8_t led_port,uint8_t led_pin) pin 2 will be on
error in LEDtoggle(uint8_t led_port,uint8_t led_pin) pin 3 will be on
*/
#endif /* LED_H_ */