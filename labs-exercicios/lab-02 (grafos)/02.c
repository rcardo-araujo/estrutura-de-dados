#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "..\..\bibliotecas\grafo\TG.h"
#include "..\..\bibliotecas\lista-simp-encadeada\TLSE.h"

int ciclico(TG* g, TG* v_atual, int parente, TLSE** visitados) {
    (*visitados) = TLSE_insere(*visitados, v_atual->info);
    TVIZ* p = v_atual->prim_viz;
    while(p) {
        if(!TLSE_busca(*visitados, p->info)) {
            TG* aux = TG_busca_no(g, p->info);
            if(ciclico(g, aux, v_atual->info, visitados)) return 1;
        }
        else if(p->info != parente) return 1;
        p = p->prox_viz;
    }
    return 0;
}

int teste(TG* g) {
    if(!g) return 0;

    TLSE* visitados = TLSE_inicializa();
    TG* prim_v = g; // salientando o parâmetro da função
    if(ciclico(g, prim_v, INT_MIN, &visitados)) return 0;
    return 1;
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
        if(n < 0 || m < 0) break;
        TG_insere_aresta(g, n, m);
    } while(1);

    if(teste(g)) printf("Eh arvore!");
    else printf("Nao eh arvore!");

    return 0;
}
