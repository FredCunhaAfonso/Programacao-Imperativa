#include <stdio.h>

int detetorDeVogais(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
    return 1;

    return 0;
}

int tamanhoDaString(char *s){
    int tamanho;
    for(tamanho=0;*(s+tamanho)!='\0';tamanho++);
    return tamanho;
}

void InsereChar(char * s, char c, int local){
    for(int i = tamanhoDaString(s);i>local;i--)
    *(s+i)=*(s+i-1);

    *(s+local)=c;
}



int contaVogais (char *s){
    int vogais=0;
    for(int i = 0; *(s+i)!='\0'; i++)
        if(detetorDeVogais(*(s+i)))
            vogais++;

    return vogais;
}

int retiraVogaisRep (char *s){
    int contaVogaisRep=0;
    for(int i = 0; *(s+i+1)!='\0';i++)
        if(*(s+i+1)==*(s+i))
        if(detetorDeVogais(*(s+i))){
        
            for(int iAux = 0; *(s+i+iAux)!='\0';iAux++)
            *(s+i+iAux)=*(s+i+iAux+1);
    
            contaVogaisRep++;
            i--;
    }

    return contaVogaisRep;
}

int duplicaVogais (char *s){
    int contaVogaisDup=0;
    char c;
    for(int i = 0; *(s+i)!='\0';i++)
        if(detetorDeVogais(*(s+i))){
            c = *(s+i);
            InsereChar(s,c,i);
            
            i++;
            contaVogaisDup++;
        }

    return contaVogaisDup;
}




int main(){
    char s[50]="Esta e uma string com duplicados";
    int x = duplicaVogais(s);

    printf("%d\n%s\n",x,s);
    return 0;
}
