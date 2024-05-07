#include <stdio.h>
#include <stdlib.h>
#include "..\..\bibliotecas\grafo\TG.h"

// 01
int nn(TG* g) {
    if(!g) return 0;

    return nn(g->prox_no) + 1;
}

// struct [02]
typedef struct A {
    int v1, v2;
} Aresta;

// f. auxiliar [02]
// verifica se já tem a aresta
int dVet(Aresta** vet, int x, int y, int tam) {
    int i;
    for(i = 0; i < tam; i ++) {
        if((vet[i]->v1 == x || vet[i]->v1 == y) && 
            (vet[i]->v2 == x || vet[i]->v2 == y))
            return 1;
    }
    return 0;
} 

// 02
// Arestas sem orientação !!
int na(TG* g) {
    if(!g) return 0;

    TG* p = g;
    Aresta** vet = (Aresta **)malloc(0);
    int tam = 0, qtd = 0;
    while(p) {
        TVIZ* q = p->prim_viz;
        while(q) {
            if(!(dVet(vet, p->info, q->info, tam))) {
                vet = (Aresta **)realloc(vet, sizeof(Aresta*) * (++tam));
                vet[tam - 1] = (Aresta *)malloc(sizeof(Aresta));
                vet[tam - 1]->v1 = p->info;
                vet[tam - 1]->v2 = q->info;
                qtd ++; 
            }
            q = q->prox_viz;
        }
        p = p->prox_no;
    }
    return qtd;
}

// 03
int mesma_cor(TG* g) {
    if(!g) return 0;

    TG* p = g;
    while(p->prox_no) {
        if(p->info == p->prox_no->info) return 1;
        p = p->prox_no;
    }
    return 0;
}

// 04
int testek(TG* g, int k) {
    if(!g) return 0;

    TG* p = g;
    while(p) {
        int grau = 0;
        TVIZ* q = p->prim_viz;
        while(q) {
            grau ++;
            q = q->prox_viz;
        }
        if(grau != k) return 0;
        p = p->prox_no;
    }
    return 1;
}

// 05
int iguais(TG* g1, TG* g2) {
    if((!g1) && (!g2)) return 1;
    if((g1 && !g2) || (!g1 && g2)) return 0;
    if(g1->info != g2->info) return 0;

    TVIZ* p = g1->prim_viz;
    TVIZ* q = g2->prim_viz;
    while(1) {
        if((!p) && (!q)) break; 
        if((p && !q) || (!p && q)) return 0;
        if(p->info != q->info) return 0;
        p = p->prox_viz;
        q = q->prox_viz;
    }
    return iguais(g1->prox_no, g2->prox_no);
}

int main(void) {
    TG* g1 = TG_inicializa();
    TG* g2 = TG_inicializa();

    int n, m;
    do {
        scanf("%d", &n);
        if(n < 0) break;
        g1 = TG_insere_no(g1, n);
        g2 = TG_insere_no(g2, n);
    } while(1);

    do {
        scanf("%d%d", &n, &m);
        if(n < 0 || m < 0) break;
        TG_insere_aresta(g1, n, m);
        TG_insere_aresta(g2, n, m);
    } while(1);

    printf("Quantidade de nos: %d\n", nn(g1));
    printf("Quantidade de arestas: %d\n", na(g1));
    printf("%d\n", testek(g1, 2));
    printf("%d\n", iguais(g1, g2));
}
