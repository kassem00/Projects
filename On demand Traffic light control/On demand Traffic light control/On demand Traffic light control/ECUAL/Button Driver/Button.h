/*
 * Button.h
 *
 * Created: 10/11/2022 11:52:07 ص
 *  Author: Kassem saber Lotfi Mohammed
 */
#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO/DIO.h"

typedef enum EN_BUTTON{
initialize_ERROR,STATE_ERROR
}EN_BUTTON;
void BUT_init(uint8_t B_port,uint8_t B_pin);/*
take port and pin
and initialize as input
*/
void BUT_state(uint8_t B_port,uint8_t B_pin,uint8_t *val);/*
take port and pin and variable address and storing state on variable user give */
void but_fun_test();
#endif /* BUTTON_H_ */