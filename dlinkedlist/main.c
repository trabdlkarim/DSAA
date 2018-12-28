/* 
 * File:   main.c
 * Author: trabdlkarim
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "include/doublelinkedlist.h"
/*
 * 
 */
int main(int argc, char** argv) {
    
    DLinkedList* list;
    init_list(&list);
    
    add_node_head(40,list);
    add_node_head(50,list);
    add_node_head(60,list);
    
    add_node_tail(70,list);
    add_node_tail(80,list);
    add_node_tail(90,list);
    
    print_list(list);
    print_list_reverse(list);
    
    return (EXIT_SUCCESS);
}

