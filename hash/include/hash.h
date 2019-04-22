/* 
 * File:   hash.h
 * Author: trabdlkarim
 */

#ifndef HASH_H
#define HASH_H

#ifdef __cplusplus
extern "C" {
#endif


typedef struct cell {
    char *key;
    struct cell *next;
}Cell;

typedef struct table_node{
    int counter;
    Cell *header;
}TNode;


typedef struct hash_table{
    TNode *table_head;
    int size;
    int multiplier;
}HashTable;

int lookup(char *key, Cell *l);
int insert(char *key, Cell **l);
void print_list(Cell *l);
unsigned hash(char *key, int multiplier, int table_size);
void initialize_hash_table(HashTable **hash_table, int multiplier, int table_size);
void insert_hash_table(HashTable *hash_table, char *key);
void print_hash_table(HashTable *hash_table);
int  delete_list_node(Cell **header,char *key);
void delete_hash_table(HashTable *table, char *key);
void distroy_table_list(Cell **list_head);
void distroy_hash_table(HashTable **hash_table);
void scale_hash_table(HashTable **htable, int multiplier, int size);

#ifdef __cplusplus
}
#endif

#endif /* HASH_H */

