#include <stdio.h>
#include <stdlib.h>
#include "TLG.h"

typedef struct Q {
    int l;
    int area;
} Quadrado;

typedef struct A {
    int area_t;
} Area;

static TLG* insere_quad(TLG* lista, int l) {
    Quadrado* novo = (Quadrado *)malloc(sizeof(Quadrado));
    novo->l = l;
    novo->area = (l * l);

    return TLG_insere(lista, novo);
}

static void area_t(void* info, void* dado) {
    Quadrado* p = (Quadrado *)info;
    Area* q = (Area *)dado;

    q->area_t += p->area;
}

int main(void) {
    TLG* l = TLG_inicializa();

    int n;
    do {
        scanf("%d", &n);
        if(n < 0) break;
        l = insere_quad(l, n);
    } while(1);

    Area a = {0};
    TLG_percorre(l, area_t, &a);
    printf("Area total: %d\n", a.area_t);

    return 0;
}
