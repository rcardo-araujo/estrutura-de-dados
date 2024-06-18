#include <stdio.h>
#include <stdlib.h>
#include "TARVB.h"

TARVB* TARVB_inicializa(void) {
    return NULL;
}

TARVB* TARVB_cria(int t) {
    TARVB* novo = (TARVB *)malloc(sizeof(TARVB));
    novo->nchaves = 0;
    novo->folha = 1;
    novo->chaves = (int *)malloc(sizeof(int) * ((2 * t) - 1));
    novo->filho = (TARVB **)malloc(sizeof(TARVB*) * (2 * t));
    for(int i = 0; i < (2 * t); i ++) novo->filho[i] = NULL;

    return novo;
}

static void TARVB_imprime_aux(TARVB* arv, int tab) {
    if(!arv) return;

    int i, j;
    for(i = 0; i < arv->nchaves; i ++) {
        TARVB_imprime_aux(arv->filho[i], tab + 1);
        for(j = 0; j < tab; j ++) printf(" ");
        printf("%d\n", arv->chaves[i]);
    } 

    // Imprimindo último filho
    TARVB_imprime_aux(arv->filho[i], tab + 1);
}

void TARVB_imprime(TARVB* arv) {
    TARVB_imprime_aux(arv, 0);
}

void TARVB_libera(TARVB* arv) {
    if(!arv) return;

    if(!arv->folha) {
        int i;
        for(i = 0; i <= arv->nchaves; i ++)
            TARVB_libera(arv->filho[i]);
    }

    free(arv->filho);
    free(arv->chave);
    free(arv);
}

TARVB* TARVB_busca(TARVB* arv, int c) {
    if(!arv) return NULL;

    int i = 0;
    while(i < arv->nchaves && c > arv->chave[i]) i++;
    
    if(i < arv->nchaves && c == arv->chave[i]) return arv;
    if(arv->folha) return NULL;
    return TARVB_busca(arv->filho[i], c);
}
