#include <stdio.h>
#include <stdlib.h>
#include "..\..\bibliotecas\arvore-binaria-busca\TABB.h"

int nos_m_n(TABB* arv, int n) {
    if(!arv) return 0;

    int n_esq = 0;

    if(arv->info > n) n_esq = nos_m_n(arv->esq, n) + 1;
    int n_dir = nos_m_n(arv->dir, n);
    
    return n_esq + n_dir;
}

void p_vet(TABB* arv, int* resp, int* pos, int n) {
    if(!arv) return;

    if(arv->info > n) {
        resp[(*pos)++] = arv->info;
        p_vet(arv->esq, resp, pos, n);
    }
    p_vet(arv->dir, resp, pos, n);
}

int* mN(TABB* arv, int n, int* tam) {
    if(!arv) return NULL;

    (*tam) = nos_m_n(arv, n);
    int* resp = (int *)malloc(sizeof(sizeof(int) * (*tam)));
    int pos = 0;

    p_vet(arv, resp, &pos, n);

    return resp;
}

int main(void) {
    TABB* arv = TABB_inicializa();
    
    int n;
    do {
        scanf("%d", &n);
        if(n < 0) break;
        arv = TABB_insere(arv, n);
    } while(1);

    int tam = 0;
    int* resp = mN(arv, 4, &tam);

    for(int i = 0; i < tam; i ++) {
        printf("%d\n", resp[i]);
    }

    return 0;
}
