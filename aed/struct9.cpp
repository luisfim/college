// 9. Pacientes com idade acima de 60 anos.
#include <cstdio>
#include <vector>

struct Paciente {
    char Nome[51];
    int Idade;
    char Diagnostico[101];
};

void exibirIdosos(const Paciente pacientes[], int quantidade) {
    bool encontrou = false;
    for (int i = 0; i < quantidade; i++) {
        if (pacientes[i].Idade > 60) {
            std::printf("%s | %d anos | %s\n", pacientes[i].Nome,
                        pacientes[i].Idade, pacientes[i].Diagnostico);
            encontrou = true;
        }
    }
    if (!encontrou) std::printf("Nenhum paciente acima de 60 anos.\n");
}

int main() {
    int quantidade;
    std::printf("Quantidade de pacientes (1 a 1000): ");
    if (std::scanf("%d", &quantidade) != 1 || quantidade < 1 || quantidade > 1000) return 1;
    std::vector<Paciente> pacientes(quantidade);
    for (int i = 0; i < quantidade; i++) {
        std::printf("\nPaciente %d\nNome: ", i + 1);
        if (std::scanf(" %50[^\n]", pacientes[i].Nome) != 1) return 1;
        std::printf("Idade: ");
        if (std::scanf("%d", &pacientes[i].Idade) != 1) return 1;
        std::printf("Diagnostico: ");
        if (std::scanf(" %100[^\n]", pacientes[i].Diagnostico) != 1) return 1;
    }
    exibirIdosos(pacientes.data(), quantidade);
    return 0;
}
