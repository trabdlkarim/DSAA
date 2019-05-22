/* 
 * File:   avltree.c
 * Author: trabdlkarim
 */

#include <stdio.h>
#include <stdlib.h>

#include "../include/avltree.h"

int max(int a, int b){
    return a>b ? a:b;
}

Node* create_node(int key){
    Node *node=(Node*)malloc(sizeof(Node));
    node->key=key;
    node->left=node->right=NULL;
    node->height=1;
    return node;
}

int height(Node *node){
    if(node==NULL) return 0;
    return node->height;
}


Node* right_rotate(Node *y){
    Node *x=y->left, *T=x->right;
    x->right=y;
    y->left = T;
    
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1; 
    
    return x;
} 

Node* left_rotate(Node* x){
    struct node *y=x->right, *T=y->left;
    y->left=x;
    x->right = T;
    
    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;
    
    return y;
} 

int get_balance(Node* node){
    if(node==NULL) return 0;
    return height(node->left) - height(node->right);
}

Node* insert(Node* node, int key){
    
    int balance;
    if(node==NULL) return create_node(key);
    if(key<node->key) node->left = insert(node->left,key);
    else node->right = insert(node->right,key);
    
    node->height = max(height(node->left),height(node->right)) +1;
    
    balance = get_balance(node);
    
    if(balance>1 && key < node->left->key) 
        return right_rotate(node);
    if(balance<-1 && key > node->right->key) 
        return left_rotate(node);
    if(balance>1 && key>node->left->key){ 
        node->left=left_rotate(node->left);
        return right_rotate(node);
    }
    if(balance<-1 && key<node->right->key){  
        node->right=right_rotate(node->right);
        return left_rotate(node);
    }
    
    return node;
}

Node* get_min_value_node(Node* root){
    Node* current = root;
    if(current == NULL) return NULL;
    while(current->left) current=current->left;
    return current;
}

void preorder_helper(Node* node) {
    if(node!=NULL){
        printf("%d (%2d) ",node->key,node->height);
        preorder_helper(node->left);
        preorder_helper(node->right);
    }
    
}
void preorder(Node* root){
    preorder_helper(node);
    printf("\n");
}
