#include <stdio.h>
#include <stdlib.h>
#include "..\bibliotecas\arvore-binaria\TAB.h"
#include "..\bibliotecas\fila\fila-ab\TF.h"

void imprime_nivel(TAB* raiz) {
    if(!raiz) return;

    TF* fila = TF_inicializa();
    TF_insere(fila, raiz);
    while(!TF_vazia(fila)) {
        struct AB* p = TF_retira(fila);
        printf("%d - ", p->info);
        if(p->esq) TF_insere(fila, p->esq);
        if(p->dir) TF_insere(fila, p->dir);
    }
    TF_libera(fila);
}

int main(void) {
    TAB* arv = TAB_inicializa();
    arv = TAB_cria(1,
        TAB_cria(2,
            TAB_cria(3, NULL, NULL),
            TAB_cria(4, NULL, NULL)
        ),
        TAB_cria(5, NULL, NULL)
    );

    imprime_nivel(arv);

    return 0;
}
