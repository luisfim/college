//Defina uma struct para estruturar dados de alunos de uma escola. Dentro dessa struct, crie uma variavel para
//armazenar o nome do aluno, e outras para armazenar as notas de matemática, física e a média dessas duas notas.
//Após definir a struct, crie três variáveis do tipo struct que você criou. Preencha os nomes e as notas dos alunos,
//calculando automaticamente a média deles.

#include <stdio.h>

typedef struct
{
    char nome[40];
    int notaMat;
    int notaFis;
    float media;
}Aluno;

int main(){
    Aluno A = {"Alice", 10, 10};
    Aluno B = {"Beatris", 5, 0};
    Aluno C = {"Cris", 0, 2};

    A.media = (A.notaMat + A.notaFis) / 2;
    B.media = (B.notaMat + B.notaFis) / 2;
    C.media = (C.notaMat + C.notaFis) / 2;
};