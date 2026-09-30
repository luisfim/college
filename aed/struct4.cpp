// 4. Struct, ponteiro, malloc e free.
#include <cstdio>
#include <cstdlib>

struct Carro {
    char Modelo[31];
    int Ano;
    float Preco;
};

int main() {
    // Em C++, o retorno de malloc precisa ser convertido para Carro*.
    Carro* ponteiro = static_cast<Carro*>(std::malloc(sizeof(Carro)));
    if (ponteiro == nullptr) {
        std::printf("Nao foi possivel alocar memoria.\n");
        return 1;
    }
    // A seta acessa os campos da struct por meio do ponteiro.
    std::printf("Modelo: ");
    if (std::scanf(" %30[^\n]", ponteiro->Modelo) != 1) {
        std::free(ponteiro);
        return 1;
    }
    std::printf("Ano: ");
    if (std::scanf("%d", &ponteiro->Ano) != 1) {
        std::free(ponteiro);
        return 1;
    }
    std::printf("Preco: ");
    if (std::scanf("%f", &ponteiro->Preco) != 1) {
        std::free(ponteiro);
        return 1;
    }
    std::printf("\nModelo: %s\nAno: %d\nPreco: R$ %.2f\n",
                ponteiro->Modelo, ponteiro->Ano, ponteiro->Preco);
    std::free(ponteiro);
    return 0;
}
