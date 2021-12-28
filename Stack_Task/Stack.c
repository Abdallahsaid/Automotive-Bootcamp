/*
 ============================================================================
 Name        : Stack.C
 Author      : Abdalla Saied
 Version     :v.1
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "Linked_List.h"
#include "Stack.h"

static s8_t top = -1;

void stack_push(u8_t u8_data)
{
    if (top < MAX_STACK_SIZE - 1)
    {
        top++;
        LL_insertFirst(u8_data);
    }
    else
    {
        printf("stack overflow");
    }
}

u8_t stack_pull(void)
{
    u8_t u8_t_temp = 0;
    
    if (top > -1)
    {
        top--;
        node_t *node_temp = LL_deleteFirst();
        u8_t_temp = node_temp->data;
        free(node_temp);
        
    }
    else{
        printf("stack is empty");
    }
    return u8_t_temp;
}

void stack_printStack(void){

    LL_printList();

}