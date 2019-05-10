/* 
 * File:   bstree.h
 * Author: trabdlkarim
 *
 */


#include <stdio.h>
#include <stdlib.h>

#include "../include/bstree.h"

void create_binary_search_tree(BSTree **tree){
    
    *tree = (BSTree*)malloc(sizeof(BSTree));
    
    if(*tree==NULL){
        printf("Memory fault no, space in the heap segment\n");
        exit(1);
    }
    
    (*tree)->root = NULL;  
}

int is_binary_tree_empty(BSTree *tree){
    
    if(tree->root == NULL) return 1;
    else return 0;
}

Node* create_node(int value){
    
    Node* node = (Node*) malloc(sizeof(Node));
    
    if(node == NULL){
        printf("Memory fault no, space in the heap segment\n");
        exit(1);
    }
    node->num = value;
    node->left = node->right = NULL;
    
    return node;
}


void insert_node(BSTree *tree, int value){
    
    Node *node, *parent, *previous;
    
    parent = tree->root;
    
    while(parent!=NULL){
        previous = parent;
        if(value < parent->num) parent = parent->left;
        else if(value > parent->num) parent = parent->right;
        else return;
    }
    
    node = create_node(value);
    if(tree->root==NULL){
        tree->root = node;
        return;
    }
    if(value < previous->num) previous->right = node;
    else previous->right = node;
    
}

void inorder(Node *root){
     
    if(root == NULL)return;
    inorder(root->left);
    printf("%4d",root->num);
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL)return;
    printf("%4d",root->num);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL)return;
    preorder(root->left);
    preorder(root->right);
    printf("%4d",root->num);
}

int count_tree_nodes(Node* root){
    if(root == NULL) return 0;
    return 1 + count_tree_nodes(root->left) + count_tree_nodes(root->right);
}

int count_tree_leaves(Node* root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    else return count_tree_leaves(root->left) + count_tree_leaves(root->right);
}

int count_tree_inner_nodes(Node* root){
    if(root == NULL) return 0;
    else if(root->left != NULL || root->right !=NULL) 
        return count_tree_inner_nodes(root->left) + count_tree_inner_nodes(root->right);

}
void delete_node(BSTree *tree, int value){
    
    Node *node = tree->root;
    Node *parent=NULL;
    Node *n1,*n2;
    int left;
    
    while(node != NULL){
        if(value < node->num){
            parent = node; 
            node = node->left; 
            left = 1;
        }
        else if(value > node->num){
            parent = node; 
            node = node->right; 
            left = 0;
        }
        else break;
    }
    
    if(node == NULL) return;
    if(node->left == NULL){
        if(parent == NULL) tree->root = node->right;
        else{
            if(left==1) parent->left = node->right;
            else parent->right = node->right;
        }
    }
    else if(node->right == NULL){  
        if(parent==NULL) tree->root = node->left;
        else {
            if(left == 1) parent->left = node->left;
            else parent->right = node->left;
        }
    }
     else { 
        n1 = node->right;
        n2 = NULL;
        
        while(n1->left!=NULL){
            n2 = n1;
            n1 = n1->left;
        }
        if(n2 != NULL){
            n2->left = n1->right;
            n1->right = node->right;
        }
        
        n1->left = node->left;
        
        if(parent==NULL) tree->root = n1; 
        else {
            if(left == 1) parent->left = n1;
            else parent->right = n1;
        }
    }
    
    free(node); 
}


void distroy_tree(Node **root){
    if(*root != NULL){
        
        distroy_tree(&(*root)->left);
        distroy_tree(&(*root)->right);
        
        free(*root);
        
        *root = NULL;
    }
}

int depth(Node* node){
   
   int right = depth(node->right)+1;
   int left = depth(node->left)+1;
   return left > right? left:right;
}
    
    