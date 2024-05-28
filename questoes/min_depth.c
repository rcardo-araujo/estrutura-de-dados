#include <stdio.h>
#include <stdlib.h>
#include "..\bibliotecas\arvore-binaria-busca\TABB.h"
#include "..\bibliotecas\lista-simp-encadeada\TLSE.h"
#include "..\bibliotecas\fila\TF.h"

// Retornar o número de nós
// do menor caminho entre a raiz
// e uma folha

int minDepth(TABB* a) {
    if(!a) return 0;

    TF* f_nos = TF_inicializa();
    TF* f_niveis = TF_inicializa();
    TF_insere(f_nos, a->info);
    TF_insere(f_niveis, 1);
    while(f_nos) {
        int x = TF_retira(f_nos);
        int n = TF_retira(f_niveis);
        TABB* no_x = TABB_busca(a, x);
        if((!no_x->esq) && (!no_x->dir)) return n;
        
        if(no_x->esq) {
            TF_insere(f_nos, no_x->esq->info);
            TF_insere(f_niveis, n + 1);
        }
        if(no_x->dir) {
            TF_insere(f_nos, no_x->dir->info);
            TF_insere(f_niveis, n + 1);
        }
    }
}

// Retorna o menor caminho
// entre a raiz e uma folha

int tamCam(TLSE* path) {
    int tam = 0;
    TLSE* aux = path;
    while(aux) {
        tam ++;
        aux = aux->prox;
    }

    return tam;
}

TLSE* menorCaminho(TABB* a) {
    if(!a) return NULL;
    if(!a->esq && !a->dir) return TLSE_insere(NULL, a->info);

    TLSE* path_esq = menorCaminho(a->esq);
    TLSE* path_dir = menorCaminho(a->dir);
    TLSE* menor_path = TLSE_inicializa();

    if(a->esq && a->dir) {
        if(tamCam(path_esq) < tamCam(path_dir)) menor_path = path_esq;
        else menor_path = path_dir;
    } else {
        if(a->esq) menor_path = path_esq;
        else menor_path = path_dir;
    }
    
    menor_path = TLSE_insere(menor_path, a->info);

    return menor_path;
}

int main(void) {
    TABB* a = TABB_inicializa();

    int n;
    do {
        scanf("%d", &n);
        if(n < 0) break;
        a = TABB_insere(a, n);
    } while(1);

    TABB_imprime(a, 0);
    printf("\nMin depth: %d\n", minDepth(a));
    TLSE_imprime(menorCaminho(a));

    return 0;
}
