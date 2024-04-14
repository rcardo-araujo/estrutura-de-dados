#include <stdio.h>
#include <stdlib.h>
#include "TAVL.h"

TAVL* TAVL_inicializa(void) {
    return NULL;
}

static int maior(int a, int b) {
    if(a >= b) return a;
    return b;
}

static int altura(TAVL* arv) {
    if(!arv) return -1;

    return arv->alt;
}

static int fb(TAVL* arv) {
    if(!arv) return 0;
    
    return 
        (altura(arv->esq) + 1) -
        (altura(arv->dir) + 1);
}

static TAVL* rotacao_dir(TAVL* arv) {
    TAVL* a = arv->esq;
    arv->esq = a->dir;
    a->dir = arv;

    arv->alt = maior(
        altura(arv->dir),
        altura(arv->esq)) + 1;
    
    a->alt = maior(
        altura(a->esq),
        altura(arv)) + 1;

    return a;
}

static TAVL* rotacao_esq(TAVL* arv) {
    TAVL* a = arv->dir;
    arv->dir = a->esq;
    a->esq = arv;

    arv->alt = maior(
        altura(arv->esq),
        altura(arv->dir)) +1;
    
    a->alt = maior(
        altura(a->dir),
        altura(arv)) + 1;

    return a;
}

static TAVL* rotacao_esq_dir(TAVL* arv) {
    arv->esq = rotacao_esq(arv->esq);
    arv = rotacao_dir(arv);
    return arv;
}

static TAVL* rotacao_dir_esq(TAVL* arv) {
    arv->dir = rotacao_dir(arv->dir);
    arv = rotacao_esq(arv);
    return arv;
}

TAVL* TAVL_cria(int x) {
    TAVL* novo = (TAVL*)malloc(sizeof(TAVL));
    novo->info = x;
    novo->alt = 0;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

TAVL* TAVL_insere(TAVL* arv, int x) {
    if(!arv) return TAVL_cria(x);

    if(x < arv->info) {
        arv->esq = TAVL_insere(arv->esq, x);
        if(fb(arv) == 2) {
            if(fb(arv->esq) >= 0) {
                arv = rotacao_dir(arv);
            } else arv = rotacao_esq_dir(arv);
        }
    } 
    else if(x > arv->info) {
        arv->dir = TAVL_insere(arv->dir, x);
        if(fb(arv) == -2) {
            if(fb(arv->dir) <= 0) {
                arv = rotacao_esq(arv);
            } else arv = rotacao_dir_esq(arv);
        }
    }
    arv->alt = maior(
        altura(arv->esq),
        altura(arv->dir)) + 1;

    return arv;
}

TAVL* TAVL_retira(TAVL* arv, int x) {
    if(!arv) return arv;

    if(x > arv->info) {
        arv->dir = TAVL_retira(arv->dir, x);
        if(fb(arv) == 2) {
            if(fb(arv->esq) >= 0) {
                arv = rotacao_dir(arv);
            } else arv = rotacao_esq_dir(arv);
        }
    }
    else if(x < arv->info) {
        arv->esq = TAVL_retira(arv->esq, x);
        if(fb(arv) == -2) {
            if(fb(arv->dir) <= 0) {
                arv = rotacao_esq(arv);
            } else arv = rotacao_dir_esq(arv);
        }
    }
    else {
        if(arv->esq && arv->dir) {
            TAVL* aux = arv->esq;
            while(aux->dir) aux = aux->dir;
            arv->info = aux->info;
            aux->info = x;
            arv->esq = TAVL_retira(arv->esq, x);

            if(fb(arv) == -2) {
                if(fb(arv->dir) <= 0) {
                    arv = rotacao_esq(arv);
                } arv = rotacao_dir_esq(arv);
            }
        } else {
            TAVL* aux = arv;
            if(!arv->esq && !arv->dir) arv = NULL;
            else if(arv->esq) arv = arv->esq;
            else arv = arv->dir;
            free(aux);
        }
    }
    
    if(arv) {
        arv->alt = maior(
            altura(arv->esq),
            altura(arv->dir)) + 1;
    }

    return arv;
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
        printf(" %d\n", arv->info);
        TAVL_imprime(arv->esq, tab + 3);
        TAVL_imprime(arv->dir, tab + 3);
    } else printf(" NULL\n");
}
