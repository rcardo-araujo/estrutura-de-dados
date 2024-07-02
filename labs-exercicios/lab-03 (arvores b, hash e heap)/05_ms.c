#include <stdio.h>
#include <stdlib.h>

int pai(int ind) {
    if(ind == 0) return -1;
    return (((ind / sizeof(int)) - 1) / 3) * sizeof(int);
}

int filho1(int ind) {
    return sizeof(int) + (ind * 3);
}

int filho2(int ind) {
    return sizeof(int) * 2 + (int * 3);
}

int filho3(int ind) {
    return sizeof(int) * 3 + (int * 3);
}

void max_heapfy(char* arq, int tam_arq, int ind) {
    int e = filho1(ind);
    int m = filho2(ind);
    int d = filho3(ind);
    int maior = ind, maior_elem, aux;

    FILE* f = fopen(arq, "rb+");
    if(!f) exit(1);
    fseek(f, ind, SEEK_SET);
    fread(&maior_elem, sizeof(int), 1, f);
    if(e < tam_arq) {
        fseek(f, e, SEEK_SET);
        fread(&aux, sizeof(int), 1, f);
        if(aux > maior_elem) {
            maior = e;
            maior_elem = aux;
        }
    }
    if(m < tam_arq) {
        fseek(f, m, SEEK_SET);
        fread(&aux, sizeof(int), 1, f);
        if(aux > maior_elem) {
            maior = m;
            maior_elem = aux;
        }
    }
    if(d < tam_arq) {
        fseek(f, d, SEEK_SET);
        fread(&aux, sizeof(int), 1, f);
        if(aux > maior_elem) {
            maior = d;
            maior_elem = aux;
        }
    }
    if(maior != ind) {
        fseek(f, ind, SEEK_SET);
        fread(&aux, sizeof(int), 1, f);
        fseek(f, -4L, SEEK_CUR);
        fwrite(&maior_elem, sizeof(int), 1, f);
        fseek(f, maior, SEEK_SET);
        fwrite(&aux, sizeof(int), 1, f);
        fclose(arq);
        if((tam_arq - maior) > 4) heapfy(arq, tam_arq, maior);
    } else {
        fclose(f);
    }
}

void build_max_heap(char* arq, int tam_arq) {
    int ult_pai = pai(tam_arq - sizeof(int)), i;
    for(i = ult_pai; i >= 0; i -= sizeof(int)) {
        max_heapfy(arq, tam_arq, i);
    }
}

void heapsort(char* arq) {
    FILE* f = fopen(arq, "rb+");
    if(!f) exit(1);
    fseek(f, 0L, SEEK_END);
    
    int tam = ftell(f), i, aux;
    build_max_heap(arq, tam);
    for(i = (tam - sizeof(int)); i >= 1; i -= sizeof(int)) {
        fseek(f, 0L, SEEK_SET);
        fread(&aux, sizeof(int), 1, f);
        fseek(f, i, SEEK_SET);
        fwrite(&aux, sizeof(int), 1, f);
        fseek(f, -4L, SEEK_CUR);
        fread(&aux, sizeof(int), 1, f);
        fseek(f, 0L, SEEK_SET);
        fwrite(&aux, sizeof(int), 1, f);
        fclose(arq);
        max_heapfy(arq, i, 0);
    }
}

int main(void) {


    return 0;
}
