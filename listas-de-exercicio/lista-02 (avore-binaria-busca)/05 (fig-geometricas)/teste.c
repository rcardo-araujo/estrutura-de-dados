#include <stdlib.h>
#include <stdio.h>
#include "TAFG.h"
#include "TFG.h"

int main(void) {
    TAFG* arv = TAFG_inicializa();

    int n;
    do {
        printf("[1] Quadrado\n[2] Retangulo\n[3] Triangulo\n[4] Trapezio\n");
        scanf(" %d", &n);
        if((n < 0) || (n > 4)) break;
        arv = TAFG_insere(arv, n);
    } while(1);

    TAFG_imprime(arv, 0);

    return 0;
}
