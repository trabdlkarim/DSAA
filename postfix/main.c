/* 
 * File:   main.c
 * Author: trabdlkarim
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "include/expressions.h"
/*
 * 
 */
int main(int argc, char** argv) {
    
    struct liste* l1;
    struct liste* l2;
    int sonuc;
    infix_olustur(&l1);
    liste_yaz(l1);
    postfix_olustur(l1, &l2);
    liste_yaz(l2);
    sonuc=postfix_hesapla(l2);
    printf("Sonuc: %d\n",sonuc);
    
    return (EXIT_SUCCESS);
}

