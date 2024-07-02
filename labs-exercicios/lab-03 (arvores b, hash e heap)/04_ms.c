#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/TH.h"

static char* tab_hash;
static char* dados;

// [A]
void inter(char* arq1, char* arq2, char* saida) {
    FILE* farq1 = fopen(arq1, "r");
    FILE* farq2 = fopen(arq2, "r");
    FILE* fsaida = fopen(saida, "w");
    if(!farq1 || !farq2 || !fsaida) exit(1);

    int r, s, num1, num2;
    r = fscanf(farq1, "%d", &num1);
    s = fscanf(farq2, "%d", &num2);
    while((r == 1) || (s == 1)) {
        if(r == 1) {
            TH_insere(tab_hash, dados, 5, num1);
            r = fscanf(farq1, "%d", &num1);
        }
        if(s == 1) {
            TH_insere(tab_hash, dados, 5, num2);
            s = fscanf(farq2, "%d", &num2);
        }
    }

    FILE* ftab_hash = fopen(tab_hash, "rb");
    FILE* fdados = fopen(dados, "rb");
    if(!(ftab_hash) || !(fdados)) exit(1);
    int n = 0, pos;
    TNUM aux;
    while(n < 5) {
        fseek(ftab_hash, n * sizeof(int), SEEK_SET);
        fread(&pos, sizeof(int), 1, ftab_hash);
        while(pos != -1) {
            fseek(fdados, pos, SEEK_SET);
            fread(&aux, sizeof(TNUM), 1, fdados);
            printf("Num: %d\tQtde: %d\n", aux.num, aux.qtde);
            if(aux.qtde == 2) fprintf(fsaida, "%d\n", aux.num);
            pos = aux.prox;
        }
        n++;
    }
    fclose(farq1);
    fclose(farq2);
    fclose(fsaida);
    fclose(ftab_hash);
    fclose(fdados);
}

// [B]
void dif_sim(char* arq1, char* arq2, char* saida) {
    FILE* farq1 = fopen(arq1, "r");
    FILE* farq2 = fopen(arq2, "r");
    FILE* fsaida = fopen(saida, "w");
    if(!farq1 || !farq2 || !fsaida) exit(1);

    int r, s, num1, num2;
    r = fscanf(farq1, "%d", &num1);
    s = fscanf(farq2, "%d", &num2);
    while((r == 1) || (s == 1)) {
        if(r == 1) {
            TH_insere(tab_hash, dados, 5, num1);
            r = fscanf(farq1, "%d", &num1);
        }
        if(s == 1) {
            TH_insere(tab_hash, dados, 5, num2);
            s = fscanf(farq2, "%d", &num2);
        }
    }
    TH_imprime(tab_hash, dados, 5);

    FILE* ftab_hash = fopen(tab_hash, "rb");
    FILE* fdados = fopen(dados, "rb");
    if(!(ftab_hash) || !(fdados)) exit(1);
    int n = 0, pos;
    TNUM aux;
    while(n < 5) {
        fseek(ftab_hash, n * sizeof(int), SEEK_SET);
        fread(&pos, sizeof(int), 1, ftab_hash);
        while(pos != -1) {
            fseek(fdados, pos, SEEK_SET);
            fread(&aux, sizeof(TNUM), 1, fdados);
            if(aux.qtde == 1) fprintf(fsaida, "%d\n", aux.num);
            pos = aux.prox;
        }
        n++;
    }
    fclose(farq1);
    fclose(farq2);
    fclose(fsaida);
    fclose(ftab_hash);
    fclose(fdados);
}

int main(int argc, char** argv) {
    tab_hash = argv[1];
    dados = argv[2];
    char* arq1 = "./04-arquivos/conj-01.txt";
    char* arq2 = "./04-arquivos/conj-02.txt";
    
    // inter(arq1, arq2, "./04-arquivos/inter.txt");
    dif_sim(arq1, arq2, "./04-arquivos/dif-sim.txt");

    return 0;
}
