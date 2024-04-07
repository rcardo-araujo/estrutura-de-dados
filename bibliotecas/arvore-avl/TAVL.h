typedef struct AVL {
    int info;
    struct AVL* esq;
    struct AVL* dir;
} TAVL;

TAVL* TAVL_inicializa(void);
TAVL* TAVL_busca(TAVL* arv, int x);
void TAVL_imprime(TAVL* arv, int tab);
TAVL* TAVL_libera(TAVL* arv);
