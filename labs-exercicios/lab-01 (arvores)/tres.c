#include <stdio.h>
#include <stdlib.h>
#include "..\..\bibliotecas\arvore-binaria-busca\TABB.h"
#include "..\..\bibliotecas\lista-simp-encadeada\TLSE.h"

TLSE* ancestrais(TABB* arv, int x) {
    if(!arv) return NULL;

    TLSE* l = TLSE_inicializa();
    if(x < arv->info) l = ancestrais(arv->esq, x);
    else if(x > arv->info) l = ancestrais(arv->dir, x);
    
    if(arv->info != x) l = TLSE_insere(l, arv->info);
    return l;
}

int main(void) {
    TABB* arv = TABB_inicializa();

    int n;
    do {
        scanf("%d", &n);
        if(n < 0) break;
        arv = TABB_insere(arv, n);
    } while(1);

    TLSE* l = TLSE_inicializa();
    
    printf("Insira o x: \n");
    scanf("%d", &n);
    l = ancestrais(arv, n);

    TLSE_imprime(l);
    TLSE_libera(l);

    return 0;
}
