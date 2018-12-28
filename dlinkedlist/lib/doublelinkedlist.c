/* 
 * File:   doublelinkedlist.c
 * Author: trabdlkarim
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/doublelinkedlist.h"
/*
 * 
 */

Node* create_node(int value){
    
    Node *new_node;
    new_node = (Node*)malloc(sizeof(Node));
    
    if(new_node==NULL){
        printf("Memory fault, no space in the heap segment.\n");
        exit(1);
    }
    new_node->value = value;
    new_node->previous = new_node->next = NULL;
    
    return new_node;
}


void init_list(DLinkedList **list){
    *list = (DLinkedList*)malloc(sizeof(DLinkedList));
    if(*list==NULL){
        printf("Memory fault, no space in the heap segment.\n");
        exit(1);
    }
    (*list)->head = (*list)->tail = NULL;
}

void add_node_head(int value, DLinkedList *list){
    Node *new_node ;
    new_node = create_node(value);
    
    if(list->tail== NULL) list->tail = new_node;
    else{
        list->head->previous = new_node;
        new_node->next = list->head;
    }
    list->head = new_node;  
}

void add_node_tail(int value,DLinkedList *list){
    Node *new_node;
    new_node = create_node(value);
    if(list->head == NULL) list->head = new_node;
    else {
        list->tail->next = new_node;
        new_node->previous = list->tail;
    }
    list->tail = new_node ;
}

void print_list(DLinkedList *list){
    Node *head = list->head;
    printf("[");
    while(head!=NULL){
        printf("%4d ",head->value);
        head = head->next;
    }
    printf("]");
    printf("\n");
}

void print_list_reverse(DLinkedList *list){
    Node *tail = list->tail;
    printf("[");
    while(tail!=NULL){
        printf("%4d ",tail->value);
        tail = tail->previous;
    }
    printf("]");
    printf("\n");
    
}
