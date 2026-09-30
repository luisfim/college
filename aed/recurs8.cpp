// 8. Maior elemento: versao iterativa.
#include <cstdio>

int maior_elemento(int vet[], int n) {
    // Comecar em vet[0] tambem funciona com valores todos negativos.
    int maior = vet[0];
    for (int i = 1; i < n; i++) {
        if (vet[i] > maior) maior = vet[i];
    }
    return maior;
}

int main() {
    int vet[1000], n;
    std::printf("Tamanho do vetor (1 a 1000): ");
    if (std::scanf("%d", &n) != 1 || n < 1 || n > 1000) {
        std::printf("Tamanho invalido.\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        std::printf("Elemento %d: ", i + 1);
        if (std::scanf("%d", &vet[i]) != 1) return 1;
    }
    std::printf("Maior elemento: %d\n", maior_elemento(vet, n));
    return 0;
}
