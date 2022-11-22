#include "server.h"
#include <string.h>
#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>
 ST_accountsDB_t extern accountsDB[255]={
	{1000,RUNNING,  "8989374615436850"},
	{200000,BLOCKED,"5807007076043871"},
	{30000,RUNNING, "1234567892138982"},
	{400,RUNNING,  "1234567892398983"},
	{500000,BLOCKED,"1234567896768984"},
	{60000,RUNNING, "1234567892158075"},
};

//Error
ST_transaction_t transaction[255];//DB
ST_cardData_t *cardData;
EN_transState_t Error_list;
uint32_t i = 0,tran_index=0;//squance number transaction element
ST_accountsDB_t* paccountsDB = &accountsDB[0];
	
	

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------
*																	 Function
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{
//	This function will take all transaction dataand validate its data
//	all fucation will call hear

	if (isValidAccount(&transData->cardHolderData,&accountsDB[i]) == ACCOUNT_NOT_FOUND)
	{
		return FRAUD_CARD;
	}
	else
	{
		if (isBlockedAccount(&accountsDB[i])==BLOCKED_ACCOUNT)
		{
			return DECLINED_STOLEN_CARD;
		}
		else
		{
			if (isAmountAvailable(&transData->terminalData,&accountsDB[i]) == LOW_BALANCE)
			{
				return DECLINED_INSUFFECIENT_FUND;
			}
			else
			{
				printf("\n Blance : %f\n", accountsDB[i].balance);
				accountsDB[i].balance=accountsDB[i].balance - transData->terminalData.transAmount;
				printf("\n Blance update to  : %f\n", accountsDB[i].balance);
				if (saveTransaction(transData)!=SERVER_OK)
				{
					return INTERNAL_SERVER_ERROR;
				}
				else
				{
					return APPROVED;
				
				}
			}
		}
	}

	// isblock
	// 
	//
	//

}

EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t* accountRefrence) {
	int tru=0,ret=0;
	int num1=0, num2=0;
	int leng1 = 0, leng2=0;
	char chnum1[20], chnum2[20];
	//printf("\nin leng %d\n",leng1);
	for (i = 0; i < 10; i++)
	{//dbsearch
		tru = 0;
		strcpy(chnum1,cardData->primaryAccountNumber);
		strcpy(chnum2 , accountsDB[i].primaryAccountNumber);
		for (int j = 0; j <20; j++)
		{if (chnum1[j]==chnum2[j])
			{
			tru = tru +1;
			}
			}
		if (tru == 18)
		{
			break;
		}
	//	printf("%d\n", tru);
	}
	if (tru==18) {
	//	printf("%s\n", accountsDB[i].primaryAccountNumber);
		
		accountRefrence =&accountsDB[i];
	//	printf("\n  pppp %s  pp \n", accountRefrence->primaryAccountNumber);
		return SERVER_OK;
	}
	else
	{
	
			return ACCOUNT_NOT_FOUND;
			accountRefrence = NULL;


	}
}
EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence) {
	
	if (accountRefrence->state==BLOCKED)
	{
		return BLOCKED_ACCOUNT;
	}
	else
	{
			return SERVER_OK;
	}
}
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_accountsDB_t* accountRefrence) {
	if (termData->transAmount>accountRefrence->balance)
	{
		return LOW_BALANCE;
	}
	else
	{
		return SERVER_OK;
	}
}

EN_serverError_t saveTransaction(ST_transaction_t* transData) {/*
	It gives a sequence number to a transaction, 
		 this number is incremented once a transaction is processed into the server, 
			 you must check the last sequence number in the server to give the new transaction a new sequence numberIt saves any type of transaction
	*/
	if (is_DB_full()==1)
	{
		printf("\n!!!!!!!! Error Data bass is  full/!\\ !!!!!!!!\n");
	}
	else
	{

		transData->transactionSequenceNumber = tran_index;
		//it will search if tr
		if (transData->transState == APPROVED || transData->transState == DECLINED_INSUFFECIENT_FUND 
			|| transData->transState == DECLINED_STOLEN_CARD ||
			transData->transState == FRAUD_CARD || transData->transState == INTERNAL_SERVER_ERROR) {
			transaction[transData->transactionSequenceNumber] = *transData;
			tran_index++;
			listSavedTransactions();
		}	
	}
	return SERVER_OK;
}

