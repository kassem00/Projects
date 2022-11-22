/*
 * Application.c
 *
 *  Author: Kassem saber Lotfi Mohammed
 */ 

#include "Application.h"
	
uint8_t color=0, squan=0,intr=0;

void app_inti(){
	
	/*
1.this function will initialize all PORTs and PINs
2.initialize timer
3.initialize interrupts
*/
	
//squan=0;
	//initialize car LED pins
	LED_init(CAR_LED_PORT,PIN_1_CAR_LED_RED);
	LED_init(CAR_LED_PORT,PIN_2_CAR_LED_YELLOW);
	LED_init(CAR_LED_PORT,PIN_3_CAR_LED_GREEN);
//initialize pedestrian  LED pins
	LED_init(PED_LED_PORT_inti,PED_PIN_1_LED_RED);
	LED_init(PED_LED_PORT_inti,PED_PIN_2_LED_YELLOW);
	LED_init(PED_LED_PORT_inti,PED_PIN_3_LED_GREEN);
	//initialize TIMER
timer_inti();
//initialize pedestrian BUTTON by enable inrrupt
//initial rising edge interrupt
MCUCR=(1<<0);
MCUCR=(1<<1);
sei();
	//CHOSSING INT0 AS external interrupts pin
GICR=(1<<6);

}/**/

void APP_start(){
	if(intr==1){
		ped_mod(&color);
}else
{
	normal_mode();
}
}
void normal_mode(){
	/*
this function will run normal mode in sequence manner
*/
		switch (squan)
		{
			case 0:
			//turn on car green led  and pedestrian red led 
			LEDON(PED_LED_PORT_inti,PED_PIN_1_LED_RED);
			color=GRREEN;
			LEDON(CAR_LED_PORT,PIN_3_CAR_LED_GREEN);
			timer_delay(5);
			LEDOFF(CAR_LED_PORT,PIN_3_CAR_LED_GREEN);
			break;
			
			case 1:

//turn on car yellow led
			color= YELLOW;
			LED_blink_delay(CAR_LED_PORT,PIN_2_CAR_LED_YELLOW,5);
			break;
			
			case 2:
			
			color=RED;
			LEDON(CAR_LED_PORT,PIN_1_CAR_LED_RED);
			timer_delay(5);
			LEDOFF(CAR_LED_PORT,PIN_1_CAR_LED_RED);
			break;
	
			case 3:
			color=YELLOW;
			LED_blink_delay(CAR_LED_PORT,PIN_2_CAR_LED_YELLOW,5);	
			break;
		}
		if (squan<3)
		{
			squan++;
	}else
	{
			squan=0;
	}
	
	

}//endd
void ped_mod(uint8_t *color){
	/*
this funcation 
*/
		if(*color==RED){
			
			LEDOFF(PED_LED_PORT_inti,PED_PIN_1_LED_RED);
			LEDON(CAR_LED_PORT,PIN_1_CAR_LED_RED);
			LEDON(PED_LED_PORT_inti,PED_PIN_3_LED_GREEN);
			timer_delay(5);
			LEDOFF(PED_LED_PORT_inti,PED_PIN_3_LED_GREEN);
			//LEDOFF(CAR_LED_PORT,PIN_1_CAR_LED_RED);
			//squan=3;
			
	}else
	{
		if(*color==GRREEN||*color==YELLOW){
				LEDOFF(PED_LED_PORT_inti,PED_PIN_1_LED_RED);
				LEDOFF(CAR_LED_PORT,PIN_3_CAR_LED_GREEN);
				two_LED_blink_delay(CAR_LED_PORT,PIN_2_CAR_LED_YELLOW,PED_LED_PORT_inti,PIN_2_CAR_LED_YELLOW,5);
				LEDON(CAR_LED_PORT,PIN_1_CAR_LED_RED);
				LEDON(PED_LED_PORT_inti,PED_PIN_3_LED_GREEN);
				timer_delay(5);
				LEDOFF(PED_LED_PORT_inti,PED_PIN_3_LED_GREEN);
			//endig funcation 	
			}
		
		}
						end_ped_mod();

}
void end_ped_mod(){
	LEDOFF(CAR_LED_PORT,PIN_1_CAR_LED_RED);
	two_LED_blink_delay(CAR_LED_PORT,PIN_2_CAR_LED_YELLOW,PED_LED_PORT_inti,PIN_2_CAR_LED_YELLOW,5);
	squan=0;
	//ACTIVE_H(WDTCR,3);
//	wdt_reset();
intr=0;
}

ISR(EXT_INT_0){
	//ped_mod(&color);
	//ACTIVE_H(WDTCR,3);
	//wdt_reset();
if (intr==0)
			{intr=1;
}else{
			intr=0;}
		
}
