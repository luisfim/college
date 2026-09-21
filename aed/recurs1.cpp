#include <cstdio>

int contar_digitos(int n){
    if (n<10){
        return 1;
    }
    else{
        return (1+ contar_digitos(n/10));
    }
}