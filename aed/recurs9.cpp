// 9. Soma dos digitos: versao iterativa.
#include <cstdio>

int soma_digitos(int n) {
    int soma = 0;
    while (n != 0) {
        int digito = n % 10;
        if (digito < 0) digito = -digito;
        soma += digito;
        n /= 10;
    }
    return soma;
}

int main() {
    int n;
    std::printf("Numero inteiro: ");
    if (std::scanf("%d", &n) != 1) return 1;
    std::printf("Soma dos digitos: %d\n", soma_digitos(n));
    return 0;
}