void listSavedTransactions(void){
	/*
	APPROVED, DECLINED_INSUFFECIENT_FUND, 
	DECLINED_STOLEN_CARD, FRAUD_CARD,
	INTERNAL_SERVER_ERROR

	*/
	char fo[60] = "##################################################";
	char sts[5][30]={"APPROVED","DECLINED_INSUFFECIENT_FUND ","DECLINED_STOLEN_CARD"," FRAUD_CARD","INTERNAL_SERVER_ERROR"};//state
	for (int i = 0; i < tran_index; i++)
	{
		printf("\n%s\n", fo);
		printf("Transaction Sequence Number: %d\n",transaction[tran_index-1].transactionSequenceNumber);
		printf("Transaction Date: %s\n", transaction[tran_index - 1].terminalData.transactionDate);
		printf("Transaction Amount: %f\n", transaction[tran_index-1].terminalData.transAmount);
		printf("Transaction State: %s\n", sts[transaction[tran_index - 1].transState]);
		printf("Terminal Max Amount: %f\n", transaction[tran_index - 1].terminalData.maxTransAmount);
		printf("Cardholder Name: %s\n", transaction[tran_index - 1].cardHolderData.cardHolderName);
		printf("PAN: %s\n", transaction[tran_index - 1].cardHolderData.primaryAccountNumber);
		printf("Card Expiration Date: %s\n", transaction[tran_index - 1].cardHolderData.cardExpirationDate);
		printf("\n%s\n", fo);
	}/**
* after saving using save transection
* it's works by cheak squance number
* if you find sq increment {transqtion saved }
* if not find not decrement  transaqtion not saved
**
*//**
#########################
Transaction Sequence Number: 
Transaction Date:
Transaction Amount:
Transaction State:
Terminal Max Amount:
Cardholder Name:
PAN:
Card Expiration Date:
#########################
	**/
}

