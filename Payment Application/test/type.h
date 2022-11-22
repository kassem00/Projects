/*
 * type.h
 *
 * Created: 06/11/2022 07:26:04 م
 *  Author: Fannan
 */ 


#ifndef TYPE_H_
#define TYPE_H_
#define ACTIVE_H(POR,PIN) POR|=(1<<PIN)
#define ACTIVE_L(POR,PIN) POR&=~(1<<PIN)
#define TOGGL(POR,PIN) POR^=(1<<PIN)
#define READ(POR,PIN) ((POR& (1<<PIN))>>PIN)
typedef unsigned char uint8_t;
#endif /* TYPE_H_ */