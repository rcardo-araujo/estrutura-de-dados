#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "..\..\bibliotecas\arvore-b\TARVB.h"
#include ".\lib\TLSEINT.h"

TLSEINT* misc_aux(TARVB* a, TLSEINT* l, int n) {
    if(!a) return NULL;

    int i, lim_i = INT_MIN, lim_s = INT_MAX;
    for(i = 0; (i < a->nchaves) && (a->chave[i] < n); i++);
    if(i != 0) lim_i = a->chave[0];
    if((i < a->nchaves) && (a->chave[i] != n)) lim_s = a->chave[i];
    
    if(!(i < a->nchaves) || !(a->chave[i] == n)) {
        l = misc_aux(a->filho[i], l, n);
    }
    l = TLSEINT_insere(l, lim_i, lim_s);
    return l;
}

TLSEINT* misc(TARVB* a, int n) {
    if((!a) || (!TARVB_Busca(a, n))) return NULL;

    TLSEINT* l = TLSEINT_inicializa();
    return misc_aux(a, l, n);
}

int main(void) {
    TARVB* a = TARVB_Inicializa();

    int n;
    do {
        scanf("%d", &n);
        if(n < 0) break;
        a = TARVB_Insere(a, n, 2);
    } while(1);

    TARVB_Imprime(a);
    printf("\n");
    TLSEINT* l = misc(a, 11);
    TLSEINT_imprime(l);

    return 0;
}
