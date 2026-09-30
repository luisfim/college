// 1. Criando uma estrutura simples.
#include <cstdio>

struct Pessoa {
    char Nome[51]; // 50 caracteres e o terminador '\0'.
    int Idade;
    float Altura;
};

int main() {
    Pessoa usuario;
    std::printf("Nome: ");
    if (std::scanf(" %50[^\n]", usuario.Nome) != 1) return 1;
    std::printf("Idade: ");
    if (std::scanf("%d", &usuario.Idade) != 1) return 1;
    std::printf("Altura (em metros): ");
    if (std::scanf("%f", &usuario.Altura) != 1) return 1;
    std::printf("\nNome: %s\nIdade: %d\nAltura: %.2f m\n",
                usuario.Nome, usuario.Idade, usuario.Altura);
    return 0;
}
