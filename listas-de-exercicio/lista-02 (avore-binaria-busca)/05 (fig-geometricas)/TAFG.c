#include <stdio.h>
#include <stdlib.h>
#include "TAFG.H"
#include "TFG.h"

TAFG* TAFG_inicializa(void) {
    return NULL;
}

static TQ* cria_quadrado(float* area) {
    TQ* novo = (TQ *)malloc(sizeof(TQ));
    printf("Quadrado:\n");
    printf("l = ");
    scanf(" %f", &(novo->l));
    (*area) = (novo->l) * (novo->l);
    return novo;
}

static TR* cria_retangulo(float* area) {
    TR* novo = (TR *)malloc(sizeof(TR));
    printf("Retangulo:\n");
    printf("b, h = ");
    scanf(" %f %f", &(novo->b), &(novo->h));
    (*area) = novo->b * novo->h;
    return novo;
}

static TTG* cria_triangulo(float* area) {
    TTG* novo = (TTG *)malloc(sizeof(TTG));
    printf("Triangulo:\n");
    printf("b, h = ");
    scanf(" %f %f", &(novo->b), &(novo->h));
    (*area) = (novo->b * novo->h) / 2;
    return novo;
}

static TTP* cria_trapezio(float* area) {
    TTP* novo = (TTP *)malloc(sizeof(TTP));
    printf("Trapezio:\n");
    printf("B, b, h = ");
    scanf(" %f %f %f", &(novo->B), &(novo->b), &(novo->h));
    (*area) = ((novo->B + novo->b) * novo->h) / 2;
    return novo;
}

TFG* TAFG_cria_figura(int tipo) {
    TFG* figura = (TFG *)malloc(sizeof(TFG));
    float a;
    switch(tipo) {
        case 1:
            figura->info = (void *)cria_quadrado(&a);
            figura->area = a;
            figura->tipo = 1;
            break;
        case 2:
            figura->info = (void *)cria_retangulo(&a);
            figura->area = a;
            figura->tipo = 2;
            break;
        case 3:
            figura->info = (void *)cria_triangulo(&a);
            figura->area = a;
            figura->tipo = 3;
            break;
        case 4:
            figura->info = (void *)cria_trapezio(&a);
            figura->area = a;
            figura->tipo = 4;
            break;
    }
    return figura;
}

TAFG* TAFG_insere(TAFG* arv, TFG* f) {
    if(!arv) {
        TAFG* nova_a = (TAFG *)malloc(sizeof(TAFG));
        nova_a->figura = f;
        nova_a->esq = NULL;
        nova_a->dir = NULL;
        return nova_a;
    }

    if(f->area < arv->figura->area) arv->esq = TAFG_insere(arv->esq, f);
    else if(f->area > arv->figura->area) arv->dir = TAFG_insere(arv->dir, f);
    return arv;
}

static void imprime_quadrado(TFG* f) {
    TQ* q = (TQ *)f->info;
    printf(" Lado = %.1f | Quadrado\n", q->l);
}

static void imprime_retangulo(TFG* f) {
    TR* r = (TR *)f->info;
    printf(" Base = %.1f, Altura = %.1f | Retangulo\n", r->b, r->h);
}

static void imprime_triangulo(TFG* f) {
    TTG* t = (TTG *)f->info;
    printf(" Base = %.1f, Altura = %.1f | Triangulo\n", t->b, t->h);
}

static void imprime_trapezio(TFG* f) {
    TTP* t = (TTP *)f->info;
    printf(" Base maior = %.1f, Base menor = %.1f, Altura = %.1f | Trapezio\n", t->B, t->b, t->h);
}

void TAFG_imprime(TAFG* arv, int tab) {
    int t;
    for(t = 0; t < tab; t ++) {
        printf("-");
    }

    if(arv) {
        printf("Area = %.1f |", arv->figura->area);
        switch(arv->figura->tipo) {
            case 1:
                imprime_quadrado(arv->figura);
                break;
            case 2:
                imprime_retangulo(arv->figura);
                break;
            case 3:
                imprime_triangulo(arv->figura);
                break;
            case 4:
                imprime_trapezio(arv->figura);
                break;
        }
        TAFG_imprime(arv->esq, tab + 3);
        TAFG_imprime(arv->dir, tab + 3);
    } else printf("NULL\n");
}
