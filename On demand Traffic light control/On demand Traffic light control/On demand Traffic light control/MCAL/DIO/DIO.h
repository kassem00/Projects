/*
 * DIO.h
 *
 * Created: 10/11/2022 11:52:07 ص
 *  Author: Kassem saber Lotfi Mohammed
 */

#ifndef DIO_H_
#define DIO_H_
#define  A_PORT 'A'
#define  B_PORT 'B'
#define  C_PORT 'C'
#define  D_PORT 'D'


#include "../../Utilities/register.h"
#include "../../Utilities/type.h"

typedef enum EN_DIR{//direction 
	INPUT,OUTPUT
	}EN_DIR;
typedef enum EN_VAL{//value
	HIGH,LOW}EN_VAL;
	
	typedef enum EN_DIO_ERROR{
		DIO_initialize_ERROR,DIO_WRITER_ERROR,DIO_TOGGLE_ERROR,DIO_READ_ERROR
	}EN_DIO_ERROR;

void DIO_INIT(uint8_t port_num, uint8_t pin_num,uint8_t direct);/*
take port and pin
initialize state by user input 
*/
void DIO_WRITE(uint8_t port_num, uint8_t pin_num,uint8_t val);/*
take port and pin
and make pin output High or LOW
*/
void DIO_TOGGLE(uint8_t port_num, uint8_t pin_num);/*
take port and pin
toggle pin state
*/
void DIO_READ(uint8_t port_num, uint8_t pin_num,uint8_t *val);/*
take port and pin 
initialize pin as input 
*/

void DIO_test_fun();/*
this funcation test if thire any error in DIO funcation
if found error it will turn on led
in port_ C
error in DIO_INIT(uint8_t port_num, uint8_t pin_num,uint8_t direct) pin 0 will be on
error in DIO_WRITE(uint8_t port_num, uint8_t pin_num,uint8_t val) pin 1 will be on
error in DIO_TOGGLE(uint8_t port_num, uint8_t pin_num) pin 2 will be on
error in DIO_READ(uint8_t port_num, uint8_t pin_num,uint8_t *val) pin 3 will be on
*/
#endif /* DIO_H_ */