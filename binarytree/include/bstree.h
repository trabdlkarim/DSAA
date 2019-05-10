/* 
 * File:   bstree.h
 * Author: trabdlkarim
 *
 */

#ifndef BSTREE_H
#define BSTREE_H

#ifdef __cplusplus
extern "C" {
#endif

#define SENTINEL -100000000

typedef struct node {
    int num;
    struct node *left;
    struct node *right;
}Node;

typedef struct binary_search_tree{
    Node* root;
}BSTree;

void create_binary_search_tree(BSTree **tree);
int is_binary_tree_empty(BSTree *tree);

Node* create_node(int value);

void insert_node(BSTree *tree, int value);
void inorder(Node *root);
void preorder(Node* root);
void postorder(Node* root);

int count_tree_nodes(Node* root);
int count_tree_leaves(Node* root);
int count_tree_inner_nodes(Node* root);

void delete_node(BSTree *tree, int value);
void distroy_tree(Node **root);
int depth(Node* node);

#ifdef __cplusplus
}
#endif

#endif /* BSTREE_H */

