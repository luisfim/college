// 1. Contagem recursiva de digitos; o sinal nao conta como digito.
#include <cstdio>

int contar_digitos(int n) {
    if (n > -10 && n < 10) return 1;
    return 1 + contar_digitos(n / 10);
}

int main() {
    int n;
    std::printf("Numero inteiro: ");
    if (std::scanf("%d", &n) != 1) return 1;
    std::printf("Quantidade de digitos: %d\n", contar_digitos(n));
    return 0;
}
