#include <stdlib.h>
#include <stdio.h>
#include "TAVL.h"

int main(void) {
    TAVL *arvore = NULL;
    int num = 0, from, to;
    while(num != -1){
        printf("Digite um numero para adicionar. 0 para imprimir. -9 para remover e -1 para sair\n");
        scanf("%i", &num);
        if(num == -9){
            scanf("%d", &from);
            arvore = TAVL_retira(arvore, from);
            TAVL_imprime(arvore, 0);
        }
        else if(num == -1){
            printf("\n");
            TAVL_imprime(arvore, 0);
            TAVL_libera(arvore);
            return 0;
        }
        else if(!num){
            printf("\n");
            TAVL_imprime(arvore, 0);
        }
        else arvore = TAVL_insere(arvore, num);
        printf("\n\n");
    }
}
