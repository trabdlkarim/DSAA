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
    Node *list_head=NULL;
    
    add_node_tail(20,&list_head);
    add_node_tail(10,&list_head);
    add_node_tail(15,&list_head);
    add_node_tail(50,&list_head);
    add_node_tail(1,&list_head);
    
    print_list(list_head);
    /*
    sort_list(&list_head);
    print_list(list_head);
     
    delete_node(15,&list_head);
    print_list(list_head);
     
    reverse_list(&list_head);
    print_list(list_head);
    
    reverse_list(&list_head);
    print_list(list_head);
    */
    return (EXIT_SUCCESS);
}

