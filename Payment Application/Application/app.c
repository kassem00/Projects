#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>
#include<time.h>
#include"../Application/app.h"
#include"../Card/card.h"
#include"../Server/server.h"
#include"../Terminal/terminal.h"
#include"app.h"

ST_transaction_t transaction[255];
ST_transaction_t* ptransaction = &transaction;
ST_cardData_t card1;
ST_cardData_t *pcard1=&card1;//&transaction->cardHolderData
ST_terminalData_t term1;
ST_terminalData_t *pterm1=&term1;//&transaction->terminalData
int main() {
    appStart();
}/**

*/
void appStart() {
    EN_cardError_t er = getCardPAN(pcard1);
    if (getCardHolderName(pcard1) == WRONG_NAME)
    {
        printf("\n WRONG NAME/!\\ \n");
    }
    else
    {
        fflush(stdin);
        if (getCardExpiryDate(pcard1) == WRONG_EXP_DATE)
        {
            printf("\n WRONG CARD DATE /!\\\n");
        }
        else
        {
            if (er == WRONG_PAN)
            {
                printf("\n PAN ERROR /!\\ \n");
            }
            else
            {
                if (getTransactionDate(pterm1) == WRONG_DATE)
                {
                    printf("\n TRANSACTION DATE ERROR /!\\ \n");
                }
                else
                {
                    if (isCardExpired(pcard1, pterm1) == EXPIRED_CARD)
                    {
                        printf("\n CARD EXPIRED /!\\ \n");
                    }
                    else
                    {
                        if (getTransactionAmount(pterm1) == INVALID_AMOUNT)
                        {
                            printf("\n INVALID AMOUNT  /!\\ \n");
                        }
                        else
                        {
                            if (setMaxAmount(pterm1, 5000.00) == INVALID_MAX_AMOUNT)
                            {
                                printf("\n ERROR WHILE SETTING MAX AMOUNT /!\\ \n");
                            }
                            else
                            {
                                if (isBelowMaxAmount(pterm1) == EXCEED_MAX_AMOUNT)
                                {
                                    printf("\n THE MACHINE CAN'T PROVIDE CASH /!\\ \n");
                                }
                                else
                                {
                                    transaction->cardHolderData = card1;
                                    transaction->terminalData = term1;
                                    EN_transState_t err_list = recieveTransactionData(ptransaction);
                                    if (err_list == FRAUD_CARD)
                                    {
                                        printf("\n!! CARD  NOT FOUND /!\\\n!!");
                                    }
                                    else
                                    {
                                        if (err_list == DECLINED_INSUFFECIENT_FUND)
                                        {
                                            printf("\n!! INSUFFECIENT FUND/!\\ !! \n");
                                        }
                                        else
                                        {
                                            if (err_list == DECLINED_STOLEN_CARD)
                                            {
                                                printf("\n!! STOLEN CARD /!\\ !!\n ");
                                            }
                                            else
                                            {
                                                if (err_list == INTERNAL_SERVER_ERROR)
                                                {
                                                    printf("\n!! SERVER CRASHED /!\\ !! \n");
                                                }
                                                else
                                                {
                                                    if (err_list == APPROVED)
                                                    {
                                                        printf("\nDATA SAVED SUCCESSFULLY\n");
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    // saveTransaction(ptransaction);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}