// Listas 3. Insercao automatica em ordem crescente.

#include <cstdio>
#include <new>

struct No {
    int dado;
    No* ptr;
};

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

bool inserirOrdenado(No*& inicio, int valor) {
    No* novo = new (std::nothrow) No{valor, nullptr};
    if (novo == nullptr) return false;
    if (inicio == nullptr || valor <= inicio->dado) {
        novo->ptr = inicio;
        inicio = novo;
        return true;
    }
    No* atual = inicio;
    while (atual->ptr != nullptr && atual->ptr->dado < valor) atual = atual->ptr;
    novo->ptr = atual->ptr;
    atual->ptr = novo;
    return true;
}

int main() {
    No* inicio = nullptr;
    int opcao, valor;
    int resultado = 0;
    while (true) {
        std::printf("\n1 - Inserir ordenado\n2 - Remover\n3 - Exibir\n0 - Sair\nOpcao: ");
        if (std::scanf("%d", &opcao) != 1) { resultado = 1; break; }
        if (opcao == 0) break;
        if (opcao == 1 || opcao == 2) {
            std::printf("Valor: ");
            if (std::scanf("%d", &valor) != 1) { resultado = 1; break; }
            if (opcao == 1 && !inserirOrdenado(inicio, valor)) std::printf("Sem memoria.\n");
            if (opcao == 2 && !remover(inicio, valor)) std::printf("Valor nao encontrado.\n");
        } else if (opcao == 3) {
            exibir(inicio);
        } else {
            std::printf("Opcao invalida.\n");
        }
    }
    liberar(inicio);
    return resultado;
}
