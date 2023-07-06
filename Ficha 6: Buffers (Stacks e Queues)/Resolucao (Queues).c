#include <stdio.h>



#define Max 10

typedef struct staticQueue{
    int front;
    int length;
    int values [Max];
} QUEUE;

typedef struct staticQueue *SQueue;

/*
    Queue com um Dynamic-Sized Array
    front * *
    * * |   |   |   |   |   | (length = 0)
        |*0*|   |   |   |   | (length = 1)
        |   |*1*| 2 |   |   | (length = 2)
        | 0 |   |   |*3*| 4 | (length = 3)
        | 0 | 1 | 2 |   |*4*| (length = 4)
        | 0 | 1 | 2 | 3 |*4*| (length = 5)
*/


void SinitQueue (SQueue q){
    q->length=0;
    q->front=-1;
}

int SisEmptyQ (SQueue q){
    return(q->length==0);
}

int Senqueue (SQueue q, int x){
    int cheia = (q->length==Max);
    if(!cheia){
        q->values[(q->length+q->front)%Max]=x;
        q->length++;
    }
    return cheia;
}

int Sdequeue (SQueue q, int *x){
    int vazia = (SisEmptyQ(q));
    if(!vazia){
        *x=q->values[q->front];
        q->front++;
        q->length--;
    }
    return vazia;
}

int Sfront (SQueue q, int *x){
    int vazia = (SisEmptyQ(q));
    if(!vazia)
    *x=q->values[q->front];

    return vazia;
}

int main(){}
