// 3. Passando uma struct para uma funcao.
#include <cstdio>

struct Produto {
    char Nome[31];
    int Codigo;
    float Preco;
};

void Info(Produto item) {
    std::printf("\nProduto: %s\nCodigo: %d\nPreco: R$ %.2f\n",
                item.Nome, item.Codigo, item.Preco);
}

int main() {
    Produto item;
    std::printf("Nome do produto: ");
    if (std::scanf(" %30[^\n]", item.Nome) != 1) return 1;
    std::printf("Codigo: ");
    if (std::scanf("%d", &item.Codigo) != 1) return 1;
    std::printf("Preco: ");
    if (std::scanf("%f", &item.Preco) != 1) return 1;
    Info(item);
    return 0;
}
