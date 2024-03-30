#ifndef TF_h
#define TF_H

#include "..\..\arvore-binaria\TAB.h"

struct NOF {
    struct AB* no;
    struct NOF* prox;
};

typedef struct FILA {
    struct NOF* inicio;
    struct NOF* fim;
} TF;

TF* TF_inicializa(void);
int TF_vazia(TF* fila);
void TF_insere(TF* fila, struct AB* no);
struct AB* TF_retira(TF* fila);
void TF_libera(TF* fila);
void TF_imprime(struct NOF* nof);

#endif
