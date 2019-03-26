/* 
 * File:   main.c
 * Author: trabdlkarim
 */

#include <stdio.h>
#include <stdlib.h>

#include "include/heap.h"

/*
 * 
 */
int main(int argc, char** argv) {
    struct heap *heap=heap_olustur(4);
    initialize_heap(heap,4,101);
    print_heap(heap);
    printf("heap mi: %d\n",heap_mi(heap));
    heapify(heap);
    print_heap(heap);
    
    printf("heap mi: %d\n",heap_mi(heap));
    return (EXIT_SUCCESS);
}

