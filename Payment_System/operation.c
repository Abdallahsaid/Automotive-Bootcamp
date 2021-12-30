#include <stdio.h>
#include <string.h>
#include "STD_TYPES.h"
#include "operation.h"

#define TRUE 1
#define FALSE 0

ST_accountBalance gST_AccountBalance[ACCOUNT_BALANCE_ARR_SIZE] ={ 
    {"123456789" ,100.00 },
    {"234567891" ,6000.00},
    {"567891234" ,3250.25},
    {"456789123" ,1500.12},
    {"258649173" ,500.00 },
    {"654823719" ,2100.00},
    {"971362485" ,0.00   },
    {"793148625" ,1.00   },
    {"123123456" ,10.12  },
    {"456789321" ,0.55   }
};


// functions implementation

// a function that receives the card data from the user
ST_cardData_t enterCardData(void)
{
    ST_cardData_t st_cardData;

    printf("Please Enter Card Data:\n");
    printf("Please Enter the Card Holder Name:\n");
    scanf("%s", st_cardData.cardHolderName);
    fflush(stdin);
    printf("Please Enter the Primary Account Number:\n");
    scanf("%s", st_cardData.primaryAccountNumber);
    fflush(stdin);
    printf("Please Enter Card Expiry Date:\n");
    scanf("%s", st_cardData.cardExpirationDate);
    fflush(stdin);

    return st_cardData;
}
ST_terminalData_t enterTerminalData(void)
{
    ST_terminalData_t st_terminalData;

    printf("Please Enter Terminal Data:\n");
    printf("Please Enter the transaction Amount:\n");
    scanf("%.2f", st_terminalData.transAmount);
    fflush(stdin);
    printf("Please Enter transaction Date:\n");
    scanf("%s", st_terminalData.transactionDate);
    fflush(stdin);
    st_terminalData.maxTransAmount=5000.00;
    return st_terminalData;
}

//function to verify that card not expired
u8_t verifyDate(u8_t *transactionDate, u8_t *ExpirationDate)
{
    u8_t u8_transactionMonth, u8_transactionYear, u8_expireMonth, u8_expireYear;
    if (transactionDate[0] == '\0' || ExpirationDate[0] == '\0')
    {
        return FALSE;
    }
    else
    {
        // do nothing
    }

    u8_transactionYear = (transactionDate[9] - '0') + (10 * (transactionDate[8] - '0'));
    u8_expireYear = (ExpirationDate[4] - '0') + (10 * (ExpirationDate[3] - '0'));
    if (u8_expireYear > u8_transactionYear)
    {
        return TRUE;
    }
    else if (u8_expireYear < u8_transactionYear)
    {
        return FALSE;
    }

    else if (u8_expireYear == u8_transactionYear)
    {

        u8_transactionMonth = (transactionDate[4] - '0') + (10 * (transactionDate[3] - '0'));
        u8_expireMonth = (ExpirationDate[1] - '0') + (10 * (ExpirationDate[0] - '0'));

        if (u8_expireMonth > u8_transactionMonth)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
        else return FALSE;
    }

// function to check PAN if PAN exists, the function checks if the amount < the balance  
// if all valid return true if any check fails return false
u8_t pan_amount_check(u8_t *pan , f32_t amount)
{
    u8_t u8_counter = 0;
    for (u8_counter = 0; u8_counter < ACCOUNT_BALANCE_ARR_SIZE; u8_counter++)
    {
        if (strcmp(pan , gST_AccountBalance[u8_counter].primaryAccountNumber) == 0)
        {
            if ( gST_AccountBalance[u8_counter].balance >= amount)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
            
            
        }
        else
        {
            //do nothing
        }
        
    }
    return FALSE;
}

// function that verify all the data
u8_t verifyData(ST_cardData_t st_card, ST_terminalData_t st_terminal)
{

    // checking if expired
    if (verifyDate(st_terminal.transactionDate, st_card.cardExpirationDate) == FALSE)
    {
        return FALSE;
    }
    else
    {
        // do nothing
    }
    // check if the ammount is accepted by the terminal
    if (st_terminal.transAmount > st_terminal.maxTransAmount)
    {
        return FALSE;
    }
    else
    {
        // do nothing
    }
    // check if PAN exists and for amount <= balance
    return pan_amount_check(st_card.primaryAccountNumber , st_terminal.transAmount);
}
