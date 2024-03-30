#include <stdio.h>
#include <stdlib.h>
#include "..\..\bibliotecas\arvore-binaria\TAB.h"

// 07
void colore(TAB* arv) {
    if(!arv) return;
    if(!arv->esq && !arv->dir) return;

    colore(arv->esq);
    colore(arv->dir);

    if(!arv->esq->info) arv->info = 255;
    else arv->info = 0;
}

// 08
int nos_internos(TAB* arv) {
    if(!arv) return 0;
    if(!arv->esq && !arv->dir) return 0;

    return nos_internos(arv->esq) + nos_internos(arv->dir) + 1;
}

// 09
int nos_folha(TAB* arv) {
    if(!arv) return 0;
    if(!arv->esq && !arv->dir) return 1;

    return nos_folha(arv->esq) + nos_folha(arv->dir);
}

int main(void) {
    TAB* arv = TAB_inicializa();
    arv = TAB_cria(0,
            TAB_cria(0,
                TAB_cria(0,
                    TAB_cria(0, NULL, NULL),
                    TAB_cria(0, NULL, NULL)
                ),
                TAB_cria(0,
                    TAB_cria(0, NULL, NULL),
                    TAB_cria(0, NULL, NULL)
                )
            ),
            TAB_cria(0,
                TAB_cria(0,
                    TAB_cria(0, NULL, NULL),
                    TAB_cria(0, NULL, NULL)
                ),
                TAB_cria(0,
                    TAB_cria(0, NULL, NULL),
                    TAB_cria(0, NULL, NULL)
                )
            )
    );

    printf("%d\n", nos_internos(arv));

    printf("%d\n", nos_folha(arv));

    colore(arv);
    TAB_imprime(0, arv);

    return 0;
}