#include <cstdio>

void contagem_regressiva(int a){
    if(a<0){
        return;
    }
    else{
        std::printf("%d", a);
        contagem_regressiva(a-1);    
    }
}