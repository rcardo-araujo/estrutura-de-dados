#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/arvore-binaria/TAB.h"

TAB* vet2ab(int* vet, int n) {
    if(n <= 0) return NULL;

    return TAB_cria(vet[n/2],
        vet2ab(vet, n/2),
        vet2ab(&vet[(n/2) + 1], n - (n/2) - 1)
    );
}

int main() {
    int n;
    scanf("%d", &n);
    int* vetor = (int *)malloc(sizeof(int) * n);

    int x, i;
    for(i = 0; i < n; i ++) {
        scanf("%d", &x);
        vetor[i] = x;
    }

    TAB* arv = TAB_inicializa();
    arv = vet2ab(vetor, n); 

    // imprimindo o vetor
    for(i = 0; i < n; i ++)
        printf("%d | ", vetor[i]);
    printf("\n");
    
    TAB_imprime(0, arv);

    return 0;
}
