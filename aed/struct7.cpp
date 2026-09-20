#include <iostream>
#include <string>
#include <cstdio>

struct Agenda{
    char Nome [51];
    char Telefone [15];

};

int main(){
    Agenda Listinha[100];
    int Resp, Contador=1;
    std::printf("Para adicionar um contato digite 1 e para buscar um contato digite 2");
    std::scanf("%d", Resp);
    if(Resp==1){
        std::printf("Qual o nome da pessoa?");
        std::scanf("%50s", Listinha[Contador].Nome);
        std::printf("Qual o numero da pessoa?");
        std::scanf("%50s", & Listinha[Contador].Telefone);
        Contador=Contador+1;
    }
    else{
        std::printf("Qual o nome da pessoa?");

    }
    return 0;
}