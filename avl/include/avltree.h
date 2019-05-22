/* 
 * File:   avltree.h
 * Author: trabdlkarim
 *
 */

#ifndef AVLTREE_H
#define AVLTREE_H

#ifdef __cplusplus
extern "C" {
#endif

 typedef struct node{
    int key;
    struct node *left;
    struct node *right;
    int height;
}Node;

int max(int a, int b);

Node* create_node(int key);

Node* right_rotate(Node *y);
Node* left_rotate(Node* x);
Node *insert(Node*node, int key);
int get_balance(Node* node);

Node* get_min_value_node(Node* root);
void preorder(Node* root);
void preorder_helper(Node* node);
#ifdef __cplusplus
}
#endif

#endif /* AVLTREE_H */

