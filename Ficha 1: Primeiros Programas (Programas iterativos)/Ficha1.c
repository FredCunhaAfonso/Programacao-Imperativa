#include <stdio.h>

//3.Programas iterativos
void quadrado(int dimensao){
    int l,altura=dimensao;

    do{
        l=dimensao;
        do{
            printf("#");
            l--;
        }while(l>0);
        
        printf("\n");
        altura--;

    }while(altura>0);
}


void xadrez(int dimensao){
    int l,altura=dimensao;

    do{
        l=dimensao;
        do{
            if((l+altura)%2==0)
            printf("#");
            else
            printf("_");

            l--;
        }while(l>0);
        
        printf("\n");
        altura--;

    }while(altura>0);
}


void trianguloVertical(int alturaDesejada){
    int alturaAtual,NivelAtual = 0;
    
    do{
        alturaAtual=NivelAtual;
        do{
            alturaAtual--;
            printf("#");
        }while(alturaAtual>=0);
        
        NivelAtual++;
        printf("\n");
    
    }while(NivelAtual!=alturaDesejada);

    alturaDesejada--;

    do{
        alturaAtual=alturaDesejada;
        do{
            alturaAtual--;
            printf("#");
        }while(alturaAtual>0);
        
        alturaDesejada--;
        printf("\n");
    
    }while(alturaDesejada>0);

}


//De modo a ser mais conciso, usarei mais "for loops" futuramente :)

void trianguloHorizontal(int alturaDesejada){
    for(int nivel = 0; nivel< alturaDesejada ;nivel++){
        for(int espacos = 0;espacos< alturaDesejada-nivel-1;espacos++){printf(" ");}
        for(int preenchidos = 0; preenchidos<(nivel*2)+1;preenchidos++){printf("#");}
        for(int espacos = 0;espacos< alturaDesejada-nivel;espacos++){printf(" ");}
        printf("\n");
    }
}


void circulo(int raio){
    int dimensaoDaMatriz=1+raio*2,matriz[dimensaoDaMatriz][dimensaoDaMatriz];
    
    for(int y = (dimensaoDaMatriz/2)*(-1); y<=dimensaoDaMatriz/2;y++){
    for(int x = (dimensaoDaMatriz/2)*(-1); x<=dimensaoDaMatriz/2;x++){
        if(x*x+y*y<=raio*raio){printf("#");}
        else{printf(" ");}
    }        
    printf("\n");
    }
}

int main(){}