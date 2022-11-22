/*
 * Application.h
 *
 * Created: 10/11/2022 11:52:07 ص
 *  Author: Kassem saber Lotfi Mohammed
 */
#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "../ECUAL/Button Driver/Button.h"
#include "../ECUAL/LED Driver/LED.h"
#include "../MCAL/Timer/Timer.h"
#include "../MCAL/Interrupts/Interrupt.h"
#include "../Utilities/register.h"
#include "../Utilities/type.h"
//define car PORTs and PINs
#define CAR_LED_PORT A_PORT
#define PIN_1_CAR_LED_RED	2
#define PIN_2_CAR_LED_YELLOW	1
#define PIN_3_CAR_LED_GREEN	0
//define pedestrian car PORTs and PINs
#define PED_LED_PORT_inti B_PORT
#define PED_PIN_1_LED_RED	2
#define PED_PIN_2_LED_YELLOW	1
#define PED_PIN_3_LED_GREEN	0

typedef enum EN_APP{
initializeERROR,NormalERROR,PEDMODERROR,APPOK
}EN_APP;
typedef enum EN_WHAT_COLOR{
RED=1,YELLOW=2,GRREEN=3
}EN_WHAT_COLOR;


void app_inti();/*
1.this function will initialize all PORTs and PINs
2.initialize timer
3.initialize interrupts
*/
void normal_mode();/*
this function will run normal mode in sequence manner
*/
void ped_mod(uint8_t *color);/*
this function will take color address
and enter the appropriate pedestrian mode according to color
*/

void end_ped_mod();/*
this function will execute after pedestrian to initialize normal mode 
*/
void APP_start();/*
this function contain all system logic
*/
#endif /* APPLICATION_H_ */