#include <stdio.h>
#include <stdlib.h>
#include "..\..\bibliotecas\arvore-binaria\TAB.h"

// 02
TAB* copia(TAB* arv_og) {
    if(!arv_og) return NULL;

    return TAB_cria(arv_og->info,
        copia(arv_og->esq),
        copia(arv_og->dir)
    );
}

// f. auxiliar [03]
TAB* comp_maior(TAB* a, TAB* b) {
    if(a && b) {
        return (a->info >= b->info) ? a : b;
    }
    else {
        if(!a && !b) return NULL;
        else if(a) return a;
        return b;
    }
}

// 03
TAB* maior(TAB* arv) {
    if(!arv) return NULL;

    TAB* maior_esq = maior(arv->esq);
    TAB* maior_dir = maior(arv->dir);

    return comp_maior(
        comp_maior(maior_esq, maior_dir),
        arv
    );
}

// f. auxiliar [04]
TAB* comp_menor(TAB* a, TAB* b) {
    if(a && b) {
        return (a->info <= b->info) ? a : b;
    }
    else {
        if(!a && !b) return NULL;
        else if(a) return a;
        return b;
    }
}

// 04
TAB* menor(TAB* arv) {
    if(!arv) return NULL;

    TAB* menor_esq = menor(arv->esq);
    TAB* menor_dir = menor(arv->dir);

    return comp_menor(
        comp_menor(menor_esq, menor_dir),
        arv
    );
}

// 05
int igual(TAB* arv_a, TAB* arv_b) {
    if(!arv_a && !arv_b) return 1;
    
    if(arv_a && arv_b) {
        if(arv_a->info == arv_b->info) {
            return (
                igual(arv_a->esq, arv_b->esq) &&
                igual(arv_a->dir, arv_b->dir)
            );
        }
    } 

    return 0;
}

int main(void) {
    TAB* arv = TAB_inicializa();
    arv = TAB_cria(1,
        TAB_cria(10,
            TAB_cria(3, NULL, NULL),
            TAB_cria(4, NULL, NULL)
        ),
        TAB_cria(5, NULL, NULL)
    );

    TAB* arv2 = TAB_inicializa();
    arv2 = TAB_cria(1,
        TAB_cria(10,
            TAB_cria(3, NULL, NULL),
            TAB_cria(4, NULL, NULL)
        ),
        NULL
    );

    TAB* arv_copia = copia(arv);
    // TAB_imprime(0, arv_copia);

    // TAB* maior_no = maior(arv);
    // printf("%d\n", maior_no->info);

    // TAB* menor_no = menor(arv);
    // printf("%d", menor_no->info);

    printf("%d\n", igual(arv, arv_copia));
    printf("%d\n", igual(arv, arv2));

    return 0;
}