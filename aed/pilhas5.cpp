// Pilhas 5. O ultimo que entra e o primeiro que sai.

#include <cstdio>

const int CAPACIDADE = 100;

struct Pilha {
    int dados[CAPACIDADE];
    int topo = -1;
};

bool isEmpty(const Pilha& pilha) {
    return pilha.topo == -1;
}

bool push(Pilha& pilha, int valor) {
    if (pilha.topo == CAPACIDADE - 1) return false;
    pilha.dados[++pilha.topo] = valor;
    return true;
}

bool pop(Pilha& pilha, int& valor) {
    if (isEmpty(pilha)) return false;
    valor = pilha.dados[pilha.topo--];
    return true;
}

bool top(const Pilha& pilha, int& valor) {
    if (isEmpty(pilha)) return false;
    valor = pilha.dados[pilha.topo];
    return true;
}

int main() {
    Pilha pilha;
    int opcao, valor;
    while (true) {
        std::printf("\n1 - Push\n2 - Pop\n3 - Top\n4 - IsEmpty\n0 - Sair\nOpcao: ");
        if (std::scanf("%d", &opcao) != 1) return 1;
        if (opcao == 0) break;
        if (opcao == 1) {
            std::printf("Valor: ");
            if (std::scanf("%d", &valor) != 1) return 1;
            if (!push(pilha, valor)) std::printf("Pilha cheia.\n");
        } else if (opcao == 2) {
            if (pop(pilha, valor)) std::printf("Removido: %d\n", valor);
            else std::printf("Pilha vazia.\n");
        } else if (opcao == 3) {
            if (top(pilha, valor)) std::printf("Topo: %d\n", valor);
            else std::printf("Pilha vazia.\n");
        } else if (opcao == 4) {
            std::printf("Vazia: %s\n", isEmpty(pilha) ? "sim" : "nao");
        } else {
            std::printf("Opcao invalida.\n");
        }
    }
    return 0;
}
