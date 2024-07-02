#include <stdio.h>
#include <stdlib.h>
#include "..\..\bibliotecas\tabela-hash\mem-principal\TH.h"

int main(void) {
    TH tab;
    TH_inicializa(tab, 7);
    int n;
    do {
        scanf("%d", &n);
        if(n < 0) break;
        TH_insere(tab, 7, n, 7);
    } while(1);

    TH_imprime(tab, 7);

    return 0;
}
