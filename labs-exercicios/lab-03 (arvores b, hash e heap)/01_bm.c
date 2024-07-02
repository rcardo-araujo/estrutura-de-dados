#include <stdio.h>
#include <stdlib.h>
#include "..\..\bibliotecas\arvore-bm\TARVBM.h"
#include "..\..\bibliotecas\lista-simp-encadeada\TLSE.h"

TLSE* mN(TARVBM* a, int n) {
    TARVBM* p = TARVBM_busca(a, n);
    if(!p) return NULL;

    int i;
    TLSE* l = TLSE_inicializa();
    while(p) {
        for(i = 0; i < p->nchaves; i++) {
            if(p->chave[i] > n)
                l = TLSE_insere(l, p->chave[i]);
        }
        p = p->prox;
    }
    return l;
}

int main(void) {
    TARVBM* a = TARVBM_inicializa();

    int n;
    do {
        scanf("%d", &n);
        if(n < 0) break;
        a = TARVBM_insere(a, n, 2);
    } while(1);

    TLSE* l = mN(a, 10);
    TLSE_imprime(l);

    return 0;
}
