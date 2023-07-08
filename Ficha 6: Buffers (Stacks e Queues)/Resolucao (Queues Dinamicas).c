#include <stdio.h>
#include <stdlib.h>

typedef struct dinQueue {
    int size; // guarda o tamanho do array values
    int front;
    int length;
    int *values;
} *DQueue;

/*
    Queue com um Fixed-Size Array
    front * *
        |*0*|   |   |   | (length = 1)
        |*0*| 1 | 2 | 3 | (length = 4)
        |*0*| 1 | 2 |   | (length = 3)        
*/


void SinitQueue (DQueue q){
    q->length=0;
    q->size=1;
    q->front=-1;
}

int SisEmptyQ (DQueue q){
    return(q->length==0);
}

int Senqueue (DQueue q, int x){
    
    if((q->length==q->size)){
        int * m = malloc(2*q->size*sizeof(int));

        if(m==NULL)//"Não existe memória disponível"
        return 1;

        for(int i = 0;i<q->size;i++)
        m[i]=q->values[i];

        free(q->values);

        q->values=m;
        q->size*=2;
    }

        q->values[(q->length+q->front)]=x;
        q->length++;
    
    return 0;
}

int Sdequeue (DQueue q, int *x){
    int vazia = (SisEmptyQ(q));
    
    if(!vazia){
        *x=q->values[q->front];
        q->length--;
        
        for(int i = 0; i < q->length;i++)
        q->values[i]=q->values[i+1];
        
    }
    return vazia;
}

int Sfront (DQueue q, int *x){
    int vazia = (SisEmptyQ(q));
    if(!vazia)
    *x=q->values[q->front];

    return vazia;
}

int main(){}
