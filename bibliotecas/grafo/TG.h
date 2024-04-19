#ifndef TG_H
#define TG_h

typedef struct VIZ {
    int info;
    struct VIZ* prox_viz;
} TVIZ;

typedef struct G {
    int info;
    struct G* prox_no;
    struct VIZ* prim_viz;
} TG;

TG* TG_inicializa(void);
TG* TG_busca_no(TG* g, int x);
TVIZ* TG_busca_aresta(TG* g, int x, int y);
TG* TG_insere_no(TG* g, int x);
TG* TG_retira_no(TG* g, int x);
void TG_insere_aresta(TG* g, int x, int y);
void TG_retira_aresta(TG* g, int x, int y);
void TG_libera(TG* g);
void TG_imprime(TG* g);
TG* TG_ordena(TG* g);

#endif
