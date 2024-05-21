#include <stdio.h>
#include <stdlib.h>

void iSortBin(char* nome_arq) {
    FILE* arq = fopen(nome_arq, "rb+");
    if(!arq) return;

    int n, elem, aux;
    fseek(arq, 0, SEEK_END);
    n = ftell(arq) / sizeof(int);
    
    int i, j;
    for(i = 1; i < n; i ++) {
        fseek(arq, i * sizeof(int), SEEK_SET);
        fread(&elem, sizeof(int), 1, arq);
        for(j = i - 1; j >= 0; j --) {
            fseek(arq, j * sizeof(int), SEEK_SET);
            fread(&aux, sizeof(int), 1, arq);
            if(aux < elem) break;

            fseek(arq, (j + 1) * sizeof(int), SEEK_SET);
            fwrite(&aux, sizeof(int), 1, arq);
        }
        fseek(arq, (j + 1) * sizeof(int), SEEK_SET);
        fwrite(&elem, sizeof(int), 1, arq);
    }
    fclose(arq);
}

int main(void) {
    iSortBin("ref.bin");
    return 0;
}
