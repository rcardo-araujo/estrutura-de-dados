#include <stdio.h>
#include <stdlib.h>

int pai(int* vet, int i) {
    if(!i) return -1;
    return (i - 1) / 3;
}

int filho1(int* vet, int i) {
    return 1 + (i * 3);
}

int filho2(int* vet, int i) {
    return 2 + (i * 3);
}

int filho3(int* vet, int i) {
    return 3 + (i * 3);
}

void max_heapfy(int* vet, int n, int i) {
    int e = filho1(vet, i);
    int m = filho2(vet, i);
    int d = filho3(vet, i);
    
    int maior = i;
    if((e < n) && (vet[e] > vet[i])) maior = e;
    if((m < n) && (vet[m] > vet[maior])) maior = m;
    if((d < n) && (vet[d] > vet[maior])) maior = d;
    if(maior != i) {
        int temp = vet[i];
        vet[i] = vet[maior];
        vet[maior] = temp;
        max_heapfy(vet, n, maior);
    }
}

// Contrói uma heap máxima, sem
// critério de ordenação
void build_max_heap(int* vet, int n) {
    int ind = pai(vet, n - 1), i;
    if(ind == -1) return;
    for(i = ind; i >= 0; i--) {
        max_heapfy(vet, n, i);
    }
}

// Ordenação em ordem crescente
void heapsort(int* vet, int n) {
    int i;
    build_max_heap(vet, n);
    for(i = (n - 1); i >= 1; i--) {
        int temp = vet[0];
        vet[0] = vet[i];
        vet[i] = temp;
        max_heapfy(vet, i, 0);
    }
}

void imprime_vet(int* vet, int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
}

int main(void) {
    int i, n, m;
    
    printf("Digite o tamanho da heap: ");
    scanf("%d", &n);
    int* vet = (int*)malloc(sizeof(int) * n);
    printf("Digite 'n' elementos: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &m);
        vet[i] = m;
    }

    printf("\n---Vetor normal---\n");
    imprime_vet(vet, n);

    build_max_heap(vet, n);
    printf("\n---Heap sem Ordenação---\n");
    imprime_vet(vet, n);

    heapsort(vet, n);
    printf("\n---Heap Ordenada---\n");
    imprime_vet(vet, n);

    return 0;
}
