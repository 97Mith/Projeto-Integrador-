#include <stdio.h>
#include <string.h>

int validador_coluna(coluna) {
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
		printf("%d ", ok_letra);
		if(ok_letra == 0){
			coluna = ok_letra;
			tru = 0;
			break;
						}	
	}	
	}while(tru);
	
}
int main(){
	int coluna = 0;
	validador_coluna(coluna);
}
