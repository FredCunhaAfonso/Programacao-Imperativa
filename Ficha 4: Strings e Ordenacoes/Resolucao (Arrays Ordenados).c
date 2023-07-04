#include <stdio.h>

int ordenado (int v[], int N){
    for(int i = 0; i<N-1;i++)
        if(v[i]>v[i+1])
            return 0;

    return 1;
}

void merge (int a[], int na, int b[], int nb, int r[]){

    int nr = na+nb;

    while(na>=0 && nb>=0){
        if(a[na-1]>b[nb-1]){
            r[nr-1]=a[na-1];
            na--;nr--;
            continue;
        }

        else{
            r[nr-1]=b[nb-1];
            nb--;nr--;
            continue;
        }
    }

        if(na==0)
        while(nr>0)
        r[nr-1]=b[nb-1];
        
        while(nr>0)
        if(nb==0)
        r[nr-1]=a[na-1];
}

int partition (int v[], int N, int x){
    int temp,i=0,numerosVistos=0;

    while(numerosVistos<N){
        if(v[i]>x){
            for(int iAux = i; iAux<N-1;iAux++){
                temp = v[iAux];
                v[iAux] = v[iAux+1];
                v[iAux+1] = temp;
            }
            numerosVistos++;
            continue;
        }

        else{
            numerosVistos++;
            i++;
        }
    }

    return i;    
}


int main(){}
