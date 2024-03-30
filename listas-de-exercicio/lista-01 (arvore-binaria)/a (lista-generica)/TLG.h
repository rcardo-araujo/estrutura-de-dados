#ifndef TLG_H
#define TLG_H

typedef struct LG {
    void* info;
    struct LG* prox;
} TLG;

typedef void callback(void* info, void* dado);

TLG* TLG_inicializa(void);
int TLG_vazia(TLG* lista);
TLG* TLG_insere(TLG* lista, void* info);
void TLG_percorre(TLG* lista, callback* cb, void* dado);

#endif
