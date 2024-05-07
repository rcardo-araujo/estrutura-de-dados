#include <stdio.h>
#include <stdlib.h>
#include "..\..\bibliotecas\arvore-binaria-busca\TABB.h"

int comp(const void* a, const void* b) {
    return *(int *)a - *(int *)b;
}

int nn(TABB* arv) {
    if(!arv) return 0;

    return nn(arv->esq) +
        nn(arv->dir) + 1;
}

void pVet(TABB* arv, int* resp, int* pos) {
    if(!arv) return;

    pVet(arv->esq, resp, pos);
    resp[(*pos)++] = arv->info;
    pVet(arv->dir, resp, pos);
}

int mi(TABB* a1, TABB* a2) {
    if(!a1 && !a2) return 1;

    int tam = nn(a1);
    if(tam != nn(a2)) return 0;

    int* vet1 = (int *)malloc(sizeof(int) * tam);
    int* vet2 = (int *)malloc(sizeof(int) * tam);

    int pos = 0;
    pVet(a1, vet1, &pos); pos = 0;
    pVet(a2, vet2, &pos);

    qsort(vet1, tam, sizeof(int), comp);
    qsort(vet2, tam, sizeof(int), comp);

    int i;
    for(i = 0; i < tam; i ++)
        if(vet1[i] != vet2[i])
            return 0;
    
    return 1;
}

int main(void) {
    TABB* arv1 = TABB_inicializa();
    TABB* arv2 = TABB_inicializa();

    int n;
    do {
        scanf("%d", &n);
        if(n < 0) break;
        arv1 = TABB_insere(arv1, n);
    } while(1);

    do {
        scanf("%d", &n);
        if(n < 0) break;
        arv2 = TABB_insere(arv2, n);
    } while(1);

    if(mi(arv1, arv2)) printf("Mesmas infos\n");
    else printf("Nao possuem as mesmas infos\n");

    return 0;
}
