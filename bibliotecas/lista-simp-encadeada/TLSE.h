#ifndef TLSE_H
#define TLSE_H

typedef struct lse{
  int info;
  struct lse *prox;
}TLSE;

TLSE* TLSE_inicializa(void);
TLSE* TLSE_insere(TLSE *l, int elem);
TLSE* TLSE_insere_fim_rec(TLSE* l, int elem);
void TLSE_imprime(TLSE *l);
void TLSE_libera(TLSE *l);
TLSE* TLSE_retira(TLSE *l, int elem);
TLSE* TLSE_busca(TLSE *l, int elem);

void TLSE_imp_rec(TLSE *l);
void TLSE_imp_rec_rev(TLSE *l);
void TLSE_lib_rec(TLSE *l);
TLSE* TLSE_busca_rec(TLSE *l, int elem);
TLSE* TLSE_retira_rec(TLSE *l, int elem);

#endif
