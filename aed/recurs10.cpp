// 10. Produto sem multiplicacao: versao iterativa.
#include <cstdio>

long long produto(int a, int b) {
    long long resultado = 0;
    while (b > 0) {
        resultado += a;
        b--;
    }
    while (b < 0) {
        resultado -= a;
        b++;
    }
    return resultado;
}

int main() {
    int a, b;
    std::printf("Primeiro inteiro: ");
    if (std::scanf("%d", &a) != 1) return 1;
    std::printf("Segundo inteiro (-1000 a 1000): ");
    // Limite didatico para evitar milhares de chamadas recursivas.
    if (std::scanf("%d", &b) != 1 || b < -1000 || b > 1000) return 1;
    std::printf("Produto: %lld\n", produto(a, b));
    return 0;
}
