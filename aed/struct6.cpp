#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

struct Livro{
    char Titulo [51];
    char Autor [51];
    int Ano;
};

void Pesquisar(Livro Vetor[],int Inicio){
    for(int i=0; i<3; i++){
        if(Vetor[i].Ano>=Inicio){
            std::printf("%s",Vetor[i].Titulo);
        }
    }
};

int main(){
    Livro Obras[3];
    int AnoInicial;

    for(int i=0; i<3; i++){
        std::printf("Qual o titulo?");
        std::scanf("%50s", Obras[i].Titulo);
        std::printf("Qual o autor?");
        std::scanf("%50s", & Obras[i].Autor);
        std::printf("Qual o ano de publicação?");
        std::scanf("%d", & Obras[i].Ano);
    };

    std::printf("Você deseja livros a partir de qual ano?");
    std::scanf("%d", &AnoInicial);

    Pesquisar(Obras,AnoInicial);


    return 0;
};