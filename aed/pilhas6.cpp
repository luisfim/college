// Pilhas 6. Cada ')' deve fechar o '(' do topo da pilha.
#include <cstdio>
#include <cstring>

bool balanceados(const char expressao[]) {
    char pilha[200];
    int topo = -1;
    for (int i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            if (topo == 199) return false;
            pilha[++topo] = '(';
        } else if (expressao[i] == ')') {
            if (topo == -1 || pilha[topo] != '(') return false;
            topo--;
        }
    }
    return topo == -1;
}

int main() {
    char expressao[201];
    std::printf("Expressao (ate 200 caracteres): ");
    if (std::fgets(expressao, sizeof(expressao), stdin) == nullptr) return 1;
    expressao[std::strcspn(expressao, "\r\n")] = '\0';
    std::printf("%s\n", balanceados(expressao) ? "Valido" : "Invalido");
    return 0;
}
