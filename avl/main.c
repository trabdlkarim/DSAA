/* 
 * File:   main.c
 * Author: trabdlkarim
 */

#include <stdio.h>
#include <stdlib.h>

#include"include/avltree.h"
/*
 * 
 */
int main(int argc, char** argv) {
    
    Node *root=NULL;
    
    root = insert(root,40);
    root = insert(root,35);
    root = insert(root,38);
    root = insert(root,60);
    root = insert(root,80);
    root = insert(root,50);
    root = insert(root,21);
    
    preorder(root);
    
    return (EXIT_SUCCESS);
}

