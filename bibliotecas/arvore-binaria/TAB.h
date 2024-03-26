typedef struct AB {
    int info;
    struct AB* esq;
    struct AB* dir;
} TAB;

TAB* TAB_inicializa();
TAB* TAB_cria(int info, TAB* esq, TAB* dir);
TAB* TAB_busca(int info, TAB* raiz);
