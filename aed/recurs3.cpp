#include <cstdio>

int soma_digitos(int n){
    if(n<10){
        return n;
    }
    else{
        return n % 10 + soma_digitos(n / 10);    
    }
}