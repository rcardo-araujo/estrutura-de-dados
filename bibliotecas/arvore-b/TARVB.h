#ifndef TARVB_H
#define TARVB_H

typedef struct B {
    int nchaves;
    int folha;
    int* chave;
    struct B** filho;
} TARVB;

TARVB* TARVB_inicializa(void);
TARVB* TARVB_cria(int t);
void TARVB_imprime(TARVB* arv);
void TARVB_libera(TARVB* arv);
