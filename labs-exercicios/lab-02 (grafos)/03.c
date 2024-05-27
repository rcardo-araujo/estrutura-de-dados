#include <stdio.h>
#include <stdlib.h>
#include "..\..\bibliotecas\grafo\TG.h"
#include "..\..\bibliotecas\lista-simp-encadeada\TLSE.h"

TLSE* caminhoAux(TG* g, TG* v_atual, int obj, TLSE* cam) {
    cam = TLSE_insere(cam, v_atual->info);
    if(v_atual == obj) return cam;
    TVIZ* p = v_atual->prim_viz;
    while(p) {
        if(p->info == obj) {
            cam = TLSE_insere(cam, obj);
            return cam;
        }
        if(!TLSE_busca(cam, p->info)) {
            TG* aux = TG_busca_no(g, p->info);
            TLSE* aux_cam = caminhoAux(g, aux, obj, cam);
            if(aux_cam) return aux_cam;
        }
        p = p->prox_viz;
    }
    return NULL;
}

TLSE* caminho(TG* g, int x, int y) {
    TG* no_x = TG_busca_no(g, x);
    if(!no_x) return NULL;
    TVIZ* aux = no_x->prim_viz;
    while(aux) {
        TLSE* cam = TLSE_inicializa();
        TG* aresta = TG_busca_no(g, aux->info);
        cam = TLSE_insere(cam, no_x->info);
        cam = caminhoAux(g, aresta, y, cam);
        if(cam) return cam;
        aux = aux->prox_viz;
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
