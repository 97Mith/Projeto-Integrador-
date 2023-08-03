#include <stdio.h>
#include <string.h>

int validador_coluna(int* coluna) {
    int i;
    int tru = 1;
    int ok_letra;
    
    char input[1];
    const char *letra[8];
    
    
    //variavel lista com as letras do alfabeto
	letra[0] = "a"; letra[1] = "b"; letra[2] = "c"; letra[3] = "d"; letra[4] = "e"; letra[5] = "f"; letra[6]= "g"; letra[7] = "h";
	
	
    
	
	do{
		
	printf("\nEscolha a coluna: ");
    scanf("%s", input);
    fflush(stdin);
		
		
	for(i=0; i<8; i++){
		ok_letra = 0;
		ok_letra = strcmp(input, letra[i]);
		
		if(ok_letra == 0){
			*coluna = i;
			tru = 0;
			
			break;
						}	
	}	
	}while(tru);
	
}

int validador_linha(int* linha) {
    int i;
    int tru = 1;
    int ok_letra;
    
    char input[1];
    const char *letra[8];
    
    
    //vetor com numeros das linhas
	letra[0] = "1"; letra[1] = "2"; letra[2] = "3"; letra[3] = "4"; letra[4] = "5"; letra[5] = "6"; letra[6]= "7"; letra[7] = "8";
	
	
    
	
	do{
		
	printf("\nEscolha a linha: ");
    scanf("%s", input);
    fflush(stdin);
		
		
	for(i=0; i<8; i++){
		ok_letra = 0;
		ok_letra = strcmp(input, letra[i]);
		
		if(ok_letra == 0){
			*linha = i;
			tru = 0;
			break;
						}	
	}	
	}while(tru);
	
}
int main(){
	int coluna, linha;
	validador_coluna(&coluna);
	validador_linha(&linha);
	printf("%d   %d", coluna, linha);
}

