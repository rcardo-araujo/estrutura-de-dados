#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void criaArqOrdenado(char* nomeArq) {
    FILE* f = fopen(nomeArq, "w");
    if(!f) {
        printf("Nao foi possivel abrir o arquivo!\n");
        exit(1);
    }

    int n, ant;
    scanf("%d", &ant);
    fprintf(f, "%d\n", ant);
    while(1) {
        scanf("%d", &n);
        if(n <= ant || n < 0) break;
        fprintf(f, "%d\n", n);
        ant = n;
    }
    fclose(f);
}

void merge(char* nomeArq1, char* nomeArq2, char* nomeArqResp) {
    FILE* f1 = fopen(nomeArq1, "r"),
        * f2 = fopen(nomeArq2, "r"),
        * resp = fopen(nomeArqResp, "w");
    if((!f1) || (!f2) || (!resp)) {
        printf("Nao foi possivel abrir todos os arquivos!\n");
        exit(1);
    }
    
    int r1, r2, n1, n2;
    r1 = fscanf(f1, "%d", &n1);
    r2 = fscanf(f2, "%d", &n2);
    while((r1 == 1) || (r2 == 1)) {
        if((r2 != 1) || (n1 <= n2)) {
            fprintf(resp, "%d\n", n1);
            if(n1 == n2) {
                r2 = fscanf(f2, "%d", &n2);
                if(r2 != 1) n2 = INT_MAX;
            }
            r1 = fscanf(f1, "%d", &n1);
            if(r1 != 1) n1 = INT_MAX;
        }
        else if((r1 != 1) || (n1 > n2)) {
            fprintf(resp, "%d\n", n2);
            r2 = fscanf(f2, "%d", &n2);
            if(r2 != 1) n2 = INT_MAX;
        }
    }
    fclose(f1);
    fclose(f2);
    fclose(resp);
}

int main(int argc, char** argv) {
    // I: [./output.exe] [nomeArq1] [nomeArq2] [nomeArqResp]
    FILE* fTeste = fopen(argv[1], "r");
    (fTeste) ? fclose(fTeste) : criaArqOrdenado(argv[1]);

    fTeste = fopen(argv[2], "r");
    (fTeste) ? fclose(fTeste) : criaArqOrdenado(argv[2]);

    merge(argv[1], argv[2], argv[3]);

    return 0;
} 
