/*
 ============================================================================
 Name        : Linked_List.c
 Author      : Abdalla Saied
 Version     :v.1
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "Linked_List.h"
node_t *node_t_head = NULL;
// display the list
void LL_printList(void)
{
    node_t *node_t_ptr = node_t_head;
    while (node_t_ptr != NULL)
    {
        printf("%d\n", node_t_ptr->data);
        node_t_ptr = node_t_ptr->next;
    }
}

//insert node at first location
void LL_insertFirst( u8_t u8_t_data){
//create a node 
node_t *node = (node_t*) malloc(sizeof(node_t));
node->data = u8_t_data;

node->next = node_t_head;
node_t_head= node;

}
//delete first node
node_t* LL_deleteFirst(void){

   node_t *temp_node = node_t_head;
   node_t_head = node_t_head->next;
   return temp_node;

}
