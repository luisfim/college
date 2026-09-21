#include <cstdio>

struct Retangulo {
    float Base;
    float Altura;
};

float CalculoArea(float B, float A) {
    return B * A;
}

float CalculoPerimetro(float B, float A) {
    return 2 * B + 2 * A;
}

int main() {
    Retangulo exemplo;

    std::printf("Digite a base do retangulo: ");
    std::scanf("%f", &exemplo.Base);

    std::printf("Digite a altura do retangulo: ");
    std::scanf("%f", &exemplo.Altura);

    std::printf("Area: %.2f\n",
                CalculoArea(exemplo.Base, exemplo.Altura));

    std::printf("Perimetro: %.2f\n",
                CalculoPerimetro(exemplo.Base, exemplo.Altura));

    return 0;
}