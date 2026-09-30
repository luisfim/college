// Pilhas 8. Os restos da divisao por 2 saem da pilha na ordem correta.
#include <cstdio>
#include <climits>

void exibirBinario(unsigned int numero) {
    int pilha[sizeof(unsigned int) * CHAR_BIT];
    int topo = -1;
    // do/while garante um digito mesmo quando o numero e zero.
    do {
        pilha[++topo] = numero % 2;
        numero /= 2;
    } while (numero != 0);
    while (topo >= 0) std::printf("%d", pilha[topo--]);
    std::printf("\n");
}

int main() {
    int numero;
    std::printf("Inteiro nao negativo: ");
    if (std::scanf("%d", &numero) != 1 || numero < 0) return 1;
    std::printf("Binario: ");
    exibirBinario(static_cast<unsigned int>(numero));
    return 0;
}
