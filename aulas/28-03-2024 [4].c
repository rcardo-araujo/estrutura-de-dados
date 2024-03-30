#include <stdio.h>
#include <stdlib.h>
#include "..\bibliotecas\arvore-binaria\TAB.h"
#include "..\bibliotecas\fila\fila-ab\TF.h"

void imprime_nivel(TAB* raiz) {
    if(!raiz) return;

    TF* fila = TF_inicializa();
    TF_insere(fila, raiz);
    TF_insere(fila, raiz->esq);
    TF_imprime(fila->inicio);
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

    TAB_imprime(0, arv);

    imprime_nivel(arv);

    return 0;
}
