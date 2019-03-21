/* 
 * File:   main.c
 * Author: trabdlkarim
 */

#include <stdio.h>
#include <stdlib.h>

#include "include/dynamicstack.h"

/*
 * 
 */
int main(int argc, char** argv) {
    Node* head = NULL;
    push(100,&head);
    push(20,&head);
    push(60,&head);
    push(70,&head);
    push(80,&head);
    push(50,&head);
    push(10,&head);
    push(90,&head);
    print_stack(head);
    
    
    int popped = pop(&head);
    if(popped != SENTINEL) printf(" %4d \n",popped);
    print_stack(head);
    
    return (EXIT_SUCCESS);
}

