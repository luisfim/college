#include <cstdio>
#include <cstdlib>

struct Carro {
    char Modelo[31];
    int Ano;
    float Preco;
};

int main() {
    // Reserva memória para um Carro e guarda seu endereço.
    Carro* ponteiro = static_cast<Carro*>(std::malloc(sizeof(Carro)));

    // Se a reserva falhar, encerra o programa.
    if (ponteiro == nullptr) {
        std::printf("Não foi possível alocar memória.\n");
        return 1;
    }

    // A seta acessa os campos do Carro pelo ponteiro.
    std::printf("Qual o modelo do carro? ");
    std::scanf(" %30[^\n]", ponteiro->Modelo);

    std::printf("Qual o ano? ");
    std::scanf("%d", &ponteiro->Ano);

    std::printf("Qual o preço? ");
    std::scanf("%f", &ponteiro->Preco);

    std::printf(
        "\nModelo: %s\nAno: %d\nPreço: R$ %.2f\n",
        ponteiro->Modelo,
        ponteiro->Ano,
        ponteiro->Preco
    );

    // Libera a memória depois de terminar de usar o carro.
    std::free(ponteiro);

    return 0;
}