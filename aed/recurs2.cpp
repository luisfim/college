#include <cstdio>

int maior_elemento(int vet[], int n) {
    // Com apenas um elemento, ele é o maior.
    if (n == 1) {
        return vet[0];
    }

    // Descobre o maior entre os primeiros n - 1 elementos.
    int maior = maior_elemento(vet, n - 1);

    // Compara esse resultado com o último elemento considerado.
    if (vet[n - 1] > maior) {
        return vet[n - 1];
    }

    return maior;
}