/* 
 * File:   main.c
 * Author: trabdlkarim
 */

#include <stdio.h>
#include <stdlib.h>

#include "include/bstree.h"
/*
 * 
 */
int main(int argc, char** argv) {
    
    BSTree *tree;
    create_binary_search_tree(&tree);
    
    insert_node(tree,100);
    insert_node(tree,50);
    insert_node(tree,200);
    insert_node(tree,25);
    insert_node(tree,75);
    insert_node(tree,20);
    insert_node(tree,35);
    insert_node(tree,98);
    insert_node(tree,99);
    insert_node(tree,500);
    insert_node(tree,400);
    insert_node(tree,300);
    insert_node(tree,210);
    insert_node(tree,375);
    insert_node(tree,30);
    insert_node(tree,173);
    
    inorder(tree->root);
   
    printf("\nNodes count: %4d\n",count_tree_nodes(tree->root));

    return (EXIT_SUCCESS);
}

