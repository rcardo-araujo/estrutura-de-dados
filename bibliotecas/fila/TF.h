#include <stdlib.h>
#include <stdio.h>

typedef struct tno{
	int info;
	struct tno *prox;
}TNO;

typedef struct{
	TNO *inicio, *fim;
}TF;

TF* TF_inicializa(void);
int TF_vazia(TF *fila);
void TF_insere(TF *fila, int x);
int TF_retira(TF *fila);
void TF_libera(TF *fila);
void TF_imprime(TF *fila);