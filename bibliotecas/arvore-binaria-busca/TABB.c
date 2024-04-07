#include <stdlib.h>
#include <stdio.h>
#include "TABB.h"

TABB* TABB_inicializa(void) {
    return NULL;
}

TABB* TABB_cria(int info, TABB* esq, TABB* dir) {
    TABB* novo = (TABB *)malloc(sizeof(TABB));
    novo->info = info;
    novo->esq = esq;
    novo->dir = dir;

    return novo;
}

TABB* TABB_insere(TABB* arv, int x) {
    if(!arv) return TABB_cria(x, NULL, NULL);

    if(x < arv->info) arv->esq = TABB_insere(arv->esq, x);
    else if(x > arv->info) arv->dir = TABB_insere(arv->dir, x);

    return arv;
}

TABB* TABB_retira(TABB* arv, int x) {
    
}

TABB* TABB_busca(TABB* arv, int x) {
    if(!arv || (arv->info == x)) return arv;

    if(x < arv->info) return TABB_busca(arv->esq, x);
    return TABB_busca(arv->dir, x);
}

void TABB_imprime(TABB* arv, int tab) {
    int t;
    for(t = 0; t < tab; t ++)
        printf("-");
        
    if(arv) {
        printf(" %d\n", arv->info);
        TABB_imprime(arv->esq, tab + 3);
        TABB_imprime(arv->dir, tab + 3);
    } else printf(" NULL\n");
}

static int TABB_folha(TABB* no) {
    return !(no->esq || no->dir);
}
