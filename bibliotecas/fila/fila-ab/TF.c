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
    return ((!fila->inicio) || (!fila->fim));
}

void TF_insere(TF* fila, struct AB* no) {
    struct NOF* novo = (struct NOF*)malloc(sizeof(struct NOF));
    novo->no = no;
    novo->prox = NULL;

    if(TF_vazia(fila)) fila->inicio = novo;
    else fila->fim->prox = novo;
    fila->fim = novo;
}

void TF_imprime(struct NOF* nof) {
    if(!nof) {
        printf("%d -> ", nof->no->info);
        TF_imprime(nof->prox);
    } 
}
