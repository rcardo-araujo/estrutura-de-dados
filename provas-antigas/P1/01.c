#include <stdio.h>
#include <stdlib.h>
#include "..\..\bibliotecas\arvore-avl\TAVL.h"
#include "..\..\bibliotecas\lista-simp-encadeada\TLSE.h"

TLSE* entreAux(TAVL* a, TLSE* l, int n, int m) {
    if(a->esq) l = entreAux(a->esq, l, n, m);
    if((a->info >= n) && (a->info <= m)) 
        l = TLSE_insere_fim_rec(l, a->info);
    if(a->dir) l = entreAux(a->dir, l, n, m);
    return l;
}

TLSE* entre(TAVL* a, int n, int m) {
    if(!a) return NULL;
    TLSE* l = TLSE_inicializa();
    l = entreAux(a, l, n, m);
    return l;
}

int main(void) {
    TAVL* a = TAVL_inicializa();

    int n, m;
    printf("Insira os nos: ");
    do{
        scanf("%d", &n);
        if(n < 0) break;
        a = TAVL_insere(a, n);
    } while(1);

    printf("Insira o limite minimo e maximo: ");
    scanf("%d %d", &n, &m);
    TLSE_imprime(entre(a, n, m));

    return 0;
}
