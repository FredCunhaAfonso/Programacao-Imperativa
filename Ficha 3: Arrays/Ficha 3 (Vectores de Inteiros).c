#include "../Headers/Ficha 3 (Vectores de Inteiros).h"

#include <stdio.h>


void swapM (int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


void swap (int v[], int i, int j){
    int temp = v[i];
    v[i]=v[j];
    v[j]=temp;
}


int soma (int v[], int N){
    int somatorio = 0;

    for(int i = 0;i<N;i++)
    somatorio+=v[i];

    return somatorio;
}


void inverteArray (int v[], int N){

    for(int i = 0; i<N/2;i++)
    	swapM(&v[i],&v[N-i-1]);
    	//swap(v,i,N-i-1);

}


int maximum (int v[], int N, int *m){
    if(!N>0)
    return 1;

    *m=v[0];
    for(int i = 0; i<N;i++)
        if(v[i]>*m)
            *m=v[i];
    
    return 0;
}


void quadrados (int q[], int N){
    q[0]=0;

    for(int i = 1; i<N; i++)
    q[i]=q[i-1]+(2*(i-1)+1);
    //ou "q[i]=i*i;" ...
}


/*
1
1  1
1  2  1
1  3  3  1
1  4  6  4  1
1  5  10 10 5  1
*/

void pascal (int v[], int N){
    v[0]=1;

    for(int numeroDaLinha=1;numeroDaLinha<N;numeroDaLinha++){
        v[numeroDaLinha]=1;

        for(int i = numeroDaLinha-1; i > 0; i--)
        v[i]+= v[i-1];
    }
}


void TrianguloDePascal(int v[], int N){
    for(int linha = 1; linha<N;linha++){
        pascal(v,linha);

        for(int i = 0; i<linha;i++)
        printf("%d ",v[i]);

        printf("\n");
    }
}
