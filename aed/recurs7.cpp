// 7. Contagem regressiva: versao iterativa.
#include <cstdio>

void contagem_regressiva(int n) {
    for (int i = n; i >= 0; i--) {
        std::printf("%d%s", i, i == 0 ? "\n" : ", ");
    }
}

int main() {
    int n;
    std::printf("Inicio da contagem (0 a 1000): ");
    if (std::scanf("%d", &n) != 1 || n < 0 || n > 1000) return 1;
    contagem_regressiva(n);
    return 0;
}
