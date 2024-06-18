#ifndef TFUNC_H
#define TFUNC_H

#include <stdio.h>

typedef struct FUNC {
    int id;
    char nome[20];
    char cpf[15];
    float salario;
} TFUNC;

typedef struct COLFUNC {
    TFUNC** vet;
    int tam;
} TCOLFUNC;

#define TAM_REG sizeof(TFUNC);
#define TAM_NOME 20;
#define TAM_CPF 15;

TFUNC* cria_func(int id, char* nome, char* cpf, float salario);
TCOLFUNC* adiciona_func(TFUNC* funcionario);
void save(FILE* arq, TFUNC** colecao);
TCOLFUNC* load(FILE* arq);
TFUNC* load_one(FILE* arq, int i);

#endif
