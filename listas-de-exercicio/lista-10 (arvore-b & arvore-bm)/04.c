#include <stdio.h>
#include <stdlib.h>
#include "..\..\bibliotecas\arvore-b\TARVB.h"

int iguais(TARVB* a1, TARVB* a2) {
    if((!a1) && (!a2)) return 1;
    
    if(a1 && a2) {
        if(a1->folha != a2->folha) return 0;
        if(a1->nchaves != a2->nchaves) return 0;

        // Se chaves iguais
        int i;
        for(i = 0; i < a1->nchaves; i ++)
            if(a1->chave[i] != a2->chave[i]) return 0;
        
        // Se filhos iguais
        for(i = 0; i <= a1->nchaves; i ++) 
            if(!iguais(a1->filho[i], a2->filho[i])) return 0;
        
        return 1;
    }
    return 0;
}

int main(void) {
    TARVB* a1 = TARVB_Inicializa();
    TARVB* a2 = TARVB_Inicializa();

    int t, n;
    printf("Digite o grau de ambas as arvores: ");
    scanf("%d", &t);

    printf("Insercao na arvore 1: ");
    do {
        scanf("%d", &n);
        if(n < 0) break;
        a1 = TARVB_Insere(a1, n, t);
    } while(1);

    printf("Insercao na arvore 2: ");
    do {
        scanf("%d", &n);
        if(n < 0) break;
        a2 = TARVB_Insere(a2, n, t);
    } while(1);

    printf("Arvore 1:\n");
    TARVB_Imprime(a1);
    printf("Arvore 2:\n");
    TARVB_Imprime(a2);
    
    printf("\nSao iguais? %d\n", iguais(a1, a2));
}
