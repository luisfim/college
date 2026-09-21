#include <cstdio>

struct No{
    int dado;
    No *ptr;
};

int main(){

    //Criando três nos
    No*node1 = new No;
    No*node2 = new No;
    No*node3 = new No;

    //definindo os dados
    node1->dado=10;
    node2->dado=20;
    node3->dado=30;

    //conectando os nós
    node1->ptr=node2;
    node2->ptr=node3;
    node3->ptr=nullptr;

    return 0;
};