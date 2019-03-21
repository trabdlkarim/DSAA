
/* 
 * File:   dynamicstack.h
 * Author: trabdlkarim
 *
 */
#include<stdlib.h>
#include<stdio.h>

#include "../include/dynamicstack.h"

Node* create_node(int value){
    
    Node *new_node;
    new_node = (Node*)malloc(sizeof(Node));
    
    if(new_node==NULL){
        printf("Memory fault, no space in the heap segment.\n");
        exit(1);
    }
    new_node->num = value;
    new_node->link = NULL;
    
    return new_node;
}

void push(int value,Node **head){
    Node* node = create_node(value);
    node->link = *head;
    *head = node;
}
void print_stack(Node* head){
    printf("[");
    while(head != NULL){
        printf("%4d ",head->num);
        head = head->link;
    }
     printf("]");
    printf("\n");
}

int pop(Node**head){
    if(*head == NULL) return SENTINEL;
    Node *node = *head;
    *head = (*head)->link;
    int value = node->num;
    free(node);
    
    return value;
}
int peek(Node* head){
    if(head == NULL) return SENTINEL;
    else return head->num;
}

int is_stack_full(Node *head){
    if(head == NULL) return 1;
    else return 0;
}

