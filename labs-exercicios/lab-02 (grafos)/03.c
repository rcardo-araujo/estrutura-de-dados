#include <stdio.h>
#include <stdlib.h>
#include "..\..\bibliotecas\grafo\TG.h"
#include "..\..\bibliotecas\lista-simp-encadeada\TLSE.h"

TLSE* caminhoAux(TG* g, TG* no, TLSE* path, TLSE** l_vis, int y) {
    path = TLSE_insere_fim_rec(path, no->info);
    if(no->info == y) return path;
    *l_vis = TLSE_insere(*l_vis, no->info);

    TVIZ* viz = no->prim_viz;
    while(viz) {
        if(!TLSE_busca(*l_vis, viz->info)) {
            TG* no_viz = TG_busca_no(g, viz->info);
            TLSE* path_aux = caminhoAux(g, no_viz, path, l_vis, y);
            if(path_aux) return path_aux;
        }

        viz = viz->prox_viz;
    }

    return NULL;
}

TLSE* caminho(TG* g, int x, int y) {
    TG* no_x = TG_busca_no(g, x);
    if(!no_x) return NULL;

    TVIZ* viz = no_x->prim_viz;
    TLSE* l_vis = TLSE_insere(NULL, no_x->info);
    while(viz) {
        TG* no_viz = TG_busca_no(g, viz->info);
        TLSE* path = TLSE_insere(NULL, no_x->info);
        path = caminhoAux(g, no_viz, path, &l_vis, y);
        TLSE_imprime(path);
        if(path) return path;

        viz = viz->prox_viz;
    }

    return NULL;
}

int main(void) {
    TG* g = TG_inicializa();
    TLSE* cam = TLSE_inicializa();

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

    cam = caminho(g, 5, 7);
    TLSE_imprime(cam);

    return 0;
}
