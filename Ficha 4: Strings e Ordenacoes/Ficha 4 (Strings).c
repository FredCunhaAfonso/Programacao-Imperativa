#include "../Headers/Ficha 4 (Strings).h"

#include <stdio.h>
#include <string.h>

int detetorDeVogais(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
    return 1;

    return 0;
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
    int contaVogaisDup=0, l = strlen(s);
    for(int i = 0; i<strlen(s);i++)
        if(detetorDeVogais(*(s+i))){
	    for(int aux = strlen(s); aux!=i;aux--)
	    *(s+aux)=*(s+aux-1);
            
            i++;
            contaVogaisDup++;
        }
        
        *(s+l+contaVogaisDup)='\0';        
        

    return contaVogaisDup;
}
