// 6. Livros publicados APOS o ano informado.
#include <cstdio>

struct Livro {
    char Titulo[51];
    char Autor[51];
    int Ano;
};

void Pesquisar(const Livro vetor[], int quantidade, int ano) {
    bool encontrou = false;
    for (int i = 0; i < quantidade; i++) {
        if (vetor[i].Ano > ano) {
            std::printf("%s | %s | %d\n", vetor[i].Titulo, vetor[i].Autor, vetor[i].Ano);
            encontrou = true;
        }
    }
    if (!encontrou) std::printf("Nenhum livro encontrado.\n");
}

int main() {
    Livro obras[3];
    int anoInicial;
    for (int i = 0; i < 3; i++) {
        std::printf("\nLivro %d\nTitulo: ", i + 1);
        if (std::scanf(" %50[^\n]", obras[i].Titulo) != 1) return 1;
        std::printf("Autor: ");
        if (std::scanf(" %50[^\n]", obras[i].Autor) != 1) return 1;
        std::printf("Ano de publicacao: ");
        if (std::scanf("%d", &obras[i].Ano) != 1) return 1;
    }
    std::printf("Buscar livros publicados apos qual ano? ");
    if (std::scanf("%d", &anoInicial) != 1) return 1;
    Pesquisar(obras, 3, anoInicial);
    return 0;
}
