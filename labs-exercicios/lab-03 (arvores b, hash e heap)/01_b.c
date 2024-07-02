#include <stdio.h>
#include <stdlib.h>
#include "..\..\bibliotecas\arvore-b\TARVB.h"
#include "..\..\bibliotecas\lista-simp-encadeada\TLSE.h"

void aux(TARVB* a, TLSE** l, int n) {
    if(!a) return;

    int i;
    for(i = 0; i < a->nchaves; i++) {
        if(a->chave[i] > n) {
            if(!i) aux(a->filho[i], l, n);
            *l = TLSE_insere(*l, a->chave[i]);
        }
        aux(a->filho[i + 1], l, n);
    }
}

TLSE* mN(TARVB* a, int n) {
    TLSE* l = TLSE_inicializa();
    aux(a, &l, n);
    return l;
}

int main(void) {
    TARVB* a = TARVB_Inicializa();

    int n;
    do {
        scanf("%d", &n);
        if(n < 0) break;
        a = TARVB_Insere(a, n, 2);
    } while(1);

    TLSE* l = mN(a, 10);
    TLSE_imprime(l);

    return 0;
}
