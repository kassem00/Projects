/*
 * DIO.h
 *
 * Created: 06/11/2022 07:30:03 م
 *  Author: Fannan
 */ 


#ifndef DIO_H_
#define DIO_H_
#define  A_PORT 'A'
#define  B_PORT 'B'
#define  C_PORT 'C'
#define  D_PORT 'D'

#define ACTIVE_H(POR,PIN) POR|=(1<<PIN)
#define ACTIVE_L(POR,PIN) POR&=~(1<<PIN)
#define TOGGL(POR,PIN) POR^=(1<<PIN)
#define READ(POR,PIN) ((POR& (1<<PIN))>>PIN)
#include "../../Utilites/register.h"
#include "../../Utilites/type.h"

typedef enum EN_DIR{//direction 
	INPUT,OUTPUT
	}EN_DIR;
typedef enum EN_VAL{//value
	HIGH,LOW}EN_VAL;

void DIO_INIT(uint8_t port_num, uint8_t pin_num,uint8_t direct);//DDR,8_PIN,HIGH_lOW  INitializ direction
void DIO_WRITE(uint8_t port_num, uint8_t pin_num,uint8_t val);//write from dio 
void DIO_TOGGLE(uint8_t port_num, uint8_t pin_num);
void DIO_READ(uint8_t port_num, uint8_t pin_num,uint8_t *val);	




#endif /* DIO_H_ */