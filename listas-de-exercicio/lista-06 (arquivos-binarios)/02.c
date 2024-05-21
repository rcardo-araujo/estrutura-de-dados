#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_REG 65
#define TAM_NOME 41
#define TAM_CPF 12

void consulta(char* nome_arq) {
    FILE* arq = fopen(nome_arq, "rb");
    if(!arq) {
        printf("Nao foi possiveo abrir o arquivo!\n");
        return;
    }

    fseek(arq, 0, SEEK_END);
    printf("Tam [%s]: %d\n", nome_arq, ftell(arq));

    char cpf_busca[12], cpf_aux[12], nome[41];
    int i, resp, conta_cor, agencia;
    float saldo;
    do {
        printf("Digite o CPF (sem pontos): ");
        scanf(" %s", cpf_busca);
        if(strlen(cpf_busca) == 1) break;
        
        fseek(arq, TAM_NOME, SEEK_SET);
        resp = fread(cpf_aux, sizeof(char), TAM_CPF, arq);
        for(i = 0; resp == TAM_CPF; i ++) {
            if(!strcmp(cpf_busca, cpf_aux)) {
                fseek(arq, i * TAM_REG, SEEK_SET);
                fread(nome, sizeof(char), TAM_NOME, arq);
                fseek(arq, TAM_CPF, SEEK_CUR);
                fread(&conta_cor, sizeof(int), 1, arq);
                fread(&agencia, sizeof(int), 1, arq);
                fread(&saldo, sizeof(float), 1, arq);

                printf("\nCliente encontrado!\nNome: %s\nCPF: %s\nConta Corrente: %d\nAgencia: %d\nSaldo: %f\n", nome, cpf_aux, conta_cor, agencia, saldo);
                break;
            }
            fseek(arq, ((i + 1) * TAM_REG) + TAM_NOME, SEEK_SET);
            resp = fread(cpf_aux, sizeof(char), TAM_CPF, arq);
        }
    } while(1);
    printf("Consulta finalizada!\n");
    fclose(arq);
}

int main(int argc, char** argv) {
    char* nome_arq = argv[1];
    consulta(nome_arq);
    return 0;
}
