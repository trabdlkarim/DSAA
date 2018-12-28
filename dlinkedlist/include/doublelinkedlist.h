/* 
 * File:   doublelinkedlist.h
 * Author: trabdlkarim
 *
 */

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct node{
    int value;
    struct node *next;
    struct node *previous;
}Node;

typedef struct dlinkedlist{
    Node *head;
    Node *tail;
}DLinkedList;

Node* create_node(int value);
void init_list(DLinkedList **list);
void add_node_head(int value, DLinkedList *list);
void add_node_tail(int value,DLinkedList *list);
void print_list(DLinkedList *list);
void print_list_reverse(DLinkedList *list);

#ifdef __cplusplus
}
#endif

#endif /* DOUBLELINKEDLIST_H */

