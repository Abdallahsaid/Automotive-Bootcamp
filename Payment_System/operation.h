/**********************************/
/* Author   : Abdalla Abdelhafiz  */
/* Date     : 30/12/2021          */
/* Version  : V01                 */
/**********************************/
#ifndef  OPERATION_H
#define  OPERATION_H

#define ACCOUNT_BALANCE_ARR_SIZE   10

typedef struct 
{
    u8_t cardHolderName[25];
    u8_t primaryAccountNumber[20];
    u8_t cardExpirationDate[6]; 
}ST_cardData_t;

typedef struct 
{
    f32_t transAmount;
    f32_t maxTransAmount ;
    u8_t  transactionDate[11];
}ST_terminalData_t;

typedef struct 
{
    u8_t  primaryAccountNumber[20];
    f32_t balance; 
}ST_accountBalance;


ST_cardData_t enterCardData(void);
ST_terminalData_t enterTerminalData(void);
u8_t verifyDate(u8_t *transactionDate, u8_t *ExpirationDate);
u8_t pan_amount_check(u8_t *pan , f32_t amount);
u8_t verifyData(ST_cardData_t st_card , ST_terminalData_t st_terminal );




#endif
