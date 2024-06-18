#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "..\..\bibliotecas\arvore-b\TARVB.h"

// 01
int suc(TARVB* a, int elem);

// 02
TARVB* maior(TARVB* a) {
    if((!a) || (a->folha)) return a;

    return maior(a->chave[a->nchaves]);
}

// 03
TARVB* menor(TARVB* a) {
    if((!a) || (a->folha)) return a;

    return menor(a->filho[0]);
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
    printf("\n");
    TARVB_Imprime(maior(a));
}
