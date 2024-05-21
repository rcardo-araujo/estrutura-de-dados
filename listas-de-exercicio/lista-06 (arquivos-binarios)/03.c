#include <stdio.h>
#include <stdlib.h>

#define TAM_REG 65
#define TAM_NOME 41
#define TAM_CPF 12

void ordena(float* vet_s, int* vet_i, int tam) {
    int i, j, menor, i_menor;
    for(i = 0; i < tam; i ++) {
        menor = vet_s[i], i_menor = i;
        for(j = i + 1; j < tam; j ++) {
            if(vet_s[j] < menor) {
                menor = vet_s[j];
                i_menor = j;
            }
        }

        if(menor != vet_s[i]) {
            vet_s[i_menor] = vet_s[i];
            vet_s[i] = menor;

            int tmp = vet_i[i_menor];
            vet_i[i_menor] = vet_i[i];
            vet_i[i] = tmp;
        }
    }
}

void indices(char* arq_ent, char* arq_saida) {
    FILE* arq_e = fopen(arq_ent, "rb");
    FILE* arq_s = fopen(arq_saida, "wb");
    if((!arq_e) || (!arq_s)) {
        printf("Nao foi possivel abrir arquivo!\n");
        return;
    }

    fseek(arq_e, 0, SEEK_END);
    int tam = ftell(arq_e) / TAM_REG;
    
    int vet_indice[tam], i, resp;
    float vet_saldo[tam], aux;
    fseek(arq_e, TAM_REG - sizeof(float), SEEK_SET);

    resp = fread(&aux, sizeof(float), 1, arq_e);
    for(i = 0; resp == 1; i ++) {
        vet_indice[i] = i;
        vet_saldo[i] = aux;
        fseek(arq_e, TAM_REG - sizeof(float), SEEK_CUR);
        resp = fread(&aux, sizeof(float), 1, arq_e);
    }
    fclose(arq_e);

    ordena(vet_saldo, vet_indice, tam);
    fwrite(vet_indice, sizeof(int), tam, arq_s);
    fclose(arq_s);
}

int main(int argc, char** argv) {
    char* arq_ent = argv[1],
        * arq_saida = argv[2];

    indices(arq_ent, arq_saida);
    return 0;
}
