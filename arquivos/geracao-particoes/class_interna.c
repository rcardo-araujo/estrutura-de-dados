#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compara(const void* a, const void* b) {
    return *((int *)a) - *((int *)b);
}

int classInterna(char* nome_arq, char* padrao_part) {
    FILE* arq = fopen(nome_arq, "rt");
    if(!arq) {
        printf("Nao foi possivel abrir arquivo!");
        exit(1);
    }

    int m;
    printf("Digite M (numero maximo de registros por particao): ");
    scanf("%d", &m);

    int vet[m];
    int i, j, r, elem, n_part = 0;
    char nome_part[18], num[2], dash = '-';
    while(1) {
        for(i = 0; i < m; i ++) {
            r = fscanf(arq, "%d", &vet[i]);
            if(r != 1) break;
        } 
        if(!i) break;

        sprintf(num, "%d", ++n_part);
        strcpy(nome_part, padrao_part);
        strcat(nome_part, &dash);
        strcat(nome_part, num);
        strcat(nome_part, ".txt");
        printf("Nome da particao %d gerado!: %s\n", n_part, nome_part);

        qsort(vet, i, sizeof(int), compara);
        FILE* part = fopen(nome_part, "w");
        if(!arq) exit(1);
        for(j = 0; j < i; j ++) {
            fprintf(part, "%d\n", vet[j]);
        }
        fclose(part);
    }
    fclose(arq);
    return n_part;
}

int main(void) {
    char nome_arq[31];
    printf("Digite o nome do arquivo que deseja partir: ");
    scanf(" %s", nome_arq);

    FILE* arq = fopen(nome_arq, "w");
    if(!arq) exit(1);

    int n;
    do {
        printf("Digite um elemento: ");
        scanf("%d", &n);
        if(n < 0) break;
        fprintf(arq, "%d\n", n);
    } while(1);
    fclose(arq);

    char padrao_part[11];
    printf("Digite o padrao para os nomes das particoes (ex.: part): ");
    scanf(" %s", padrao_part);

    int n_part = classInterna(nome_arq, padrao_part);
    if(n_part == 1) printf("1 particao gerada!\n");
    else printf("Foram geradas %d particoes!", n_part);

    return 0;
}
