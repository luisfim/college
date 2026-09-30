// 7. Agenda: adicionar e buscar contatos pelo nome completo.
#include <cstdio>
#include <cstring>

struct Contato {
    char Nome[51];
    char Telefone[16]; // 15 caracteres e '\0'.
};

int main() {
    Contato agenda[100];
    int quantidade = 0;
    int opcao;
    while (true) {
        std::printf("\n1 - Adicionar\n2 - Buscar\n0 - Sair\nOpcao: ");
        if (std::scanf("%d", &opcao) != 1) return 1;
        if (opcao == 0) break;
        if (opcao == 1) {
            if (quantidade == 100) {
                std::printf("Agenda cheia.\n");
                continue;
            }
            std::printf("Nome: ");
            if (std::scanf(" %50[^\n]", agenda[quantidade].Nome) != 1) return 1;
            std::printf("Telefone: ");
            if (std::scanf(" %15[^\n]", agenda[quantidade].Telefone) != 1) return 1;
            quantidade++;
            std::printf("Contato adicionado.\n");
        } else if (opcao == 2) {
            char nome[51];
            bool encontrou = false;
            std::printf("Nome completo para buscar: ");
            if (std::scanf(" %50[^\n]", nome) != 1) return 1;
            for (int i = 0; i < quantidade; i++) {
                if (std::strcmp(agenda[i].Nome, nome) == 0) {
                    std::printf("%s | %s\n", agenda[i].Nome, agenda[i].Telefone);
                    encontrou = true;
                }
            }
            if (!encontrou) std::printf("Contato nao encontrado.\n");
        } else {
            std::printf("Opcao invalida.\n");
        }
    }
    return 0;
}
