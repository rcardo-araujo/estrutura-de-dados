#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "..\..\bibliotecas\grafo\TG.h"
#include "..\..\bibliotecas\lista-simp-encadeada\TLSE.h"

int tamCaminho(TLSE* path) {
    int tam = 0;
    TLSE* p = path;
    while(p) {
        tam ++;
        p = p->prox;
    }
    return tam;
}

TLSE* caminho(TG* g, TG* no, TLSE* path, int y) {
    path = TLSE_insere_fim_rec(path, no->info);
    if(no->info == y) return path;

    TVIZ* viz = no->prim_viz;
    while(viz) {
        if(!TLSE_busca(path, viz->info)) {
            TG* no_viz = TG_busca_no(g, viz->info);
            TLSE* path_aux = caminho(g, no_viz, path, y);
            if(path_aux) return path_aux;
        }
        
        viz = viz->prox_viz;
    }

    return NULL;
}

TLSE* menorCaminho(TG* g, int x, int y) {
    if(!g) return NULL;

    TG* no_x = TG_busca_no(g, x);
    if(!no_x) return NULL;

    TLSE* menor_path = NULL;
    int menor_tam = INT_MAX;

    TVIZ* viz = no_x->prim_viz;
    while(viz) {
        TG* no_viz = TG_busca_no(g, viz->info);
        TLSE* path = TLSE_insere(NULL, no_x->info);
        path = caminho(g, no_viz, path, y);
        
        int tam = tamCaminho(path);
        if(tam && (tam < menor_tam)) {
            menor_path = path;
            menor_tam = tam;
        }
        
        viz = viz->prox_viz;
    }
    
    return menor_path;
}

int main(void) {
    TG* g = TG_inicializa();

    int n, m;
    printf("Inserindo vertices:\n");
    do {
        scanf("%d", &n);
        if(n < 0) break;
        g = TG_insere_no(g, n);
    } while(1);

    printf("Inserindo arestas:\n");
    do {
        scanf("%d %d", &n, &m);
        if((n < 0) || (m < 0)) break;
        TG_insere_aresta(g, n, m);
    } while(1);

    printf("Digite o vertice fonte e final: ");
    scanf("%d %d", &n, &m);

    TLSE_imprime(menorCaminho(g, n, m));

    return 0;
}
