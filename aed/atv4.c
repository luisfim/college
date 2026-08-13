// Crie um programa recursivo e outro iterativo que calcule o 
//MDC (máximo divisor comum) de dois números.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int mdc1= 1, mdc2=1, test1=2, test2=2;

void encontrarMDC1 (int num1, int num2) { //função iterativa

    while (true){

        if (test1 > num1 || test1 > num2){
            return;
        }

        if (num1 % test1 == 0 && num2 % test1 == 0) {
            mdc1 = mdc1*test1;
            num1 = num1/test1;
            num2 = num2/test1;
    }
        else{
            test1=test1+1;
        }
    }
}

void encontrarMDC2 (int num3, int num4) { //função recursiva

        if (test2 > num3 || test2 > num4){ //Caso de parada
            return;
    }

        if (num3 % test2 != 0 || num4 % test2 != 0){
            test2=test2+1;
            encontrarMDC2 (num3, num4);

    }
        else{
            mdc2 = mdc2*test2;
            encontrarMDC2 (num3/test2, num4/test2);
    }

}

int main(){

    int dig1, dig2, dig3, dig4;

    printf("Vamos testar a função iterativa\n");
    printf("Digite um número\n");
    scanf("%d", & dig1);
    printf("Digite outro número\n");
    scanf("%d", & dig2);

    encontrarMDC1 (dig1, dig2);
    
    printf ("Mdc: %d \n", mdc1);


    printf("Vamos testar a função recursiva\n");

    printf("Digite um número\n");
    scanf("%d", & dig3);
    printf("Digite outro número\n");
    scanf("%d", & dig4);

    encontrarMDC2 (dig3, dig4);
    
    printf ("Mdc: %d \n", mdc2);


    return 0;
}


