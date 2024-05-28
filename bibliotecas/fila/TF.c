#include "TF.h"

/*Inicializando a fila:*/
TF* TF_inicializa(void){
	TF *fila = (TF *)malloc(sizeof(TF));
	fila->inicio = NULL;
	fila->fim = NULL;
	return fila;
}

/*Verifica se a fila est� vazia:*/
int TF_vazia(TF *fila){
	return !fila->inicio;
}

/*Inserindo novos elementos:*/
void TF_insere(TF *fila, int x){
	TNO *novo = (TNO *)malloc(sizeof(TNO));
	novo->info = x;
	novo->prox = NULL;
	if(!TF_vazia(fila)) fila->fim->prox = novo;
	else fila->inicio = novo;
	fila->fim = novo;
}

/*Retirando elementos da fila (sempre no inicio):*/
int TF_retira(TF *fila){
	if(TF_vazia(fila)) return 0;
	int x = fila->inicio->info;
	TNO *tmp = fila->inicio;
	fila->inicio = fila->inicio->prox;
	if(!fila->inicio) fila->fim = NULL;
	free(tmp);
	return x;
}

/*Liberando a fila:*/
void TF_libera(TF *fila){
	while(!TF_vazia) TF_retira(fila);
	free(fila->inicio);
	free(fila->fim);
	free(fila);
}

/*Imprimindo fila:*/
void TF_imprime(TF *fila){
	if(TF_vazia(fila)) return;
	TF *aux = TF_inicializa();
	int i;
	for(i = 1; !TF_vazia(fila); i++){
		printf("Dado %d -> %d\n", i, fila->inicio->info);
		TF_insere(aux, TF_retira(fila));
	}
	while(!TF_vazia(aux)) TF_insere(fila, TF_retira(aux));
	TF_libera(aux);
}
