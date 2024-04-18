#ifndef TABB_H
#define TABB_H

typedef struct ABB {
    int info;
    struct ABB* esq;
    struct ABB* dir;
} TABB;

TABB* TABB_inicializa(void);
TABB* TABB_cria(int info, TABB* esq, TABB* dir);
TABB* TABB_insere(TABB* arv, int x);
TABB* TABB_retira(TABB* arv, int x);
TABB* TABB_busca(TABB* arv, int x);
void TABB_imprime(TABB* arv, int tab);

#endif
