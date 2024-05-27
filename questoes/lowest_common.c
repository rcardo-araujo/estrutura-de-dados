#include <stdio.h>
#include <stdlib.h>
#include "..\bibliotecas\arvore-binaria\TAB.h"
#include "..\bibliotecas\lista-simp-encadeada\TLSE.h"

// Problema: Achar o menor ancestral, em
// termos altura, entre dois nós de uma árvore.

TLSE* findPathAux(TLSE* path, TAB* a, int x) {
    if(a) {
        path = TLSE_insere_fim_rec(path, a->info);
        if(a->info == x) return path;
        
        TLSE* path_e, * path_d;
        path_e = findPathAux(path, a->esq, x);
        if(path_e) return path_e;
        path_d = findPathAux(path, a->dir, x);
        if(path_d) return path_d;
        path = TLSE_retira(path, a->info);
    }
    return NULL;
}

TLSE* findPath(TAB* a, int x) {
    TLSE* path = TLSE_inicializa();
    path = findPathAux(path, a, x);
    return path;
} 

TAB* lca(TAB* a, int x, int y) {
    if(!a) return NULL;

    TLSE* path_x = findPath(a, x);
    TLSE* path_y = findPath(a, y);
    if(!path_x || !path_y) return NULL;
    TLSE_imprime(path_x);
    TLSE_imprime(path_y);

    TLSE* p = path_x, * q = path_y;
    while(p && q) {
        if(p->prox->info != q->prox->info)
            return TAB_busca(p->info, a);
        p = p->prox;
        q = q->prox;
    }
}

int main(void) {
    TAB* a = TAB_inicializa();
    a = TAB_cria(1,
        TAB_cria(4,
            TAB_cria(6, NULL, NULL),
            TAB_cria(5,
                TAB_cria(10, NULL, NULL),
                NULL
            )
        ),
        TAB_cria(2, NULL, NULL)
    );

    int n, m;
    printf("Digite v1 e v2: ");
    scanf("%d %d", &n, &m);
    TAB_imprime(0, lca(a, n, m));

    return 0;
}
