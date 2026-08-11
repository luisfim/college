// Crie um programa recursivo e outro iterativo que calcule o 
//MDC (máximo divisor comum) de dois números.

#include <string.h>
#include <stdbool.h>

int num1,num2,mdc, test =2;
bool end = true;

while (end){

}

int encontrarMDC (int num1, int num2) {
    if (num1 % test == 0 && num2 % test == 0) {
        mdc = mdc*test;
}
    else if (num1 % test != 0 || num2 % test != 0){
        test=test+1;
}
    else if (num1 % test != 0 && num2 % test != 0){
        end = 1;
}

