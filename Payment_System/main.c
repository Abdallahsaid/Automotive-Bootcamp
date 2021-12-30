
#include <stdio.h>
#include "STD_TYPES.h"
#include "operation.h"

int main(void)
{   u8_t proceed;

    while(1){
    ST_cardData_t card = enterCardData();
    ST_terminalData_t terminal = enterTerminalData();
    
    if(verifyData(card , terminal)){
       printf("The Transaction is APPROVED.\n");
    }
    else
    {
        printf("The Transaction is DECLINED.\n");
    }

  printf("Do you want to continue (y/n)?:\n")    ;
  
  scanf("%c",&proceed);
  if(proceed == 'n'){
      break;
  }
  else if (proceed == 'y')
  {
      continue;
  }
  else
  {
      break;
  }
    }

    return 0;
}
