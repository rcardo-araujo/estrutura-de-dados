#include <stdio.h>
#include <stdlib.h>

#define TAM_PLV 11

void prod_cartesiano(FILE* arq_a, FILE* arq_b) {
    FILE* arq_c = fopen("c.bin", "wb");
    if(!arq_c) return;

    int r, s;
    char p_a[TAM_PLV], p_b[TAM_PLV];
    r = fread(p_a, sizeof(char), TAM_PLV, arq_a);
    while(r == TAM_PLV) {
        s = fread(p_b, sizeof(char), TAM_PLV, arq_b);
        while(s == TAM_PLV) {
            printf("Palavra A: %s\n", p_a);
            printf("Palavra B: %s\n", p_b);
            fwrite(p_a, sizeof(char), TAM_PLV, arq_c);
            fwrite(p_b, sizeof(char), TAM_PLV, arq_c);
            s = fread(p_b, sizeof(char), TAM_PLV, arq_b);
        }
        fseek(arq_b, 0, SEEK_SET);
        r = fread(p_a, sizeof(char), TAM_PLV, arq_a);
    }
}

int main(void) {
    FILE* arq_a = fopen("a.bin", "rb");
    FILE* arq_b = fopen("b.bin", "rb");
    if((!arq_a) || (!arq_b)) {
        printf("Nao foi possivel abrir algum arquivo!");
        return 0;
    }

    prod_cartesiano(arq_a, arq_b);
    fclose(arq_a);
    fclose(arq_b);
}
