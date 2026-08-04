//Crie um programa que leia e apresente os dados de 3 funcionários. Crie uma struct que contenha o nome, idade,
//salário e a data de nascimento. O que se sabe é que a data de nascimento é do tipo Data, ou seja, uma outra struct
//que contem os seguintes membros: dia e ano, ambos do tipo inteiro; e mês do tipo string. Crie um vetor de struct
//para registrar os dados dos 3 funcionários.

#include <stdio.h>

typedef struct
{
    int dia;
    int ano;
    char mes[10];
}Data;

typedef struct
{
    char nome[40];
    int idade;
    float salario;
    Data nascimento;
}Func;

Func funcionarios [3];
