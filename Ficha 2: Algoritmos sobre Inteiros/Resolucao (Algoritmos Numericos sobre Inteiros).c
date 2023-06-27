#include <stdio.h>


float multInt1 (int n, float m){
    float r = 0;

    for(int i = 0; i<n;i++){r+=m;}
    
    return r;
}


float multInt2 (int n, float m){
    float r = 0;
    
    while(n>0){
        if(n%2)
        r+=m;

        m*=2;
        n/=2;
    }

    return r;
}


int mdc1 (int a, int b){
    int menorInicial, maiorInicial;
    
    (a>b)?(menorInicial=b,maiorInicial=a):(menorInicial=a,maiorInicial=b);

    for(int r = menorInicial;r>1;r--){
        
        if(menorInicial%r==0)
        if(maiorInicial%r==0){return r;}
        
    }
}


int mdc2 (int a, int b){
    int menorInicial, maiorInicial;
    
    (a>b)?(menorInicial=b,maiorInicial=a):(menorInicial=a,maiorInicial=b);

    while(maiorInicial!=menorInicial){

        if(maiorInicial>menorInicial)
        maiorInicial-=menorInicial;

        if(maiorInicial<menorInicial)
        menorInicial-=maiorInicial;

    }
    
    return maiorInicial;
}


int mdc3 (int a, int b){
    int menorInicial, maiorInicial;
    
    (a>b)?(menorInicial=b,maiorInicial=a):(menorInicial=a,maiorInicial=b);

    while(maiorInicial!=menorInicial){

        if(maiorInicial>menorInicial)
        maiorInicial%=menorInicial;

        if(maiorInicial<menorInicial)
        menorInicial%=maiorInicial;

    }
    
    return maiorInicial;
}


int fib1 (int n){
    if(n==0)
    return 0;

    if(n==1)
    return 1;

    else
    return fib1(n-2) + fib1(n-1);
}


int fib2 (int n){
    if(n==0)
    return 0;

    if(n==1)
    return 1;
    
    int aux1, aux2,temp;

    aux1=0;
    aux2=1;

    while(n>1){
        aux2 += aux1;
        aux1 = aux2-aux1;        
        n--;
    }

    return aux2;

}


int main(){}