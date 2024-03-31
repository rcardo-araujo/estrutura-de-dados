#include <stdlib.h>
#include <stdio.h>
#include "TP.h"

TP* TP_inicializa(void) {
    TP* pilha = (TP *)malloc(sizeof(TP));
    pilha->topo = NULL;

    return pilha;
}

int TP_vazia(TP* pilha) {
    return !pilha->topo;
}

void TP_push(TP* pilha, struct AB* no) {
    struct NOP* novo = (struct NOP *)malloc(sizeof(struct NOP));
    novo->prox = pilha->topo;
    novo->no = no;

    pilha->topo = novo;
}

struct AB* TP_pop(TP* pilha) {
    if(TP_vazia(pilha)) return NULL;

    struct NOP* p = pilha->topo;
    struct AB* q = pilha->topo->no;
    pilha->topo = pilha->topo->prox;
    free(p);

    return q;
}

void TP_libera(TP* pilha) {
    struct NOP* p;
    while(!TP_vazia(pilha)) {
        p = pilha->topo;
        pilha->topo = p->prox;
        free(p);
    }
    free(pilha);
}
