#include <stdio.h>
#include <stdlib.h>
#include "TAFG.H"
#include "TFG.h"

TAFG* TAFG_inicializa(void) {
    return NULL;
}

static struct Q* cria_q(void) {
    float l;
    printf("Insira o lado do quadrado: ");
    scanf("%f", &l);

    struct Q* novo = (struct Q*)malloc(sizeof(struct Q));
    novo->l = l;
    return novo;
}

static struct R* cria_r(void) {
    float b, h;
    printf("Insira a base e altura do retangulo: ");
    scanf(" %f %f", &b, &h);

    struct R* novo = (struct R*)malloc(sizeof(struct R));
    novo->b = b;
    novo->h = h;
    return novo;
}

static struct TG* cria_tg(void) {
    float b, h;
    printf("Insira a base e altura do triangulo: ");
    scanf(" %f %f", &b, &h);

    struct TG* novo = (struct TG*)malloc(sizeof(struct TG));
    novo->b = b;
    novo->h = h;
    return novo;
}

static struct TP* cria_tp(void) {
    float B, b, h;
    printf("Insira a base maior, base menor e altura do trapezio: ");
    scanf(" %f %f %f", &B, &b, &h);

    struct TP* novo = (struct TP*)malloc(sizeof(struct TP));
    novo->B = B;
    novo->b = b;
    novo->h = h;
    return novo;
}

TFG* TAFG_cria_fg(int tipo) {
    TFG* fg = (TFG *)malloc(sizeof(TFG));

    struct Q* q;
    struct R* r;
    struct TG* tg;
    struct TP* tp;
    switch(tipo) {
        case 1:
            fg->tipo = 1;
            fg->figura = (void *)cria_q();
            q = (struct Q*)fg->figura;
            fg->area = q->l * q->l;
            break;
        case 2:
            fg->tipo = 2;
            fg->figura = (void *)cria_r();
            r = (struct R*)fg->figura;
            fg->area = r->b * r->h;
            break;
        case 3:
            fg->tipo = 3;
            fg->figura = (void *)cria_tg();
            tg = (struct TG*)fg->figura;
            fg->area = (tg->b * tg->h) / 2;
            break;
        case 4:
            fg->tipo = 4;
            fg->figura = (void *)cria_tp();
            tp = (struct TP*)fg->figura;
            fg->area = ((tp->B + tp->b) * tp->h) / 2;
            break;
        default:
            break;
    }
    return fg;
}

TAFG* TAFG_insere_arv(TAFG* arv, TAFG* no, float area) {
    if(!arv) return no;

    float area_arv = arv->figura->area;
    if(area < area_arv) arv->esq = TAFG_insere_arv(arv, no, area);
    else arv->dir = TAFG_insere_arv(arv, no, area);
    
    return arv;
}

TAFG* TAFG_insere(TAFG* arv, int tipo) {
    TAFG* novo = (TAFG *)malloc(sizeof(TAFG));
    novo->figura = TAFG_cria_fg(tipo);
    novo->esq = NULL;
    novo->dir = NULL;

    float area = novo->figura->area;

    return TAFG_insere_arv(arv, novo, area);
}

void TAFG_imprime(TAFG* arv, int tab) {
    int t;
    for(t = 0; t < tab; t ++) {
        printf("-");
    }
    
    if(arv) {
        TAFG_imprime(arv->esq, tab + 3);

        struct Q* q;
        struct R* r;
        struct TG* tg;
        struct TP* tp;
        int tipo = arv->figura->tipo;
        switch(tipo) {
            case 1:
                q = (struct Q*)arv->figura->figura;
                printf("Quadrado | Lado: %f | ", q->l);
                break;
            case 2:
                r = (struct R*)arv->figura->figura;
                printf("Retangulo | Base, Altura: %f, %f | ", r->b, r->h);
                break;
            case 3:
                tg = (struct TG*)arv->figura->figura;
                printf("Triangulo | Base, Altura: %f, %f | ", tg->b, tg->h);
                break;
            case 4:
                tp = (struct TP*)arv->figura->figura;
                printf("Trapezio | Base maior, Base menor, Altura: %f, %f, %f | ", tp->B, tp->b, tp->h);
                break;
            default:
                break;
        }
        printf("Area: %f\n", arv->figura->area);
        
        TAFG_imprime(arv->dir, tab + 3);
    } else printf("NULL\n");
}
