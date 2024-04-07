#include <stdio.h>
#include <stdlib.h>
#include "..\..\bibliotecas\arvore-binaria-busca\TABB.h"

// 01
TABB* maior_elem(TABB* arv) {
    if(!(arv && arv->dir)) return arv;

    return maior_elem(arv->dir);
}

// 02
TABB* menor_elem(TABB* arv) {
    if(!(arv && arv->esq)) return arv;

    return menor_elem(arv->esq);
}

// 03
TABB* retira_impares(TABB* arv) {
    if(arv) {
        arv->esq = retira_impares(arv->esq);
        arv->dir = retira_impares(arv->dir);
        if((arv->info) % 2) {
            arv = TABB_retira(arv, arv->info);
        }
    }

    return arv;
}

// f. auxiliar [04]
// calcula tamanho de vetor
int tam_vetor(int* vet) {
    int tam = 0;
    if(!vet) return tam;

    while(vet[tam] != -1) {
        tam++;
    }

    return tam;
}

// 04
int* menores_n(TABB* arv, int n) {
    if(!arv) return NULL;

    int* resp = NULL;
    int* resp_dir = NULL;
    int* resp_esq = menores_n(arv->esq, n);

    if(arv->info < n) {
        resp_dir = menores_n(arv->dir, n);
        resp = (int *)malloc(
            sizeof(int) * (
                tam_vetor(resp_esq) +
                tam_vetor(resp_dir) +
                2
            )
        );
    } else return resp_esq;

    int i, j;
    for(i = 0; i < tam_vetor(resp_esq); i++) {
        resp[i] = resp_esq[i];
    }
    resp[i++] = arv->info;
    for(j = 0; j < tam_vetor(resp_dir); j ++) {
        resp[j + i] = resp_dir[j];
    }
    resp[i + j] = -1;

    free(resp_esq);
    free(resp_dir);
    return resp;
}

int main(void) {
    TABB* arv = TABB_inicializa();

    int vet[] = {10, 5, 2, 6, 8, 7, 9, 15, 12, 17};
    int i = 0;
    for(i; i < 10; i ++) {
        arv = TABB_insere(arv, vet[i]);
    }

    printf("Maior elemento da arvore: %d\n", maior_elem(arv)->info);

    printf("Menor elemento da arvore: %d\n", menor_elem(arv)->info);

    int* menores_q_n = menores_n(arv, 3);
    printf("Elementos menores que 3: ");
    for(i = 0; i < tam_vetor(menores_q_n); i++)
        printf("%d ", menores_q_n[i]);
    printf("\n");

    printf("\nArvore:\n");
    TABB_imprime(arv, 0);

    arv = retira_impares(arv);
    printf("\nArvore sem impares:\n");
    TABB_imprime(arv, 0);

    return 0;
}
