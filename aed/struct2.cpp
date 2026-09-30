// 2. Vetor de cinco alunos e media das notas.
#include <cstdio>

struct Aluno {
    char Nome[51];
    int Matricula;
    float Nota;
};

int main() {
    Aluno alunos[5];
    float soma = 0;
    for (int i = 0; i < 5; i++) {
        std::printf("\nAluno %d\nNome: ", i + 1);
        if (std::scanf(" %50[^\n]", alunos[i].Nome) != 1) return 1;
        std::printf("Matricula: ");
        if (std::scanf("%d", &alunos[i].Matricula) != 1) return 1;
        std::printf("Nota: ");
        if (std::scanf("%f", &alunos[i].Nota) != 1) return 1;
        soma += alunos[i].Nota;
    }
    std::printf("\nMedia das notas: %.2f\n", soma / 5);
    return 0;
}
