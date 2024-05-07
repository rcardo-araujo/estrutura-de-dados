#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 01
void retRepet(char* nomeArqEnt, char* nomeArqSaida) {
    FILE* arqEnt = fopen(nomeArqEnt, "r");
    FILE* arqSaida = fopen(nomeArqSaida, "w");
    if((!arqEnt) || (!arqSaida)) exit(1);

    char ant[20] = "";
    char str[20];
    int count;
    do {
        count = fscanf(arqEnt, "%s", str);
        printf("%s %s\n", str, ant);
        if(count != 1) break;
        if(strcmp(ant, str) != 0) fprintf(arqSaida, "%s ", str);
        strcpy(ant, str);
    } while(1);
    fclose(arqEnt);
    fclose(arqSaida);
}

// struct Aluno para [02]
typedef struct Aluno {
    char nome[3];
    float media;
} Aluno;

// função ordenação [02]
int ord(const void* a, const void* b) {
    float media1 = ((Aluno*)a)->media;
    float media2 = ((Aluno*)b)->media;
    if(media1 < media2) return -1;
    if(media1 > media2) return 1;
    return 0;
}

// 02
void media(char* arqEnt, char* arqSaida) {
    FILE* fEnt = fopen(arqEnt, "r");
    FILE* fSaida = fopen(arqSaida, "w");
    if((!fEnt) || (!fSaida)) exit(1);

    Aluno* vetAlunos = (Aluno*)malloc(0);
    int resp, tamVet = 0;
    float nota1, nota2;
    char letra1, letra2;
    do {
        resp = fscanf(fEnt, " %c %c", &letra1, &letra2);
        printf("%c %c\n", letra1, letra2);
        if(resp != 2) break;
        
        int i = tamVet++;
        vetAlunos = (Aluno*)realloc(vetAlunos, sizeof(Aluno) * tamVet);
        vetAlunos[i].nome[0] = letra1;
        vetAlunos[i].nome[1] = letra2;
        fscanf(fEnt, " %f %f", &nota1, &nota2);
        printf("%f\n%f\n", nota1, nota2);
        vetAlunos[i].media = (nota1 + nota2) / 2;
    } while(1);

    qsort(vetAlunos, tamVet, sizeof(Aluno), ord);
    for(int i = 0; i < tamVet; i ++) {
        fprintf(fSaida, "%c %c\n", vetAlunos[i].nome[0], vetAlunos[i].nome[1]);
        fprintf(fSaida, "%f\n", vetAlunos[i].media);
    }
}

// struct Num [03]
typedef struct Num {
    int valor;
    int count;
    int *linhas;
} Num;

// função para buscar número
// no vetor [03]
Num* buscaNum(Num* vet, int tamVet, int x) {
    int i;
    for(i = 0; i < tamVet; i ++) {
        if(vet[i].valor == x)
            return &vet[i];
    }
    return NULL;
}

// 03
void resumo(char* nomeArq) {
    FILE* fr = fopen(nomeArq, "r");
    if(!fr) exit(1);

    Num* vet = (Num*)malloc(0);
    int resp, num, i, l = 0, tamVet = 0;
    do {
        resp = fscanf(fr, "%d", &num);
        if(resp != 1) break;
        
        i = tamVet; l++;
        Num* bNum = buscaNum(vet, tamVet, num);
        if(bNum != NULL) {
            (bNum->count)++;
            bNum->linhas = (int *)realloc(bNum->linhas, sizeof(int) * bNum->count);
            bNum->linhas[bNum->count - 1] = l;
        } else {
            vet = (Num*)realloc(vet, sizeof(Num) * (++tamVet));
            vet[i].valor = num;
            vet[i].count = 1;
            vet[i].linhas = (int *)malloc(sizeof(int));
            vet[i].linhas[0] = l;
        }
    } while(1);

    for(i = 0; i < tamVet; i ++) {
        printf("Valor: %d\n", vet[i].valor);
        printf("Count: %d\nLinhas: ", vet[i].count);
        for(int j = 0; j < vet[i].count; j ++) {
            printf("%d ", vet[i].linhas[j]);
        }
        printf("\n");
    }
}

int main(void) {
    // retRepet("arq1", "arq2");
    // media("arqEnt.txt", "arqSaida");
    resumo("arq.txt");

    return 0;
}
