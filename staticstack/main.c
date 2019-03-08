/* 
 * File:   main.c
 * Author: trabdlkarim
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "include/staticstack.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
   Stack *A=NULL;
   Stack *B=NULL;

   int deleted;

   A = create_static_stack(10);
   // set_static_stack_attr(10,&A);

   push(12,A);
   push(56,A);
   push(-20,A);
   print_stack(A);
   
   deleted = pop(A);
   printf("Deleted: %4d\n",deleted);
   print_stack(A);
   
   push(100,A);
   print_stack(A);
   
   increase_stack_capacity_2(&A,3);
   print_stack(A);
    
    return (EXIT_SUCCESS);
}

