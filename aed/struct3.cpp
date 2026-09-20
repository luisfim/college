#include <iostream>
#include <string>
#include <cstdio>

struct Produto{
    char Nome [31];
    int Codigo;
    float Preco;

};

void Info(Produto Item){
    std::printf("O produto %s tem o código %d e custa %f", Item.Nome, Item.Codigo, Item.Preco);
}

int main(){
    Produto Item1;
    std::printf("Digite o nome do produto");
    std::scanf("%30s", Item1.Nome);
    std::printf("Qual o código?");
    std::scanf("%d", & Item1.Codigo);
    std::printf("Qual o preço?");
    std::scanf("%f", & Item1.Preco);

    Info(Item1);

    return 0;
}