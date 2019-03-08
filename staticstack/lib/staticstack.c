/* 
 * File:   staticstack.h
 * Author: trabdlkarim
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "../include/staticstack.h"

Stack* create_static_stack(int size){
    
    if(size<=0) {
        printf("Size must be a positive integer... ");
        exit(1);
    } 
    
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    
    stack->array = (int *)malloc(size*sizeof(int));
    stack->count = -1;
    stack->size = size;
    
    return stack;
}

void set_static_stack_attr(int size, Stack **stack){
    
    if(size<=0) {
        printf("Size must be a positive integer... ");
        exit(1);
    }
    
    *stack = (Stack*)malloc(sizeof(Stack));
    
    (*stack)->array = (int *)malloc(size*sizeof(int));
    (*stack)->count = -1;
    (*stack)->size = size;
    
}

int is_stack_full(Stack *s){
    if(s->count ==  s->size-1) return 1;
    else return 0;
}

int is_stack_empty(Stack *s){
    if(s->count == -1) return 1;
    else return 0;
}

void push(int element,Stack *stack){
    
    if(is_stack_full(stack)){
        printf("Stack is full, can't push element...");
        return;
    }
    
    stack->array[++stack->count] = element;
}

void print_stack(Stack* stack){
  
    printf("Stack capacity: %4d\n",stack->size);
    printf("Stack elements count: %4d\n",stack->count+1);
    printf("[");
    for(int i=stack->count;i>=0;i--){
        printf("%4d",stack->array[i]);
    }
    printf("]\n");
}

int pop(Stack* stack){

     if(is_stack_full(stack)){
       printf("Stack is full, can't pop element...\n");
       return SENTINEL;
     }
     
     return stack->array[stack->count--];
}

int peek(Stack* stack){

     if(is_stack_full(stack)){
       printf("Stack is full, can't peek element...\n");
       return SENTINEL;
     }
     
     return stack->array[stack->count];
}

Stack* increase_stack_capacity_1(Stack **stack, int n){
    Stack* new_stack;
    new_stack = create_static_stack(n*((*stack)->size));
    
    for(int i=0; i<=(*stack)->count; i++) new_stack->array[i] = (*stack)->array[i];
    new_stack->count = (*stack)->count;
    delete_stack(&(*stack)); // equivalent to delete_stack(stack);
    return new_stack;
}

void increase_stack_capacity_2(Stack **stack, int n){
    Stack* new_stack;
    new_stack = create_static_stack(n*((*stack)->size));
    
    for(int i=0; i<=(*stack)->count; i++) new_stack->array[i] = (*stack)->array[i];
    
    new_stack->count = (*stack)->count;
    delete_stack(&(*stack)); // equivalent to delete_stack(stack);
    
    *stack = new_stack;
}

void delete_stack(Stack** stack){
    free((*stack)->array);
    free(*stack);
    *stack = NULL;
}