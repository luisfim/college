// Filas 9. Fila simples usando vetor.

#include <cstdio>

const int CAPACIDADE = 100;

struct Fila {
    int dados[CAPACIDADE];
    int quantidade = 0;
};

bool isEmpty(const Fila& fila) {
    return fila.quantidade == 0;
}

bool enqueue(Fila& fila, int valor) {
    if (fila.quantidade == CAPACIDADE) return false;
    fila.dados[fila.quantidade++] = valor;
    return true;
}

bool dequeue(Fila& fila, int& valor) {
    if (isEmpty(fila)) return false;
    valor = fila.dados[0];
    // Na fila simples, deslocamos os restantes para a esquerda.
    for (int i = 1; i < fila.quantidade; i++) fila.dados[i - 1] = fila.dados[i];
    fila.quantidade--;
    return true;
}

bool front(const Fila& fila, int& valor) {
    if (isEmpty(fila)) return false;
    valor = fila.dados[0];
    return true;
}

int main() {
    Fila fila;
    int opcao, valor;
    while (true) {
        std::printf("\n1 - Enqueue\n2 - Dequeue\n3 - Front\n4 - IsEmpty\n0 - Sair\nOpcao: ");
        if (std::scanf("%d", &opcao) != 1) return 1;
        if (opcao == 0) break;
        if (opcao == 1) {
            std::printf("Valor: ");
            if (std::scanf("%d", &valor) != 1) return 1;
            if (!enqueue(fila, valor)) std::printf("Fila cheia.\n");
        } else if (opcao == 2) {
            if (dequeue(fila, valor)) std::printf("Removido: %d\n", valor);
            else std::printf("Fila vazia.\n");
        } else if (opcao == 3) {
            if (front(fila, valor)) std::printf("Primeiro: %d\n", valor);
            else std::printf("Fila vazia.\n");
        } else if (opcao == 4) {
            std::printf("Vazia: %s\n", isEmpty(fila) ? "sim" : "nao");
        } else {
            std::printf("Opcao invalida.\n");
        }
    }
    return 0;
}
