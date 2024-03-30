#include <stdlib.h>
#include <stdio.h>
#include "TLG.h"

TLG* TLG_inicializa(void) {
    return NULL;
}

int TLG_vazia(TLG* lista) {
    return lista == NULL;
}

TLG* TLG_insere(TLG* lista, void* info) {
    TLG* novo = (TLG *)malloc(sizeof(TLG));
    novo->info = info;
    novo->prox = lista;

    return novo;
}

void TLG_percorre(TLG* lista, callback* cb, void* dado) {
    TLG* p = lista;
    while(p) {
        cb(p->info, dado);
        p = p->prox;
    }
}
