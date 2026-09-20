#include <iostream>
#include <string>
#include <cstdio>

struct Aluno{
    char Nome [51];
    int Matricula;
    float Nota;

};

int main(){
    float media=0;
    Aluno alunos[5];
    for (int i=0; i<5; i++){
        std::printf("Qual o nome do aluno?");
        std::scanf("%50s", alunos[i].Nome);
        std::printf("Qual a matricula?");
        std::scanf("%d", & alunos[i].Matricula);
        std::printf("Qual a nota?");
        std::scanf("%f", & alunos[i].Nota);
        media = media + alunos[i].Nota;
    }

    media = media/5;

    std::printf("O media de notas dos alunos foi %f", media);
    return 0;
}