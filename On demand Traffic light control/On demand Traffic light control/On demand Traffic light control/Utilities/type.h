/*
 * type.h
 *
 * Created: 10/11/2022 11:52:07 ص
 *  Author: Kassem saber Lotfi Mohammed
 */

#ifndef TYPE_H_
#define TYPE_H_
#define ACTIVE_H(POR,PIN) POR|=(1<<PIN)
#define ACTIVE_L(POR,PIN) POR&=~(1<<PIN)
#define TOGGL(POR,PIN) POR^=(1<<PIN)
#define READ(POR,PIN) ((POR& (1<<PIN))>>PIN)
typedef unsigned char uint8_t;
#endif /* TYPE_H_ */