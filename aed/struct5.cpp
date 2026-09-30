// 5. Cadastro de N funcionarios.
#include <cstdio>
#include <vector>

struct Funcionario {
    char Nome[51];
    char Cargo[31];
    float Salario;
};

int main() {
    int N;
    std::printf("Quantidade de funcionarios (1 a 1000): ");
    if (std::scanf("%d", &N) != 1 || N < 1 || N > 1000) {
        std::printf("Quantidade invalida.\n");
        return 1;
    }
    std::vector<Funcionario> trabalhadores(N);
    for (int i = 0; i < N; i++) {
        std::printf("\nFuncionario %d\nNome: ", i + 1);
        if (std::scanf(" %50[^\n]", trabalhadores[i].Nome) != 1) return 1;
        std::printf("Cargo: ");
        if (std::scanf(" %30[^\n]", trabalhadores[i].Cargo) != 1) return 1;
        std::printf("Salario: ");
        if (std::scanf("%f", &trabalhadores[i].Salario) != 1) return 1;
    }
    std::printf("\nFuncionarios cadastrados:\n");
    for (int i = 0; i < N; i++) {
        std::printf("%s | %s | R$ %.2f\n", trabalhadores[i].Nome,
                    trabalhadores[i].Cargo, trabalhadores[i].Salario);
    }
    return 0;
}
