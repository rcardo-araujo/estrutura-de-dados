#ifndef TAFG_H
#define TAFG_H

#include "TFG.h"

typedef struct AFG {
    TFG* figura;
    struct AFG* esq;
    struct AFG* dir;
} TAFG;

TAFG* TAFG_inicializa(void);
TFG* TAFG_cria_fg(int tipo);
TAFG* TAFG_insere_arv(TAFG* arv, TAFG* no, float area);
TAFG* TAFG_insere(TAFG* arv, int tipo); 
void TAFG_imprime(TAFG* arv, int tab);

#endif
