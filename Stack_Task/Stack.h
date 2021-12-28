/*
 ============================================================================
 Name        : Stack.h
 Author      : Abdalla Saied
 Version     :v.1
 ============================================================================
 */
#ifndef  STACK_H
#define STACK_H
#define MAX_STACK_SIZE  20

void stack_push(u8_t u8_data);
u8_t stack_pull(void);
void stack_printStack(void);


#endif
