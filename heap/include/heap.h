/* 
 * File:   heap.h
 * Author: trabdlkarim
 *
 */

#ifndef HEAP_H
#define HEAP_H

#ifdef __cplusplus
extern "C" {
#endif

struct dugum{
    int key;
    // istenilen diger bilgiler
};

struct heap{
    struct dugum *dizi;
    int kapasite;
    int eleman_sayisi;
};

struct heap *heap_olustur(int kapasite);
void heap_olustur_yeni(struct heap **h,int kapasite);
void print_heap(struct heap *heap);
void initialize_heap(struct heap *heap,int eleman_sayisi, int aralik);
void buble_down(struct heap *heap, int index);
void heapify(struct heap *heap);
void buble_up(struct heap *heap, int index);
void heap_insert(struct heap *heap,int key);
void delete_max(struct heap *heap);
void heap_sort(struct heap *heap);
int heap_mi(struct heap* h);


#ifdef __cplusplus
}
#endif

#endif /* HEAP_H */

