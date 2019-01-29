/* 
 * File:   linkedlist.h
 * Author: trabdlkarim
 *
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct node {
    int value;
    struct node *next;
} Node;

Node* create_node(int value);

void add_node_head(int value, Node **head);
void add_node_tail(int value, Node** head);
void add_node_in_order(int value, Node** head);

void print_list(Node* head);
void print_list_rec(Node* head);
void rprint_list_rec(Node* head);

void delete_list(Node** head);
void delete_node(int value, Node** head);

void reverse_list(Node** head);
void sort_list(Node** head);


#ifdef __cplusplus
}
#endif

#endif /* LINKEDLIST_H */

