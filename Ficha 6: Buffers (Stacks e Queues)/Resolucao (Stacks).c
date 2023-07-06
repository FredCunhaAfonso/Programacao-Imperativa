#include <stdio.h>



#define Max 10

/*
    Alguns problemas ao compilar levaram a uma
    pequena alteração à definição do struct
*/

struct staticStack{
    int sp;
    int values [Max];
} STACK;

typedef struct staticStack *SStack;


void SinitStack(SStack s){
    s->sp=0;
    /*
    como o StackPointer aponta para a próxima
    localização  da "stack" (array neste caso), 
    ao dizer que toma o valor de 0, estamos a
    afirmar que a próxima localização da stack
    é a primeira posição, não havendo elementos 
    anteriores
    */
}

int SisEmpty (SStack s){
    return(s->sp==0);
}

int Spush (SStack s, int x){
    if(s->sp==Max)
    return 0;

    s->values[s->sp]=x;
    s->sp++;
    return 0;
}

int Spop (SStack s, int *x){
    if(!SisEmpty(s)){
    s->sp--;
    *x=s->values[s->sp];
    }

    return(SisEmpty(s));
}

int Stop (SStack s, int *x){
    if(!SisEmpty(s))
    *x=s->values[s->sp-1];

    return(SisEmpty(s));
}

int main(){}