#ifndef TP_H
#define TP_H

#include "..\..\arvore-binaria\TAB.h"

struct NOP {
    struct AB* no;
    struct NOP* prox;
};

typedef struct P {
    struct NOP* topo;
} TP;

TP* TP_inicializa();
int TP_vazia(TP* pilha);
void TP_push(TP* pilha, struct AB* no);
struct AB* TP_pop(TP* pilha);
void TP_libera(TP* pilha);

#endif
