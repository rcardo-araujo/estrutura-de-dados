#include <stdio.h>
#include <stdlib.h>
#include "TG.h"

TG* TG_inicializa(void) {
    return NULL;
}

TG* TG_busca_no(TG* g, int x) {
    if((!g) || (g->info == x)) return g;

    return TG_busca_no(g->prox_no, x);
}

TVIZ* TG_busca_aresta(TG* g, int x, int y) {
    if(g) {
        TG* p = TG_busca_no(g, x);
        if(p) {
            TVIZ* q = g->prim_viz;
            while((q) && (q->info != y)) q = q->prox_viz;
            return q;
        }
    }
    return NULL;
}

TG* TG_insere_no(TG* g, int x) {
    if(TG_busca_no(g, x)) return g;

    TG* novo = (TG *)malloc(sizeof(TG));
    novo->info = x;
    novo->prim_viz = NULL;
    novo->prox_no = g;

    return novo;
}

void TG_insere_aresta_sentido(TG* g, int x, int y) {
    TG* p = TG_busca_no(g, x);
    TG* q = TG_busca_no(g, y);
    if((!p) || (!q)) return;

    TVIZ* aux = TG_busca_aresta(p, x, y);
    if(!aux) {
        aux = (TVIZ *)malloc(sizeof(TVIZ));
        aux->info = y;
        aux->prox_viz = p->prim_viz;
        p->prim_viz = aux;
    }
}

void TG_insere_aresta(TG* g, int x, int y) {
    TG_insere_aresta_sentido(g, x, y);
    TG_insere_aresta_sentido(g, y, x);
}

void TG_retira_aresta_sentido(TG* g, int x, int y) {
    TG* p = TG_busca_no(g, x);
    if(!p) return;

    TVIZ* ant = NULL, *q = p->prim_viz;
    while((q) && (q->info != y)) {
        ant = q;
        q = q->prox_viz;
    }

    if(!q) return;
    if(!ant) p->prim_viz = q->prox_viz;
    else ant->prox_viz = q->prox_viz;
    free(q);
}

void TG_retira_aresta(TG* g, int x, int y) {
    TG_retira_aresta_sentido(g, x, y);
    TG_retira_aresta_sentido(g, y, x);
}

TG* TG_retira_no(TG* g, int x) {
    TG* ant = NULL, *p = g;
    while((p) && (p->info != x)) {
        ant = p;
        p = p->prox_no;
    } if(!p) return g;

    TVIZ* q = p->prim_viz, *t;
    while(q) {
        TG_retira_aresta_sentido(g, q->info, x);
        t = q;
        q = q->prox_viz;
        free(t);
    }

    if(!ant) g = p->prox_no;
    else ant->prox_no = p->prox_no;
    free(p);
    return g;
}

void TG_libera_viz(TVIZ* v) {
    if(v) {
        TG_libera_viz(v->prox_viz);
        free(v);
    }
}

void TG_libera(TG* g) {
    if(g) {
        TG_libera(g->prox_no);
        TG_libera_viz(g->prim_viz);
        free(g);
    }
}

void TG_imprime_aresta(TVIZ* v) {
    if(v) {
        printf("%d -> ", v->info);
        TG_imprime_aresta(v->prox_viz);
    }
}

void TG_imprime(TG* g) {
    if(g) {
        printf("(no: %d) -> ", g->info);
        TG_imprime_aresta(g->prim_viz);
        printf("\n|\n|\n");
        TG_imprime(g->prox_no);
    }
}

TVIZ* ordena_viz(TVIZ* v) {
    if(!v) return NULL;

    TVIZ* p = v;
    while(p) {
        TVIZ* menor = p, *q;
        for(q = p->prox_viz; q; q = q->prox_viz) {
            if(q->info < menor->info) {
                menor = q;
            }
        }
        if(menor != p) {
            int tmp = p->info;
            p->info = menor->info;
            menor->info = tmp;
        }
        p = p->prox_viz;
    }
    return v;
}

TG* TG_ordena(TG* g) {
    if(!g) return NULL;

    TG* p = g;
    while(p) {
        TG* menor = p, *q;
        for(q = p->prox_no; q; q = q->prox_no) {
            if(q->info < menor->info) {
                menor = q;
            }
        }
        if(menor != p) {
            int tmp = p->info;
            p->info = menor->info;
            menor->info = tmp;

            TVIZ* tmp_viz = p->prim_viz;
            p->prim_viz = menor->prim_viz;
            menor->prim_viz = tmp_viz;
        }
        p->prim_viz = ordena_viz(p->prim_viz);
        p = p->prox_no;
    }
    return g;
}
