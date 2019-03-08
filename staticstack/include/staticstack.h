/* 
 * File:   staticstack.h
 * Author: trabdlkarim
 *
 */

#ifndef STATICSTACK_H
#define STATICSTACK_H

#ifdef __cplusplus
extern "C" {
#endif

#define SENTINEL -10000000

typedef struct static_stack{
    int *array;
    int count;
    int size;
}Stack; 

Stack* create_static_stack(int size);
void set_static_stack_attr(int size, Stack **stack);

int is_stack_full(Stack *s);
int is_stack_empty(Stack *s);

void push(int element,Stack *stack);

void print_stack(Stack* stack);

int pop(Stack* stack);
int peek(Stack* stack);

Stack* increase_stack_capacity_1(Stack **stack, int n);
void increase_stack_capacity_2(Stack **stack, int n);

void delete_stack(Stack** stack);

#ifdef __cplusplus
}
#endif

#endif /* STATICSTACK_H */

