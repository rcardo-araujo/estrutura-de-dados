#include <stdio.h>
#include <stdlib.h>

#define TAM_PLV 11

void insere_palavras(char* nome_arq) {
    FILE* arq = fopen(nome_arq, "wb");
    if(!arq) return;

    int opcao;
    char palavra[TAM_PLV];
    do {
        printf("Deseja inserir? [1/0]: ");
        scanf("%d", &opcao);
        if(opcao == 0) break;

        printf("Palavra: ");
        scanf(" %s", palavra);
        fwrite(palavra, sizeof(char), TAM_PLV, arq);
    } while(1);
    fclose(arq);
}

int main(int argc, char** argv) {
    char* nome_arq = argv[1];
    insere_palavras(nome_arq);
    return 0;
} 
