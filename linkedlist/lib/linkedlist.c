#include<stdlib.h>
#include<stdio.h>

#include "../include/linkedlist.h"

Node* create_node(int value){
    
    Node *new_node;
    new_node = (Node*)malloc(sizeof(Node));
    
    if(new_node==NULL){
        printf("Memory fault, no space in the heap segment.\n");
        exit(1);
    }
    new_node->value = value;
    new_node->next = NULL;
}

void add_node_head(int value,Node **head){
    Node* node = create_node(value);
    node->next=*head;
    *head=node;
}

void add_node_tail(int value, Node** head){
    Node* node = create_node(value);
    if(*head==NULL){
        node->next = *head;
        *head = node;
    }
    else {
        Node* tmp =*head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next= tmp;
    }
}

void print_list(Node* head){
    while(head != NULL){
        printf("%4d ",head->value);
        head = head->next;
    }
    printf("\n");
}

void print_list_rec(Node* head){
    if(head != NULL) {
    printf("%4d ",head->value);
    print_list_rec(head->next);
    }  
    else{ 
        printf("\n");
    }
}
void rprint_list_rec(Node* head){
    
    if(head != NULL){
        rprint_list_rec(head->next);
        printf("%4d ",head->value);
    }
   
}
void delete_list(Node** head){
    Node *current;
    while(*head!=NULL){
        current = (*head);
        *head = (*head)->next;
        free(current);
    }
}

void add_node_in_order(int value, Node** head){
   Node *a, *b, *c;
   b=*head;
   while(b!=NULL && b->value <= value){
       if(b->value == value) return;
       a = b;
       b= b->next;
   }
   c = create_node(value);
   if(b==*head){
       c->next = *head;
       *head = c;
   }
   else {
       a->next = c;
       c->next = b;
       
   }
}

void delete_node(int value, Node** head){
    Node* temp = *head;
    Node* previous;
    
    while(temp!=NULL && temp->value!=value){
        previous = temp;
        temp=temp->next;
    }
    if(temp==NULL) return;
    else {
        if(temp == *head) *head = (*head)->next;
        else previous->next = temp->next;
        free(temp);
    }
        
   }

void sort_list(Node** head){
    Node *a,*b,*c,*d;
    
    if(*head == NULL || (*head)->next==NULL) return;
    
    d = (*head)->next;
    (*head)->next = NULL;
    
    while(d!=NULL){
        c=d;
        d=d->next;
        b=*head;
        while(b!=NULL && b->value < c->value){
            a=b;
            b=b->next;
        }
        if(b==*head){
            c->next=*head;
            *head=c;
        }
        else {
            a->next = c;
            c->next = b;
        }
        }
    }
 
void reverse_list(Node** head){
    
    Node *n1,*n2;
    n1=NULL;
    
    while(*head!=NULL){
        n2 = *head;
        *head = (*head)->next;
        n2->next = n1;
        n1 = n2;
    }
    *head=n1;
}
    
