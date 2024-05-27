#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "..\..\bibliotecas\grafo\TG.h"
#include "..\..\bibliotecas\lista-simp-encadeada\TLSE.h"

TLSE* caminho(TG* g, TG* no_atual, int obj, int* cam_tam, TLSE* cam) {
    cam = TLSE_insere(cam, no_atual->info);
    if(no_atual->info == obj) return cam;
    (*cam_tam) ++;

    TVIZ* viz = no_atual->prim_viz;
    while(viz) {
        if(viz->info == obj) {
            cam = TLSE_insere(cam, obj);
            return cam;
        } 
        if(!TLSE_busca(cam, viz->info)) {
            TG* aux = TG_busca_no(g, viz->info);
            TLSE* cam_aux = caminho(g, aux, obj, cam_tam, cam);
            if(cam_aux) return cam_aux;
        }
        viz = viz->prox_viz;
    }
    return NULL;
}

TLSE* menorCaminho(TG* g, int x, int y) {
    if(!g) return NULL;

    TG* no_x = TG_busca_no(g, x);
    TVIZ* viz = no_x->prim_viz;
    TLSE* menor_cam = TLSE_inicializa();
    int menor_tam = INT_MAX;
    while(viz) {
        TG* v_viz = TG_busca_no(g, viz->info);
        TLSE* cam_n = TLSE_inicializa();
        int cam_tam = 0;

        cam_n = TLSE_insere(cam_n, no_x->info);
        cam_n = caminho(g, v_viz, y, &cam_tam, cam_n);
        if(cam_tam < menor_tam) {
            menor_cam = cam_n;
            menor_tam = cam_tam;
        }
        viz = viz->prox_viz;
    }
    return menor_cam;
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
