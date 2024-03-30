#include <stdio.h>
#include <stdlib.h>
#include ".\TAB.h"

TAB* TAB_inicializa() {
    return NULL;
}

TAB* TAB_cria(int info, TAB* esq, TAB* dir) {
    TAB* novo = (TAB *)malloc(sizeof(TAB));
    novo->info = info;
    novo->esq = esq;
    novo->dir = dir;

    return novo;
}

TAB* TAB_busca(int info, TAB* raiz) {
    if((!raiz) || (raiz->info == info))
        return raiz;
    
    TAB* resp = TAB_busca(info, raiz->esq);
    
    return (resp) ? resp : TAB_busca(info, raiz->dir);
}

void TAB_imprime(int tab, TAB* raiz) {
    int i;
    for(i = 0; i < tab; i ++)
        printf("-");

    if(raiz) {
        printf("%d\n", raiz->info);
        TAB_imprime(tab + 2, raiz->esq);
        TAB_imprime(tab + 2, raiz->dir);
    } else printf("NULL\n");
}

TAB* TAB_libera(TAB* raiz) {
    if(raiz) {
        TAB_libera(raiz->esq);
        TAB_libera(raiz->dir);
        free(raiz);
    }

    return NULL;
}

int TAB_altura(TAB* raiz) {
    if(!raiz) return -1;

    int altura_esq = TAB_altura(raiz->esq);
    int altura_dir = TAB_altura(raiz->dir);

    return ((altura_esq >= altura_dir) ?
            altura_esq : altura_dir) + 1;
}
