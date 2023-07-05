#include <stdio.h>
#include <string.h>
typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

    /*
    6 minitestes, cada um com
    uma cotação máxima de 2,
    um peso total de 20% no 
    resultado final e de nota 
    mínima 25%
    */

int nota (Aluno a){
    float resultado = 0, miniTestes=0;

    for(int i = 0; i<6; i++)
    miniTestes += a.miniT[i];

    miniTestes /= 12;
    miniTestes *= 20;

    if(miniTestes<5)
    return 0;

    resultado += (0.8*a.teste) + (0.2*miniTestes);
    return resultado;
}


int procuraNum (int num, Aluno t[], int N){
    for(int i = 0; i<N; i++)
        if(t[i].numero==num)
            return i;

    return -1;
}


void ordenaPorNum (Aluno t [], int N){
    Aluno dIntercambio;

    for(int i = 0; i<N-1; i++)
    for(int iAux = i; iAux<N;iAux++)
        if(t[i].numero>t[iAux].numero){
            dIntercambio = t[i];
            t[i] = t[iAux];
            t[iAux] = dIntercambio;
        }
}

void criaIndPorNum (Aluno t[], int N, int ind[]){
    for(int i = 0; i<N; i++)
    ind[i]=i;

    int temp;
    Aluno dIntercambio;

    for(int i = 0; i<N-1; i++)
    for(int iAux = i; iAux<N;iAux++)
        if(t[i].nome<t[iAux].nome){
            dIntercambio = t[i];
            t[i] = t[iAux];
            t[iAux] = dIntercambio;

            temp=ind[i];
            ind[i]=ind[iAux];
            ind[iAux]=temp;
        }
}

void imprimeTurma (int ind[], Aluno t[], int N){
    criaIndPorNum(t,N,ind);
    printf("Numero Nome    Mini-Testes   Teste|Nota Final\n----------------------------------|----------\n");
    for(int i = 0; i<N;i++)
    printf("{%4d, %s, {%d,%d,%d,%d,%d,%d}, %4.1f}|%6d\n",t[i].numero,t[i].nome,t[i].miniT[0],t[i].miniT[1],t[i].miniT[2],t[i].miniT[3],t[i].miniT[4],t[i].miniT[5],t[i].teste,nota(t[i]));
}

int procuraNum2 (int num, int N, int ind[], Aluno t[]){
    for(int i = 0;i<N;i++)
    if(t[ind[i]].numero==num)
    return ind[i];

    return -1;
}

void criaIndPorNome(Aluno t[], int N, int ind[]){

    for(int i = 0; i<N; i++)
    ind[i]=i;

    int temp;
    Aluno dIntercambio;

    for(int i = 0; i<N-1; i++)
    for(int iAux = i; iAux<N;iAux++)
        if(!strcmp(t[i].nome,t[iAux].nome)){
            dIntercambio = t[i];
            t[i] = t[iAux];
            t[iAux] = dIntercambio;

            temp=ind[i];
            ind[i]=ind[iAux];
            ind[iAux]=temp;
        }
}


int main(){

    Aluno t[4]= {{4444, "Andre", {2,1,0,2,2,2}, 10.5},{2222, "Joana", {2,2,2,1,0,0}, 14.5},{7777, "Maria", {2,2,2,2,2,1}, 18.5},{3333, "Paulo", {0,0,2,2,2,1}, 8.7}};
    int r[4];

    criaIndPorNome(t,4,r);
    imprimeTurma(r,t,4);

    printf("%d %d %d %d\n",r[0],r[1],r[2],r[3]);


    return 0;
}
