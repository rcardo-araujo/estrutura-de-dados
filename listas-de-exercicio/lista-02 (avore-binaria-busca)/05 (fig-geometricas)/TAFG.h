#ifndef TAFG_H
#define TAFG_H

#include "TFG.h"

typedef struct AFG {
    struct FG* figura;
    struct AFG* esq;
    struct AFG* dir;
} TAFG;

TAFG* TAFG_inicializa(void);
TFG* TAFG_cria_figura(int tipo);
TAFG* TAFG_insere(TAFG* arv, TFG* f); 
void TAFG_imprime(TAFG* arv, int tab);

#endif
