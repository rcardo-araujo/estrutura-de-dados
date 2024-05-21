#include <stdio.h>
#include <stdlib.h>

void bSortBin(char* nome_arq) {
    FILE* arq = fopen(nome_arq, "rb+");
    if(!arq) {
        printf("Nao foi possivel abrir o arquivo!");
        exit(1);
    }

    int n, ant, atual;
    fseek(arq, 0, SEEK_END);
    n = ftell(arq) / sizeof(int);

    int i, j, flag;
    for(i = 0; i < n - 1; i ++) {
        flag = 0;
        for(j = 0; j < (n - i) - 1; j ++) {
            fseek(arq, j * sizeof(int), SEEK_SET);
            fread(&ant, sizeof(int), 1, arq);
            fread(&atual, sizeof(int), 1, arq);
            if(atual < ant) {
                fseek(arq, j * sizeof(int), SEEK_SET);
                fwrite(&atual, sizeof(int), 1, arq);
                fwrite(&ant, sizeof(int), 1, arq);
                flag = 1;
            }
        }
        if(!flag) break;
    }
    fclose(arq);
}

int main(void) {
    bSortBin("ref.bin");
    return 0;
}
