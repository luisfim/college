// 6. Palindromo: compara as extremidades e avanca para o centro.
#include <cstdio>
#include <cstring>

int verificar(const char texto[], int inicio, int fim) {
    if (inicio >= fim) return 1;
    if (texto[inicio] != texto[fim]) return 0;
    return verificar(texto, inicio + 1, fim - 1);
}

int palindromo(const char texto[]) {
    return verificar(texto, 0, static_cast<int>(std::strlen(texto)) - 1);
}

int main() {
    char texto[201];
    std::printf("Texto (ate 200 caracteres): ");
    if (std::fgets(texto, sizeof(texto), stdin) == nullptr) return 1;
    texto[std::strcspn(texto, "\r\n")] = '\0';
    std::printf("Palindromo: %d\n", palindromo(texto));
    return 0;
}
