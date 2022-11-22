/*
 * Button.h
 *
 * Created: 07/11/2022 02:18:14 م
 *  Author: Fannan
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO Driver/DIO.h"

void BUT_init(uint8_t B_port,uint8_t B_pin);
void BUT_state(uint8_t B_port,uint8_t B_pin,uint8_t *val);

#endif /* BUTTON_H_ */