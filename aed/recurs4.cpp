#include <cstdio>

int produto(int a, int b){
    if(b==0){
        return 0;
    }
    else{
        return a + produto(a, b-1);    
    }
}