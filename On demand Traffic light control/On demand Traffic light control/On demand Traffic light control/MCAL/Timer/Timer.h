/*
 * Timer.h
 *
 * Created: 10/11/2022 11:52:07 ص
 *  Author: Kassem saber Lotfi Mohammed
 */

#ifndef TIMER_H_
#define TIMER_H_

#define NUMBER_OF_OVER_FLOW 1
#define F_CPU 1000000UL//1MHZ
#define wdt_reset() __asm__ __volatile__ ("wdr")
#include "../../Utilities/register.h"
#include "../../Utilities/type.h"
#include "../../ECUAL/LED Driver/LED.h"
typedef enum EN_TIMER_ERROR{
initialize_ERORR,TIMER_DELAY_ERROR,TIMER_DELAY_BLINK,TWO_TIMER_DELAY_BLINK
}EN_TIMER_ERROR;
void timer_inti();//initialize timer 0 in microcontroller
void timer_delay(uint8_t T_S);//Creates a delay by a second 
void LED_blink_delay(uint8_t led_port,uint8_t led_pin,uint8_t T_S);//make blink by using overflows with delay
void two_LED_blink_delay(uint8_t led_port1,uint8_t led_pin1,uint8_t led_port2,uint8_t led_pin2,uint8_t T_S);/*
make delay on two port and pins in same time */
void timer_test_fun();/*
this funcation test if thire any error in timer funcation 
if found error it will turn on led 
in port_ C
error in timer_inti() pin 0 will be on 
error in timer_delay(uint8_t T_S); pin 1 will be on
error in timer_inti() pin 2 will be on
error in timer_inti() pin 3 will be on
*/
#endif /* TIMER_H_ */