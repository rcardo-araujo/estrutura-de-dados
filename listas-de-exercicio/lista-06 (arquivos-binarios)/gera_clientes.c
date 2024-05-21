#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 41
#define TAM_CPF 12

typedef struct C {
    char nome[TAM_NOME], cpf[TAM_CPF];
    int conta_cor, agencia;
    float saldo;
} Cliente;

int main(void) {
    FILE* arq = fopen("clientes.bin", "wb");
    if(arq == NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
        return 0;
    }

    int id = 0;
    char opcao_conta;
    do {
        Cliente c;
        printf("Cliente %d\n", ++id);
        printf("Nome: ");
        scanf(" %s", c.nome);
        if(strlen(c.nome) == 1) break;

        printf("CPF (sem pontos): ");
        scanf(" %s", c.cpf);
        printf("Conta Corrente? [S/N]: ");
        scanf(" %c", &opcao_conta);
        c.conta_cor = (opcao_conta == 'S') ? 1 : 0;
        printf("Agencia: ");
        scanf(" %d", &c.agencia);
        printf("Saldo: R$ ");
        scanf(" %f", &c.saldo);
        printf("\n");

        // Não é possível escrever a estrutura inteira
        // porque o sizeof é instável
        fwrite(c.nome, sizeof(char), TAM_NOME, arq);
        fwrite(c.cpf, sizeof(char), TAM_CPF, arq);
        fwrite(&c.conta_cor, sizeof(int), 1, arq);
        fwrite(&c.agencia, sizeof(int), 1, arq);
        fwrite(&c.saldo, sizeof(float), 1, arq);
    } while(1);
    fclose(arq);
    printf("%d clientes cadastrados com sucesso!\n", id - 1);
}
