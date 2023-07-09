#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;



void libertaLista (Palavras l){
    Palavras t;

    while(l!=NULL){
        t = l->prox;

        free(l->palavra);
        free(l);
        
        l = t;
    }
}

int quantasP (Palavras l){
    int pUnicas = 0;
    Palavras t = l;

    while(t!=NULL){
        if(t->ocorr==1)
        pUnicas++;

        t=t->prox;
    }

    return pUnicas;
}


void listaPal (Palavras l){
    Palavras t = l;

    while(t!=NULL){
        printf("\"%s\" Numero de Ocorrencias:%d\n",t->palavra,t->ocorr);
        t=t->prox;
    }
}


char * ultima (Palavras l){

    Palavras t = l;
    
    while(t!=NULL){
        if(t->prox==NULL)
        return t->palavra;

        t=t->prox;
    }

    return NULL;
}


Palavras acrescentaInicio (Palavras l, char *p){
    
    Palavras t=malloc(sizeof(Palavras));
    t->palavra=p;
    t->ocorr=1;
    t->prox=l;

    return t;
}


Palavras acrescentaFim (Palavras l, char *p){
    Palavras t=malloc(sizeof(Palavras)),aux=l;
    t->palavra=p;
    t->ocorr=1;
    t->prox=NULL;

    if(l==NULL)
    return t;

    while(aux->prox!=NULL)
    aux=aux->prox;

    aux->prox=t;

    return l;
}


Palavras acrescenta (Palavras l, char *p){
    Palavras t=l;
    while(t!=NULL){
    
        if(strcmp(t->palavra,p)==0){
            t->ocorr++;
            break;
        }

        t=t->prox;

        if(t!=NULL){
            if(strcasecmp(p,t->palavra)<0)
            acrescentaInicio(t,p);
        }

        else
            acrescentaFim(l,p);
    }
    
    return l;
}


struct celula * maisFreq (Palavras l){
    Palavras max = l;
    
    if(l!=NULL){
        Palavras t = l;
        while(t!=NULL){
            if(t->ocorr>max->ocorr)
            max=t;

            t=t->prox;
        }
    }

    return max;
}


int main(){}