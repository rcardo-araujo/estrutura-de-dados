#include <stdio.h>
#include <stdlib.h>
#include "..\..\bibliotecas\arvore-binaria-busca\TABB.h"

int estbin(TABB* arv) {
    if(!arv) return 0;
    if((!arv->esq && arv->dir) ||
        (arv->esq && !arv->dir))
        return 0;
    if(!arv->esq && !arv->dir) return 1;
    
    return estbin(arv->esq) && estbin(arv->dir);
}

int main(void) {
    TABB* arv = TABB_inicializa();

    int n;
    do {
        scanf("%d", &n);
        if(n < 0) break;
        arv = TABB_insere(arv, n);
    } while(1);

    if(estbin(arv)) printf("Estritamente binaria\n");
    else printf("Nao estritamente binaria\n");

    return 0;
}
