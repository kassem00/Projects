#include"terminal.h"
#include "../card/card.h"
#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>
#include<time.h>/**
int main() {
	printf("Tester Name: kassem saper lotfi mohammed\n");

		isBelowMaxAmountTest();
	
		return 0;
	}
*/
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------
*																	 Function
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
	
	EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
	{
	int length = 0, ch[2] = {0,0};//0=day 1=month 2=digit
 	char num[10];//dd/mm/yyyy
	printf("transaction date :");
		scanf(" %s", termData->transactionDate);
		length = strlen(termData->transactionDate);
		strncpy(num,termData->transactionDate,2);
		ch[0] = atoi(num);
		num[0]=termData->transactionDate[3] ;
		num[1]=termData->transactionDate[4] ;
		ch[1] = atoi(num);
		if (termData->transactionDate==NULL||termData->transactionDate[2]&& termData->transactionDate[5]!='/'
			||length!=10||ch[0]>31||ch[1]>12|| isdigit(termData->transactionDate[0] && termData->transactionDate[1] && termData->transactionDate[3] && termData->transactionDate[4] && termData->transactionDate[6] && termData->transactionDate[7] && termData->transactionDate[8]&& termData->transactionDate[9]))
		{
			return	WRONG_DATE;
		}
		else
		{
			return TERMINAL_OK;
		}
}


EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData) {
	char y1[4], y2[4],
		mon1[2],mon2[2];
	int y_num1=0, y_num2=0,m_num1=0,m_num2=0,sp=0;
	y1[0] = cardData->cardExpirationDate[3]; y2[0] = termData->transactionDate[8];
	y1[1] = cardData->cardExpirationDate[4]; y2[1] = termData->transactionDate[9];
	mon1[0] = cardData->cardExpirationDate[0]; mon2[0] = termData->transactionDate[3];
	mon1[1] = cardData->cardExpirationDate[1]; mon2[1] = termData->transactionDate[4];
	y_num1 = atoi(y1);//date expiry year
	y_num2 = atoi(y2);//transaction year
	m_num1 = atoi(mon1);//expiry month
	m_num2 = atoi(mon2);//transication 
	//printf("%dy %dy %dm %dm", y_num1, y_num2, m_num1, m_num2);
	if (y_num1 == y_num2 && mon1<mon2)
	{
		sp = 1;
	}
	//printf("%dsp", sp);
	if (y_num1<y_num2||sp==1)
	{
		return EXPIRED_CARD;

	}
	else
	{
		return TERMINAL_OK;
	}
}


EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData) {
	printf("\ntransaction amount :");
	scanf("	%g",&termData->transAmount);
	//printf("\n transaction amount :%f\n",termData->transAmount);
	if (termData->transAmount<=0)
	{
		return INVALID_AMOUNT;
	}
	else {
		return TERMINAL_OK;
	}

}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData){
		
	if (termData->maxTransAmount< termData->transAmount)
		{
		return EXCEED_MAX_AMOUNT;
	//	printf("%d\n%d", termData->maxTransAmount, termData->transAmount);
	}else{
		return TERMINAL_OK;
	}
}
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount) {
	termData->maxTransAmount = maxAmount;
	if (maxAmount<=0)
	{
		return INVALID_MAX_AMOUNT;
	}
	else
	{
		return TERMINAL_OK;
	
	}

}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------
*																 TEST FUNCATION
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void getTransactionDateTest() {
	ST_terminalData_t ter;
	ST_terminalData_t* pter = &ter;
	EN_terminalError_t err;
	err=getTransactionDate(pter);
	if (err==WRONG_DATE)
	{
		printf("\n!!!!!! wrong date !!!!!!\n");
	}
	else if (err==TERMINAL_OK)
	{
		printf("\n DATE IS OK \n");
	}
}
void isCardExpriedTest(void) {
	ST_terminalData_t ter;
	ST_terminalData_t* pter = &ter;
	ST_cardData_t pan;
	ST_cardData_t* ppan = &pan;
	EN_cardError_t xaa= getCardExpiryDate(ppan);
	EN_terminalError_t err = getTransactionDate(pter);
		EN_terminalError_t ER = isCardExpired(ppan, pter);
		if (ER == EXPIRED_CARD)
		{
			printf("\nexpierd card /!\\\n");
		}
		if (ER == TERMINAL_OK)
		{
			printf("\n Approved \n");
		}

	}
	
void getTransactionAmountTest() {
	ST_terminalData_t amo;
	ST_terminalData_t *pamo=&amo;
	EN_terminalError_t tr=getTransactionAmount(pamo);
	if (tr==INVALID_AMOUNT)
	{
		printf("\n invaltd amonut /!\\ \n");
	}
	else {
		printf("\n good amount\n");
	}
}
void isBelowMaxAmountTest(void) {
	float x = 500.0;
	ST_terminalData_t amo;
	ST_terminalData_t* pamo = &amo;
	setMaxAmount(pamo,x);
	printf("%f\n", amo.maxTransAmount);//delet after test
	getTransactionAmount(pamo);
	//printf("MAX Transaction Amount :");
	
	EN_terminalError_t tr = isBelowMaxAmount(pamo);
	if (tr == EXCEED_MAX_AMOUNT)
	{
		printf("\n  EXCEED_MAX_AMOUN /!\\\n");
	}
	else {
		printf("\n good amount\n");
	}
}

void setMaxAmountTest(void) {
	ST_terminalData_t amo;
	ST_terminalData_t* pamo = &amo;
	float x = 0;
	printf("MAX Transaction Amount :");
	scanf("%f", &x);
	EN_terminalError_t tr = setMaxAmount(pamo, x);
	if (tr == INVALID_MAX_AMOUNT)
	{
		printf("\n INVALID_MAX_AMOUNT/!\\\n");
	}
	else {
		printf("\n good amount\n");
	}
}


/*
* 	printf("\ntest case : 1\n");
	printf("Expected Result: If the input amount is less than 0\nwill print error massage\n");
	printf(" Actual Result :\n ");
	setMaxAmountTest();	
	printf("\ntest case : 2\n");
	printf("Expected Result: if the in put amount equal to zero\n  will print error massage \n");
	printf(" Actual Result :\n ");
	setMaxAmountTest();
	printf("Expected Result: if the in put amount > 0 \nwill print good amount \n");
	printf(" Actual Result :\n ");
	setMaxAmountTest();
*
*/