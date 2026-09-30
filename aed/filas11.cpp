// Filas 11. Atendimento por ordem de chegada (FIFO).
#include <cstdio>

const int CAPACIDADE = 100;

struct Cliente {
    char Nome[51];
    int Senha;
};

struct Fila {
    Cliente clientes[CAPACIDADE];
    int inicio = 0;
    int fim = 0;
    int quantidade = 0;
};

bool enqueue(Fila& fila, Cliente cliente) {
    if (fila.quantidade == CAPACIDADE) return false;
    fila.clientes[fila.fim] = cliente;
    fila.fim = (fila.fim + 1) % CAPACIDADE;
    fila.quantidade++;
    return true;
}

bool dequeue(Fila& fila, Cliente& cliente) {
    if (fila.quantidade == 0) return false;
    cliente = fila.clientes[fila.inicio];
    fila.inicio = (fila.inicio + 1) % CAPACIDADE;
    fila.quantidade--;
    return true;
}

void exibir(const Fila& fila) {
    if (fila.quantidade == 0) std::printf("Nenhum cliente aguardando.\n");
    for (int i = 0; i < fila.quantidade; i++) {
        int posicao = (fila.inicio + i) % CAPACIDADE;
        std::printf("Senha %d | %s\n", fila.clientes[posicao].Senha,
                    fila.clientes[posicao].Nome);
    }
}

int main() {
    Fila fila;
    int proximaSenha = 1;
    int opcao;
    while (true) {
        std::printf("\n1 - Chegada de cliente\n2 - Atender\n3 - Exibir fila\n0 - Sair\nOpcao: ");
        if (std::scanf("%d", &opcao) != 1) return 1;
        if (opcao == 0) break;
        if (opcao == 1) {
            if (fila.quantidade == CAPACIDADE) {
                std::printf("Fila cheia.\n");
                continue;
            }
            Cliente cliente;
            std::printf("Nome: ");
            if (std::scanf(" %50[^\n]", cliente.Nome) != 1) return 1;
            cliente.Senha = proximaSenha++;
            enqueue(fila, cliente);
            std::printf("Senha recebida: %d\n", cliente.Senha);
        } else if (opcao == 2) {
            Cliente cliente;
            if (dequeue(fila, cliente)) {
                std::printf("Atendendo: senha %d | %s\n", cliente.Senha, cliente.Nome);
            } else {
                std::printf("Fila vazia.\n");
            }
        } else if (opcao == 3) {
            exibir(fila);
        } else {
            std::printf("Opcao invalida.\n");
        }
    }
    return 0;
}
