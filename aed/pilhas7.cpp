// Pilhas 7. Empilha os caracteres e retira na ordem inversa.
#include <cstdio>
#include <cstring>

void inverterString(char texto[]) {
    char pilha[200];
    int topo = -1;
    int tamanho = static_cast<int>(std::strlen(texto));
    for (int i = 0; i < tamanho; i++) pilha[++topo] = texto[i];
    for (int i = 0; i < tamanho; i++) texto[i] = pilha[topo--];
}

int main() {
    char texto[201];
    std::printf("Texto (ate 200 caracteres, sem acentos): ");
    if (std::fgets(texto, sizeof(texto), stdin) == nullptr) return 1;
    texto[std::strcspn(texto, "\r\n")] = '\0';
    inverterString(texto);
    std::printf("Invertida: %s\n", texto);
    return 0;
}
