/* 
 * File:   hash.h
 * Author: trabdlkarim
 */

#include <stdio.h>
#include <stdlib.h>

#include "../include/hash.h"

int lookup(char *key, Cell *l){
    if(l==NULL) return 0;
    else if(!strcmp(key,l->key)) return 1;
    else return lookup(key,l->next);
}

int insert(char *key, Cell **l){
    if(*l==NULL){
        *l=(Cell*)malloc(sizeof(Cell));
        (*l)->key=(char*)malloc((strlen(key)+1)*sizeof(char));
        strcpy((*l)->key,key);
        (*l)->next=NULL;
        return 1;
    }
    else if(strcmp(key,(*l)->key)) 
        return insert(key, &((*l)->next));
    else return 0;
}

void print_list(Cell *l){
    if(l!=NULL){
        printf("%s ", l->key);
        print_list(l->next);
    }
    
}


unsigned hash(char *key, int multiplier, int table_size){
    int i=0;
    unsigned int value=0;
    while(key[i]){
        value = (key[i]+multiplier*value)% table_size;
        i++;
    }
    return value;
}

void initialize_hash_table(HashTable **hash_table, int multiplier, int table_size){
    int i;
    *hash_table=(HashTable*)malloc(sizeof(HashTable));
   if(*hash_table==NULL){
       printf("Memory fault can't initiate the hash map...!!!");
       exit(1);
   }    
    (*hash_table)->table_head = (TNode *)malloc(table_size*sizeof(TNode));
    if((*hash_table)->table_head==NULL){
       printf("Memory fault can't initiate the hash map...!!!");
       exit(1);
    }
    (*hash_table)->size= table_size;
    (*hash_table)->multiplier= multiplier;
    
    for(i=0; i<table_size; i++){
        ((*hash_table)->table_head+i)->counter = 0;
        ((*hash_table)->table_head+i)->header = NULL;
    }
}

void insert_hash_table(HashTable *hash_table, char *key){
    
    int hash_index = hash(key, hash_table->multiplier, hash_table->size);
    
    if(insert(key, &((hash_table->table_head + hash_index)->header)))
        (hash_table->table_head + hash_index)->counter++;
}

void print_hash_table(HashTable *hash_table){
    if(hash_table){
        int index;
        printf("----- HASH MAP -----\n");
        for(index=0; index < hash_table->size; index++){
            printf("%5d : (%2d) ",index,(hash_table->table_head +index)->counter);
            print_list((hash_table->table_head+index)->header);
            printf("\n");
        }
    }
    else printf("Hash Table is empty ...\n"); 
    
}

int delete_list_node(Cell **header,char *key){
    Cell *current,*previous;
    current = *header;
    while(current && strcmp(current->key, key)){
        previous = current;
        current = current->next;
    }
    if(!current) return 0;
    if(current == *header){
        *header=(*header)->next;
    }else {
        previous->next = current->next;
    }
    free(current->key);
    free(current);
    return 1;
}

void delete_hash_table(HashTable *table, char *key){
    
    int hash_index = hash(key,table->multiplier, table->size);
    
    if(delete_list_node(&((table->table_head + hash_index)->header),key))
    (table->table_head + hash_index)->counter--; 
}

void distroy_table_list(Cell **list_head){
    Cell *previous;
    while(*list_head){
        previous = *list_head;
        *list_head=(*list_head)->next;
        free(previous->key);
        free(previous);
    }
}

void distroy_hash_table(HashTable **hash_table){
    int index;
    if(*hash_table){
        for(index=0; index < (*hash_table)->size; index++)
            distroy_table_list(&((*hash_table)->table_head+index)->header);
        free((*hash_table)->table_head);
        free(*hash_table);
    }
    *hash_table=NULL;
    
}

void scale_hash_table(HashTable **htable, int multiplier, int size){
    int i;
    Cell *list_head;
    HashTable *new_table;
    
    if(*htable){
       initialize_hash_table(&new_table, multiplier,size);
    for(i=0; i< (*htable)->size; i++){
        list_head = ((*htable)->table_head+i)->header;
        while(list_head!=NULL){
            insert_hash_table(new_table,list_head->key);
            list_head = list_head->next;
        }
    }
    distroy_hash_table(htable);
    *htable = new_table;
    }   
}