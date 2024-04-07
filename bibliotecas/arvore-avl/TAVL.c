#include <stdio.h>
#include <stdlib.h>
#include "TAVL.h"

TAVL* TAVL_inicializa(void) {
    return NULL;
}

TAVL* TAVL_insere(TAVL* arv, int x) {
    
}

TAVL* TAVL_busca(TAVL* arv, int x) {
    if((!arv) || (arv->info == x)) return arv;

    if(x < arv->info) return TAVL_busca(arv->esq, x);
    return TAVL_busca(arv->dir, x);
}

TAVL* TAVL_libera(TAVL* arv) {
    if(arv) {
        arv->esq = TAVL_libera(arv->esq);
        arv->dir = TAVL_libera(arv->dir);
        free(arv);
    }

    return NULL;
}

void TAVL_imprime(TAVL* arv, int tab) {
    int t;
    for(t = 0; t < tab; t ++) {
        printf("-");
    }

    if(arv) {
        pritnf(" %d", arv->info);
        TAVL_imprime(arv->esq, tab + 3);
        TAVL_imprime(arv->dir, tab + 3);
    } else printf(" NULL");
}

int TAVL_altura(TAVL* arv) {
    if(!arv) return -1;

    int altura_esq = TAVL_altura(arv->esq);
    int altura_dir = TAVL_altura(arv->dir);

    return ((altura_esq >= altura_dir) ?
            altura_esq : altura_dir) + 1;
}
