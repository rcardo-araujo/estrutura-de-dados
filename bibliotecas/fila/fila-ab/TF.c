#include <stdio.h>
#include <stdlib.h>
#include "TF.h"

TF* TF_inicializa(void) {
    TF* nova = (TF *)malloc(sizeof(TF));
    nova->inicio = NULL;
    nova->fim = NULL;

    return nova;
}

int TF_vazia(TF* fila) {
    return fila->inicio == NULL;
}

void TF_insere(TF* fila, struct AB* no) {
    struct NOF* novo = (struct NOF*)malloc(sizeof(struct NOF));
    novo->no = no;
    novo->prox = NULL;

    if(TF_vazia(fila)) fila->inicio = novo;
    else fila->fim->prox = novo;
    fila->fim = novo;
}

struct AB* TF_retira(TF* fila) {
    if(TF_vazia(fila)) return NULL;

    struct AB* p = fila->inicio->no;
    struct NOF* q = fila->inicio;

    fila->inicio = fila->inicio->prox;
    if(!fila->inicio) fila->fim = NULL;
    free(q);

    return p;
}

void TF_libera(TF* fila) {
    while(!TF_vazia(fila)) TF_retira(fila);

    free(fila->inicio);
    free(fila->fim);
    free(fila);
}

void TF_imprime(TF* fila) {
    if(TF_vazia(fila)) return;

    TF* aux = TF_inicializa();
    while(!TF_vazia(fila)) {
        TAB* no = TF_retira(fila);
        printf("%d -> ", no->info);
        TF_insere(aux, no);
    }

    while(!TF_vazia(aux)) TF_insere(fila, TF_retira(aux));
    TF_libera(aux);
}
