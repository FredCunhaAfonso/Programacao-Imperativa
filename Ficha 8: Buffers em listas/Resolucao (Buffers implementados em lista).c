#include <stdio.h>
#include <stdlib.h>


typedef struct slist {
    int valor;
    struct slist * prox;
} * LInt;

typedef LInt Stack;


void initStack (Stack *s){
    *s=NULL;
}


int SisEmpty (Stack s){
    return(s==NULL);
}


int push (Stack *s, int x){
    Stack t = malloc(sizeof(Stack));
    if(t==NULL)
    return 1;

    t->valor=x;
    t->prox=*s;

    *s = t;

    return 0;
}


int pop (Stack *s, int *x){

    if(s==NULL)
    return 1;

    *x = (*s)->valor;

    Stack t = (*s)->prox;
    free(s);
    *s=t;
    
    return 0;
}


int top (Stack s, int *x){
    if(s!=NULL)
    *x = s->valor;

    return(s==NULL);
}




typedef struct {
    LInt inicio,fim;
} Queue;


void initQueue (Queue *q){
    q->inicio=NULL;
    q->fim=NULL;
}


int QisEmpty (Queue q){
    return(q.inicio==q.fim && q.inicio == NULL);
}


int enqueue (Queue *q, int x){
    
    Queue *aux = q;
    LInt t = malloc(sizeof(LInt));
    if(t!=NULL){
        t->valor=x;
        t->prox=NULL;

        (q->fim)->prox=t;
        q->fim=(q->fim)->prox;

        if(q->inicio==NULL)
        q->inicio = q->fim;
    }

    return(t==NULL);
}


int dequeue (Queue *q, int *x){
    if(!QisEmpty(*q)){
        *x=(q->inicio)->valor;
        
        if(q->inicio==q->fim){
            q->inicio=NULL;
            q->fim=NULL;
        }
        
        else{
            LInt t = q->inicio;
            free(q->inicio);
            q->inicio=t->prox;
        }

    }

    return(QisEmpty(*q));
}


int front (Queue q, int *x){
    *x=(q.inicio)->valor;
    return *x;
}



typedef struct dlist {
    int valor;
    struct dlist *ant, *prox;
} *DList;

typedef struct {
    DList front, back;
} Deque;



void initDeque (Deque *q){
    q->back=NULL;
    q->front=NULL;
}


int DisEmpty (Deque q){
    return (q.back == NULL && q.front == NULL);    
}


int pushBack (Deque *q, int x){
    DList t = malloc(sizeof(struct dlist));
    if(t!=NULL){
        t->valor = x;
        t->prox = NULL;

        if(DisEmpty(*q)){
            t->ant=NULL;

            q->front=t;
            q->back=t;
        }

        else{
            t->ant = q->back;
            q->back->prox = t;
            q->back=t;
        }

    }
    return(t==NULL);
}


int pushFront (Deque *q, int x){
    DList t = malloc(sizeof(struct dlist));
    if(t!=NULL){
        t->valor = x;
        t->ant = NULL;

        if(DisEmpty(*q)){
            t->prox=NULL;

            q->front=t;
            q->back=t;
        }

        else{
            t->prox = q->front;
            q->front->ant = t;
            q->front=t;
        }

    }
    return(t==NULL);
}


int popBack (Deque *q, int *x){
    if(!DisEmpty(*q)){

        *x = q->back->valor;
        DList t = q->back;

        (q->back)=(q->back)->ant;
        (q->back)->prox=NULL;
        free(t);
        
    }
    return(DisEmpty(*q));
}


int popFront (Deque *q, int *x){
    if(!DisEmpty(*q)){

        *x = q->front->valor;
        DList t = q->front;

        (q->front)=(q->front)->prox;
        (q->front)->ant=NULL;
        free(t);
        
    }
    return(DisEmpty(*q));
}


int popMax (Deque *q, int *x){
    DList t = q->front;
    DList max = t;
    if(q!=NULL){

    while(t!=NULL){
        if(t->valor>max->valor)
            max = t;

        t = t->prox;    
    }

    *x = max->valor;
    t=max;
    (t->ant->prox)=t->prox;
    free(max);
    }
    return (q==NULL);
}


int main(){}