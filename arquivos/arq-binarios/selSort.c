#include <stdio.h>
#include <stdlib.h>

void selSort(FILE* arq) {
    int menorInd, menorElem, elemAtual, elemI, tam;
    int i, j;

    fseek(arq, 0, SEEK_END);
    tam = ftell(arq);
    
    fseek(arq, 0, SEEK_SET);
    i = ftell(arq);
    fread(&elemI, sizeof(int), 1, arq);
    while(i < tam) {
        menorInd = i;
        menorElem = elemI;
        j = ftell(arq);
        fread(&elemAtual, sizeof(int), 1, arq);
        while(j < tam) {
            if(elemAtual < menorElem) {
                menorInd = j;
                menorElem = elemAtual;
            }
            j = ftell(arq);
            fread(&elemAtual, sizeof(int), 1, arq);
        }

        printf("%d %d\n", i, menorInd);
        if(menorInd != i) { 
            printf("Trocando %d[%d] por %d[%d]\n", elemI, i, menorElem, menorInd);
            fseek(arq, menorInd, SEEK_SET);
            fwrite(&elemI, sizeof(int), 1, arq);
            fseek(arq, i, SEEK_SET);
            fwrite(&menorElem, sizeof(int), 1, arq);
        } else {
            fseek(arq, (i + sizeof(int)), SEEK_SET);
        }

        i = ftell(arq);
        fread(&elemI, sizeof(int), 1, arq);
    }
}

int main(int argc, char** argv) {
    int n, x, i;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int vet[n];
    printf("Digite os elementos do vetor: ");
    for(i = 0; i < n; i ++) {
        scanf("%d", &vet[i]);
    }

    FILE* arq = fopen(argv[1], "wb+");
    if(!arq) exit(1);
    fwrite(vet, sizeof(int), n, arq);

    int r = n;
    rewind(arq);
    printf("Arquivo binario [%s]:\n", argv[1]);
    while(r--) {
        fread(&x, sizeof(int), 1, arq);
        printf("%d\n", x);
    }
    printf("\n");

    selSort(arq);
    fclose(arq);

    int vetResp[n];
    arq = fopen(argv[1], "rb");
    fread(vetResp, sizeof(int), n, arq);
    fclose(arq);

    printf("\n");
    for(i = 0; i < n; i ++) {
        printf("%d\n", vetResp[i]);
    }
}
