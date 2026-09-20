#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

struct Funcionario{
    char Nome [51];
    char Cargo [31];
    float Salario;
};

int main(){
    int N;
    std::printf("Quantos funionarios você deseja cadastrar?");
    std::scanf("%d", &N);
    std::vector<Funcionario> Trabalhadores(N);

    for(int i= 0; i<N; i++){
        std::printf("Qual o nome do funcionário?");
        std::scanf("%50s", Trabalhadores[i].Nome);
        std::printf("Qual o cargo?");
        std::scanf("%30s", Trabalhadores[i].Cargo);
        std::printf("Qual o salário?");
        std::scanf("%f", & Trabalhadores[i].Salario);
    }
    for(int i= 0; i<N; i++){
        std::printf("%s", Trabalhadores[i].Nome);
    }


    return 0;
}