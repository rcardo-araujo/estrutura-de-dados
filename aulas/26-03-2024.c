#include "../bibliotecas/arvore-binaria/TAB.h"

TAB* vet2ab(int* vet, int n) {
    if(n <= 0) return NULL;

    
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

    TAB* arv = TAB_incializa();
    arv = vet2ab(vetor, n); 

    // imprimindo o vetor
    for(i = 0; i < n; i ++)
        printf("%d | ", vetor[i]);
    printf("\n");
    
    // TAB_imprime(r);

    return 0;
}
