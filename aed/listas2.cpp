// Listas 2. Lista encadeada simples.
// No*& permite que a funcao atualize o ponteiro de inicio do chamador.

#include <cstdio>
#include <new>

struct No {
    int dado;
    No* ptr;
};

bool inserirInicio(No*& inicio, int valor) {
    No* novo = new (std::nothrow) No{valor, inicio};
    if (novo == nullptr) return false;
    inicio = novo;
    return true;
}

bool inserirFinal(No*& inicio, int valor) {
    No* novo = new (std::nothrow) No{valor, nullptr};
    if (novo == nullptr) return false;
    if (inicio == nullptr) {
        inicio = novo;
        return true;
    }
    No* atual = inicio;
    while (atual->ptr != nullptr) atual = atual->ptr;
    atual->ptr = novo;
    return true;
}

bool remover(No*& inicio, int valor) {
    No* atual = inicio;
    No* anterior = nullptr;
    while (atual != nullptr && atual->dado != valor) {
        anterior = atual;
        atual = atual->ptr;
    }
    if (atual == nullptr) return false;
    if (anterior == nullptr) inicio = atual->ptr;
    else anterior->ptr = atual->ptr;
    delete atual; // Remove somente a primeira ocorrencia.
    return true;
}

void exibir(const No* inicio) {
    if (inicio == nullptr) {
        std::printf("Lista vazia.\n");
        return;
    }
    for (const No* atual = inicio; atual != nullptr; atual = atual->ptr) {
        std::printf("%d%s", atual->dado, atual->ptr == nullptr ? "\n" : " -> ");
    }
}

void liberar(No*& inicio) {
    while (inicio != nullptr) {
        No* apagar = inicio;
        inicio = inicio->ptr;
        delete apagar;
    }
}

int contar(const No* inicio) {
    int quantidade = 0;
    for (const No* atual = inicio; atual != nullptr; atual = atual->ptr) quantidade++;
    return quantidade;
}

int main() {
    No* inicio = nullptr;
    int opcao, valor;
    int resultado = 0;
    while (true) {
        std::printf("\n1 - Inserir no inicio\n2 - Inserir no final\n3 - Remover\n4 - Exibir\n5 - Contar\n0 - Sair\nOpcao: ");
        if (std::scanf("%d", &opcao) != 1) { resultado = 1; break; }
        if (opcao == 0) break;
        if (opcao >= 1 && opcao <= 3) {
            std::printf("Valor: ");
            if (std::scanf("%d", &valor) != 1) { resultado = 1; break; }
            if (opcao == 1 && !inserirInicio(inicio, valor)) std::printf("Sem memoria.\n");
            if (opcao == 2 && !inserirFinal(inicio, valor)) std::printf("Sem memoria.\n");
            if (opcao == 3 && !remover(inicio, valor)) std::printf("Valor nao encontrado.\n");
        } else if (opcao == 4) {
            exibir(inicio);
        } else if (opcao == 5) { std::printf("Quantidade: %d\n", contar(inicio)); } else {
            std::printf("Opcao invalida.\n");
        }
    }
    liberar(inicio);
    return resultado;
}
