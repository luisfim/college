#include <iostream>
#include <string>
#include <cstdio>

struct Pessoa{
    char Nome [51];
    int Idade;
    float Altura;

};

int main(){
    Pessoa usuario1;
    std::printf("Qual o nome da pessoa?");
    std::scanf("%50s", usuario1.Nome);
    std::printf("Qual a idade da pessoa?");
    std::scanf("%d", & usuario1.Idade);
    std::printf("Qual a altura da pessoa?");
    std::scanf("%f", & usuario1.Altura);

    std::printf("O nome da pessoa é %s com %d anos e %f de altura", usuario1.Nome, usuario1.Idade, usuario1.Altura);

    return 0;
}