int is_DB_full(){
	if (255< tran_index)
	{
		return 1;
	}
	else
	{
		return	0;
	}
}
int is_DB_empty() {
	if (tran_index<=0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------
*																 TEST FUNCATION
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


//void recieveTransactionDataTest(){}

void isBlockedAccountTest() {
	ST_cardData_t ac;
	ST_cardData_t* pac = &ac;
	EN_cardError_t err = getCardPAN(pac);
	EN_serverError_t erp = isValidAccount(pac,&accountsDB[i]);
	EN_serverError_t er = isBlockedAccount(&accountsDB[i]);
	if (err == CARD_OK)
	{
		printf("found card");
	}
	else if (err == WRONG_PAN) {
		printf("\n!!!! wrong number !!!!\n");

	}
	if (er == BLOCKED_ACCOUNT)
	{
		printf("\n stolen card \n");
	}
	if (er == SERVER_OK)
	{
		printf("\nrunning acount found \n");
	//	printf("Available balance %f",PaccountsDB->balance);
	//	printf("Available balance %d", PaccountsDB->state);
		
	}
}




void isValidAccountTest() {	
	ST_cardData_t ac;
	ST_cardData_t* pac=&ac;
	ST_accountsDB_t* pdb1 = &accountsDB[i];
	EN_cardError_t err = getCardPAN(pac);
	EN_serverError_t er= isValidAccount(pac, pdb1);
	printf("\n  pppp %s  pp \n", pdb1[i].primaryAccountNumber);
	if (err == CARD_OK)
	{
		printf("found card");	
	}
	else if (err == WRONG_PAN) {
		printf("\n!!!! wrong number !!!!\n");

	}
	if (er==ACCOUNT_NOT_FOUND)
	{
		printf("\nacount not found \n");
	}
	if (er == SERVER_OK)
	{
		printf("\nacount found \n");
		printf("Available balance %f",pdb1[i].balance);
	}
}

void isAmountAvailableTest() {
	ST_cardData_t ac;
	ST_cardData_t* pac = &ac;
	EN_cardError_t err1 = getCardPAN(pac);
	EN_serverError_t err2 = isValidAccount(pac, &accountsDB[i]);
	ST_terminalData_t term;
	ST_terminalData_t* pterm= &term;
	EN_terminalError_t err3=getTransactionAmount(pterm);
	if (err1==WRONG_PAN)
	{
		printf("wrong PAN");
		exit(1);
	}
	else
	{
		if (err2==ACCOUNT_NOT_FOUND)
		{
			printf(" account no found ");
			exit(1);
		}
		else
		{
			if (isAmountAvailable(pterm, &accountsDB[i]) == LOW_BALANCE)
			{
				printf("\n!!!!!!! LOW Balance !!!!!!!!!!\n");
				exit(1);
			}
			else
			{
				printf("\nAvailable Amount\n");
				exit(1);
			}
		}
	}
	
	
}

void saveTransactionTest() {
	tran_index = 256;//change this for the sake of testing
	float max = 2000;
	ST_transaction_t try;
	ST_transaction_t *ptry=&try;
	getCardHolderName(&ptry->cardHolderData);
	getCardExpiryDate(&ptry->cardHolderData);
	getTransactionDate(&try.terminalData);
	strcpy(try.cardHolderData.primaryAccountNumber, accountsDB[i].primaryAccountNumber);
	getTransactionAmount(&ptry->terminalData);
	try.terminalData.maxTransAmount= 2000;
	try.transState=APPROVED;
	/**printf("ENTER SQUANCE NUMBER : ");
	scanf("%d",&tran_index);*/
	saveTransaction(ptry);
	/*
use all funcation to fill this funcation 
*/
}

void	listSavedTransactionsTest() {
	float max = 2000;
	ST_transaction_t try;
	ST_transaction_t* ptry = &try;
	getCardHolderName(&ptry->cardHolderData);
	getCardExpiryDate(&ptry->cardHolderData);
	getTransactionDate(&try.terminalData);
	strcpy(try.cardHolderData.primaryAccountNumber, accountsDB[i].primaryAccountNumber);
	getTransactionAmount(&ptry->terminalData);
	try.terminalData.maxTransAmount = 2000;
	try.transState = APPROVED;
	/**printf("ENTER SQUANCE NUMBER : ");
	scanf("%d",&tran_index);*/
	saveTransaction(ptry);
}
void recieveTransactionDataTest() {//testing
	float max = 2000;
	ST_transaction_t try;
	ST_transaction_t* ptry = &try;
	if (getCardPAN(&ptry->cardHolderData) == WRONG_PAN)
	{
		printf("\ninput error \n");
	}
	else
	{
		if (isValidAccount(&ptry->cardHolderData, &accountsDB[i]) == ACCOUNT_NOT_FOUND)
		{
			printf("\ninput error \n");
		}
		else
		{
			if (getCardHolderName(&ptry->cardHolderData) == WRONG_NAME)
			{
				printf("\ninput error \n");
			}
			else
			{
				if (getCardExpiryDate(&ptry->cardHolderData)==WRONG_EXP_DATE)
				{
					printf("\ninput error \n");
				}
				else
				{
					if (getTransactionDate(&ptry->terminalData)== WRONG_DATE)
					{
						printf("\ninput error \n");
					}
					else
					{
						if (getTransactionAmount(&ptry->terminalData) == INVALID_AMOUNT)
						{
							printf("\ninput error \n");
						}
					}
				}
			}
		}
	}
	
	fflush(stdin);
	fflush(stdout);

 //try.transState = BLOCKED;
	/**printf("ENTER SQUANCE NUMBER : ");
	scanf("%d",&tran_index*/
	EN_transState_t err_list=	recieveTransactionData(ptry);
	if (err_list==FRAUD_CARD)
	{
		printf("\n!! CARD  NOT FOUND /!\\\n!!");
	}
	else if (err_list == DECLINED_INSUFFECIENT_FUND)
	{
		printf("\n!! INSUFFECIENT FUND/!\\ !! \n your blance = %f \n",accountsDB[i].balance);
	}
	else if (err_list == DECLINED_STOLEN_CARD)
	{
		printf("\n!! STOLEN CARD /!\\ !!\n ");
	}
	else if (err_list == INTERNAL_SERVER_ERROR)
	{
		printf("\n!! SERVER CRASHED /!\\ !! \n");
	}
	else if (err_list == APPROVED)
	{
		printf("\nDATA SAVED SUCCESSFULLY\n");
	}
	
}