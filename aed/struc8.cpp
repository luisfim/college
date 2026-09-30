// 8. Area e perimetro de um retangulo.
#include <cstdio>

struct Retangulo {
    float Base;
    float Altura;
};

float CalculoArea(float B, float A) {
    return B * A;
}

float CalculoPerimetro(float B, float A) {
    return 2 * (B + A);
}

int main() {
    Retangulo exemplo;
    std::printf("Base: ");
    if (std::scanf("%f", &exemplo.Base) != 1) return 1;
    std::printf("Altura: ");
    if (std::scanf("%f", &exemplo.Altura) != 1) return 1;
    if (!(exemplo.Base > 0) || !(exemplo.Altura > 0)) {
        std::printf("Base e altura devem ser positivas.\n");
        return 1;
    }
    std::printf("Area: %.2f\n", CalculoArea(exemplo.Base, exemplo.Altura));
    std::printf("Perimetro: %.2f\n", CalculoPerimetro(exemplo.Base, exemplo.Altura));
    return 0;
}
