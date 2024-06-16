#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "..\..\bibliotecas\arvore-b\TARVB.h"

// 05
TARVB* retira_pares(TARVB* a);

// 06
int ni(TARVB* a) {
    if(!a || a->folha) return 0;

    int i, n = 1;
    for(i = 0; i <= a->nchaves; i ++) {
        n += ni(a->filho[i]);
    }

    return n;
}

// 07
int nf(TARVB* a) {
    if(!a) return 0;
    if(a->folha) return 1;

    int i, n = 0;
    for(i = 0; i <= a->nchaves; i ++) {
        n += nf(a->filho[i]);
    }

    return n;
}

int main(void) {
    TARVB* a = TARVB_Inicializa();

    int t, n;
    printf("Digite o grau da arvore: ");
    scanf("%d", &t);

    printf("Insercao de numeros: ");
    do {
        scanf("%d", &n);
        if(n < 0) break;
        a = TARVB_Insere(a, n, t);
    } while(1);

    TARVB_Imprime(a);
    printf("\nNos folha: %d\n", nf(a));
    printf("Nos internos: %d\n", ni(a));
}
