#include <stdio.h>
#include <stdlib.h>


ABin newABin (int r, ABin e, ABin d) {
    ABin a = malloc (sizeof(struct nodo));
    if (a!=NULL) {
        a->valor = r; a->esq = e; a->dir = d;
    }
    return a;
}


int altura (ABin a){
    if(a==NULL)
    return 0;

    int e = (1 + altura(a->esq)), d = (1 + altura(a->dir));

    return (e>d)?e:d;
}


int nFolhas (ABin a){
    if(a==NULL)
    return 0;

    if(a->esq==NULL&&a->dir==NULL)
    return 1;

    return (nFolhas(a->esq)+nFolhas(a->dir));
}



ABin maisEsquerda (ABin a){
    if(a!=NULL)
        while(a->esq!=NULL)
            a=a->esq;

    return a;
}


void imprimeNivel (ABin a, int l){
    if(l<=0)
    printf("%d ",a->valor);

    else{
        l--;
        if(a->esq!=NULL)
        imprimeNivel(a->esq,l);

        if(a->dir!=NULL)
        imprimeNivel(a->dir,l);    
    }

}


int procuraE (ABin a, int x){
    
    if(a->valor==x)
    return 1;
    
    int e = 0, d = 0;

    if(a->esq!=NULL)
    e = (procuraE(a->esq,x));

    if(a->dir!=NULL)
    d = (procuraE(a->dir,x));

    return ((e>d)?e:d);
}


struct nodo * procura (ABin a, int x){
    
    if(a==NULL)
    return NULL;

    
    int v = a->valor;

    if(v==x)
    return a;


    if(v<x)
    return procura(a->dir,x);

    if(v>x)
    return procura(a->esq,x);
}


int nivel (ABin a, int x){
    int l = 0, v;

    while(a!=NULL){
        v = a->valor;
        if(v==x)
        return l;


        if(x>v){
            l++;
            a=a->dir;
        }

        if(x<v){
            l++;
            a=a->esq;
        }
    }
    
    return -1;
}


void imprimeAte (ABin a, int x){
    if(a==NULL)
    return;

    imprimeAte(a->esq,x);
    
    if(x > a->valor)
    printf(" %d ",a->valor);

    imprimeAte(a->dir,x);
}
