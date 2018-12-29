/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   expressions.h
 * Author: trabdlkarim
 *
 */

#ifndef EXPRESSIONS_H
#define EXPRESSIONS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
    
struct eleman{
    int tip;
    int islenen;
    int oncelik;
    char islem;
    struct eleman *ileri;
};

struct liste{
    struct eleman *bas;
    struct eleman *son;
};


struct eleman* yeni_islenen(int islenen);
struct eleman* yeni_islem(char islem);
struct liste* yeni_liste();
void liste_sonuna_ekle(struct liste* l, struct eleman* yeni);
void liste_yaz(struct liste* l);
void yigina_eleman_ekle(struct eleman **yigin_isaretcisi,struct eleman *e);
int yigin_bosmu(struct eleman *yigin_isaretcisi);
struct eleman* yigindan_eleman_cikar(struct eleman **yigin_isaretcisi);
struct eleman* yigin_ust(struct eleman *yigin_isaretcisi);
void infix_olustur(struct liste **l);
void postfix_olustur(struct liste *in, struct liste **out);
int postfix_hesapla(struct liste *in);


#ifdef __cplusplus
}
#endif

#endif /* EXPRESSIONS_H */

