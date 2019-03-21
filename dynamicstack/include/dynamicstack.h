
/* 
 * File:   dynamicstack.h
 * Author: trabdlkarim
 *
 */

#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H

#ifdef __cplusplus
extern "C" {
#endif

#define SENTINEL -100000000

typedef struct node{
   int num;
   struct node *link;
}Node;

Node* create_node(int value);

void push(int value,Node **head);
int pop(Node**head);
int peek(Node* head);

int is_stack_full(Node *head);

void print_stack(Node* head);

#ifdef __cplusplus
}
#endif

#endif /* DYNAMICSTACK_H */

