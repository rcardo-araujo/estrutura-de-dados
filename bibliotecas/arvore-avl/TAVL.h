typedef struct AVL {
    int info;
    int alt;
    struct AVL* esq;
    struct AVL* dir;
} TAVL;

TAVL* TAVL_inicializa(void);
TAVL* TAVL_cria(int x);
TAVL* TAVL_insere(TAVL* arv, int x);
TAVL* TAVL_retira(TAVL* arv, int x);
TAVL* TAVL_busca(TAVL* arv, int x);
void TAVL_imprime(TAVL* arv, int tab);
TAVL* TAVL_libera(TAVL* arv);
