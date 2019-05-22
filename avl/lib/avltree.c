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

Node* creat_node(int key){
    struct node *node=(struct node*)malloc(sizeof(struct node));
    node->key=key;
    node->left=node->right=NULL;
    node->height=1;
    return node;
}

