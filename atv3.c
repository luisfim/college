//Crie um programa que leia a venda de 10 produtos (use um vetor). De cada produto queremos saber o nome,
//preço, quantidade de um produto vendido, e mostre também o valor total das vendas. Use structs para estruturar
//os dados.

#include <stdio.h>

typedef struct
{
    char nome[40];
    float preco;
    int qnt;
}Produto;

int main(){
    Produto venda [10];
    int i;
    float total=0;
    for (i=0;i<10;i++){
        printf("Digite o nome do produto");
        scanf("%39", & venda[i].nome);
        printf("Digite o preço do produto");
        scanf("%f", & venda[i].preco);
        printf("Digite a quantidade do produto");
        scanf("%d", & venda[i].qnt);

        total = total + venda[i].preco*venda[i].qnt;

        printf("O total foi %f", total);

    };


};