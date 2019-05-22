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

Node* creat_node(int key);


#ifdef __cplusplus
}
#endif

#endif /* AVLTREE_H */

