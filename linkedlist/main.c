/* 
 * File:   main.c
 * Author: trabdlkarim
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "include/linkedlist.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    Node* list_head = NULL;
    
    printf("Initial list state: ");
    add_node_tail(20,&list_head);
    add_node_tail(10,&list_head);
    add_node_tail(15,&list_head);
    print_list(list_head);
    
    printf("List state after adding elements to head: ");
    add_node_head(50,&list_head);
    add_node_head(1,&list_head);
    print_list(list_head);
    
    printf("List state after sorting: ");
    sort_list(&list_head);
    print_list(list_head);
    
    printf("List state after deletion of 15: ");
    delete_node(15,&list_head);
    print_list(list_head);
    
    printf("List state after reversal:"); 
    reverse_list(&list_head);
    print_list(list_head);
    
    printf("List state after reversal:"); 
    reverse_list(&list_head);
    print_list(list_head);
    
    return (EXIT_SUCCESS);
}

