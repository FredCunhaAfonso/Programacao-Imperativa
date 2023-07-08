#include <stdio.h>
#include <stdlib.h>

typedef struct dinStack {
    int size; // guarda o tamanho do array values
    int sp;
    int *values;
} *DStack;


void SinitStack(DStack s){
    s->sp = 0;
    s->size = 1;
}

int SisEmpty (DStack s){
    return(s->sp==0);
}

int Spush (DStack s, int x){
    
    if(s->sp==s->size){
        int *m = malloc(2*s->size*sizeof(int));
        
        if(m==NULL)//"Não existe memória disponível"
        return 1;
        
        for(int i = 0; i<s->size;i++)
        m[i]=s->values[i];

        free(s->values);
        s->values=m;
        s->size*=2;
    }

    s->values[s->sp]=x;
    s->sp++;
    return 0;
}

int Spop (DStack s, int *x){
    if(!SisEmpty(s)){
    s->sp--;
    s->size--;
    *x=s->values[s->sp];
    }

    return(SisEmpty(s));
}

int Stop (DStack s, int *x){
    if(!SisEmpty(s))
    *x=s->values[s->sp-1];

    return(SisEmpty(s));
}

int main(){}