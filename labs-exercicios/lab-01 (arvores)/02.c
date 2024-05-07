#include <stdio.h>
#include <stdlib.h>
#include "..\..\bibliotecas\arvore-binaria-busca\TABB.h"

int zzD(TABB* arv) {
    if(!arv) return 1;
    if(arv->dir && arv->esq) return 0;

    if(arv->esq) return zzD(arv->esq);
    return zzD(arv->dir);
}

int zz(TABB* arv) {
    if((!arv) || (!arv->esq && !arv->dir)) return 0;

    return zzD(arv->esq) && zzD(arv->dir);
}

int main(void) {
    TABB* arv = TABB_inicializa();
    
    int n;
    do {
        scanf("%d", &n);
        if(n < 0) break;
        arv = TABB_insere(arv, n);
    } while(1);

    printf(((zz(arv)) ? "E zig zag\n" : "Nao e zig zag\n"));

    return 0;
}