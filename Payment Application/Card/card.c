#include "card.h"
#include <string.h>
#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------
*																	 Function
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

EN_cardError_t getCardHolderName(ST_cardData_t* cardData) {//error acord
	int is_it=0,length=0;
	printf("card holder name : ");
	fgets(cardData->cardHolderName, 25, stdin);
	length = strlen(cardData->cardHolderName);
	for (int i = 0;i<24; i++) {
		is_it = is_it + isalpha(cardData->cardHolderName[i]);
	}//alpha =0printf("%d len %d", length, is_it);
	if(24 < length||20 >length|| cardData->cardHolderName == NULL||is_it==0) {
		return WRONG_NAME;
	}
	else {
		return CARD_OK;
	}
}

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData) {
	int ch;
	char num[5];//MM/YY
	printf("card expiry date MM/YY : ");
	scanf("%s", cardData->cardExpirationDate);
	strncpy(num, cardData->cardExpirationDate, 2);
	ch= atoi(num);
	if (strlen(cardData->cardExpirationDate) != 5 || cardData->cardExpirationDate == NULL || cardData->cardExpirationDate[2] != '/'
		|| isdigit(cardData->cardExpirationDate[0] && cardData->cardExpirationDate[1] && cardData->cardExpirationDate[3] && cardData->cardExpirationDate[4]) != 0||ch>12) {

		return WRONG_EXP_DATE;
	}
	else
	{
		return CARD_OK;
	}
}
EN_cardError_t getCardPAN(ST_cardData_t* cardData) {
	fflush(stdout);
	char te[20];
	int it_is=0, leng;
	printf("Primary Account Number : ");
	//sscanf(stdin,"%f", cardData->primaryAccountNumber);
	fgets(cardData->primaryAccountNumber, 20, stdin);
	leng = strlen(cardData->primaryAccountNumber);
	for (int i = 0; i > 20; i++) {
		it_is = it_is + isdigit(cardData->cardHolderName[i]);
	}//digit = 0
	if(19 < leng || leng < 16||it_is!=0)
	{
		return WRONG_PAN;
	}
	else {
		return CARD_OK;
	}
}
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------
*																 TEST FUNCATION
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void getCardPANTest() {
	ST_cardData_t pann;
	ST_cardData_t* ppan = &pann;
	EN_cardError_t er = getCardPAN(ppan);
	if (er == CARD_OK)
	{
		printf("found card");
	}
	else if (er == WRONG_PAN) {
		printf("\n!!!! wrong number !!!!\n");

	}
}
void getCardExpiryDateTest() {
	ST_cardData_t card1;
	ST_cardData_t* pcard1 = &card1;
	EN_cardError_t xaa;
	xaa = getCardExpiryDate(pcard1);
	if (xaa == CARD_OK)
	{
		printf("\n found card \n");
	}
	else if (xaa == WRONG_EXP_DATE) {
		printf("\n!!! Wrong date !!!\n");
	}
}
void getCardHolderNameTest() {//test funcation 
	ST_cardData_t card;
	ST_cardData_t* pcard = &card;
	EN_cardError_t xa = getCardHolderName(pcard);
	if (xa == CARD_OK) {
		printf("\nFound card \n");
	}
	if (xa == WRONG_NAME) {
		printf("\n!!! Wrong name !!!\n");
	}
}
