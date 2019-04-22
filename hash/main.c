/* 
 * File:   main.c
 * Author: trabdlkarim
 */

#include <stdio.h>
#include <stdlib.h>

#include "include/hash.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
     HashTable *htable=NULL;
    
    initialize_hash_table(&htable,3,5);
    print_hash_table(htable); 
    insert_hash_table(htable,"Lisa Smith");
    insert_hash_table(htable,"John Smith");
    insert_hash_table(htable,"John Doe");
    insert_hash_table(htable,"Jane Doe");
    insert_hash_table(htable,"Sandra Dee");
    insert_hash_table(htable,"Sam Doe");
    insert_hash_table(htable,"Ted Baker");
    insert_hash_table(htable,"Tayip Erdogan");
    
   
    print_hash_table(htable);
    
    scale_hash_table(&htable,17,19);
    print_hash_table(htable);
    
    insert_hash_table(htable,"Yaya Toure");
    insert_hash_table(htable,"Mariam Dembele");
    print_hash_table(htable);
    
    return (EXIT_SUCCESS);
}

