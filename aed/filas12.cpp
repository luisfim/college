// Filas 12. Inversao de uma fila com uma pilha auxiliar.

#include <cstdio>

const int CAPACIDADE = 100;

struct Fila {
    int dados[CAPACIDADE];
    int inicio = 0;
    int fim = 0; // Proxima posicao de insercao.
    int quantidade = 0;
};

bool isEmpty(const Fila& fila) {
    return fila.quantidade == 0;
}

bool enqueue(Fila& fila, int valor) {
    if (fila.quantidade == CAPACIDADE) return false;
    fila.dados[fila.fim] = valor;
    fila.fim = (fila.fim + 1) % CAPACIDADE;
    fila.quantidade++;
    return true;
}

bool dequeue(Fila& fila, int& valor) {
    if (isEmpty(fila)) return false;
    valor = fila.dados[fila.inicio];
    fila.inicio = (fila.inicio + 1) % CAPACIDADE;
    fila.quantidade--;
    return true;
}

bool front(const Fila& fila, int& valor) {
    if (isEmpty(fila)) return false;
    valor = fila.dados[fila.inicio];
    return true;
}

struct Pilha {
    int dados[CAPACIDADE];
    int topo = -1;
};

void inverterFila(Fila& fila) {
    Pilha pilha;
    int valor;
    // A pilha tem a mesma capacidade da fila, entao todos os itens cabem.
    while (dequeue(fila, valor)) pilha.dados[++pilha.topo] = valor;
    while (pilha.topo >= 0) enqueue(fila, pilha.dados[pilha.topo--]);
}

void exibir(const Fila& fila) {
    if (isEmpty(fila)) {
        std::printf("Fila vazia.\n");
        return;
    }
    for (int i = 0; i < fila.quantidade; i++) {
        int posicao = (fila.inicio + i) % CAPACIDADE;
        std::printf("%d%s", fila.dados[posicao], i + 1 == fila.quantidade ? "\n" : " ");
    }
}

int main() {
    Fila fila;
    int n, valor;
    std::printf("Quantidade de elementos (0 a 100): ");
    if (std::scanf("%d", &n) != 1 || n < 0 || n > CAPACIDADE) return 1;
    for (int i = 0; i < n; i++) {
        std::printf("Elemento %d: ", i + 1);
        if (std::scanf("%d", &valor) != 1) return 1;
        enqueue(fila, valor);
    }
    std::printf("Fila original: ");
    exibir(fila);
    inverterFila(fila);
    std::printf("Fila invertida: ");
    exibir(fila);
    return 0;
}
