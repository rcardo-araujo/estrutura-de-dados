#include <stdio.h>
#include <stdlib.h>

void insereArq(char* nome_arq) {
    FILE* arq = fopen(nome_arq, "wb");
    if(!arq) return;

    int n;
    do {
        printf("Insira um numero: ");
        scanf("%d", &n);
        if(n < 0) break;

        printf("Inserindo %d na posicao %d\n", n, ftell(arq));
        fwrite(&n, sizeof(int), 1, arq);
    } while(1);
    printf("Quantidade de elementos escritos: %d\n\n", ftell(arq) / sizeof(int));
    fclose(arq);
}

void imprimeArq(char* nome_arq) {
    FILE* arq = fopen(nome_arq, "rb");
    if(!arq) return;

    int n, r;
    r = fread(&n, sizeof(int), 1, arq);
    while(r == 1) {
        printf("%d ", n);
        r = fread(&n, sizeof(int), 1, arq);
    }
    fclose(arq);
}

int main(int argc, char** argv) {
    insereArq(argv[1]);
    imprimeArq(argv[1]);
    return 0;
}
