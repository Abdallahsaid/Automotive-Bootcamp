/*
 ============================================================================
 Name        : Linked_List.h
 Author      : Abdalla Saied
 Version     :v.1
 ============================================================================
 */
#ifndef  LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node {
   u16_t data;
   struct node *next;
}node_t;



void LL_printList(void);
void LL_insertFirst( u8_t data);
node_t* LL_deleteFirst(void);


#endif
