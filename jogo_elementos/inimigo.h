#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>


void tiros(){
	char item[1000] = 
"                                                 .   |   .       \n"     
"                                          __      \\  :  /    .L_ \n"
"                _..--._                ____       .    ` ' '    ,\n" 
"           __.i---''''\\___....----''''  ( )'' _ __:.   .:__ _'   \n" 
"     __..-/    006  '________....-----''''          .        `  \n"
"    /     ''---.....___.-'  \\               .---_ /` : '\\     \\\n"
"                                               _='   |   `_    /  \n";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
puts(item);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}
void dano(){

	char item1[500] = 
"        ____   __     _    _    _   \n" 
" ___   (___ \\ /  \\   / \\  / \\  / \\  \n"
"(___)   / __/(  0 )  \\_/  \\_/  \\_/  \n"
"       (____) \\__/   (_)  (_)  (_)  \n";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
puts(item1);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}
void comentario(char mensagem[20]){

puts("___________________________________________________________________________________");
printf("\n");
printf("                - %s \n", mensagem);
puts("___________________________________________________________________________________");
	
}
void randomizador(int* randInt, int numero){
	//inicializa o gerador de números aleatórios com a hora atual como semente
	srand(time(NULL));
	
	//gera um numero aleatório baseado no argumento
	*randInt = rand() % numero;
}

void sargent(char msg[25]){
	printf("       \\\\ ///// \n       |      |        %s\n      (| >  < |)    /\n       |` |  '|    /          \n       | >==< |             \n >>>___/\\_^__/\\___<<<\n/               |||  \\\n", msg);
}
void sargent0(char msg[25]){
	printf("       \\\\ ///// \n       |      |        %s\n      (| -  - |)    /\n       |` |  '|    /          \n       |  o<  |             \n >>>___/\\_^__/\\___<<<\n/               |||  \\\n", msg);
}
void hit(void){ 
char item[450]=
//                                                        |   |
"       ____  ___       \n"
"  ___ |___ ||   |                                        \\==/           ___|_\n"
" |___| /  / | | |                                         ||          _|     |_____    \n"
"      |____||___|                                         \\/         \\_____(_)_____/\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	puts(item);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}
void nohit(void){ 
char item[350]=

"      / \\/ \\         \n"
"      \\    /                                            \\==/           ___|_\n"
"       \\  /                                              ||          _|     |_____    \n"
"        \\/                                               \\/         \\_____(_)_____/\n";
	puts(item);
}
void enemy(int* HP){
	int i,j;
	int tabuleiro[6][6] = {{0,0,0,0,0,0}, 
						   {0,0,0,0,0,0},
					   	   {0,0,0,0,0,0},
						   {0,0,0,0,0,0},
						   {0,0,0,0,0,0},
						   {0,0,0,0,0,0},
						   };
	int r, r2;
	randomizador(&r, 100);
	if (r < 31){
		puts("_____________________________________________________________________________________");
		nohit();
		puts("_____________________________________________________________________________________");
		for(i=0; i<6; i++){
			printf("        \t%d", 6 - i);
			
			for(j=0; j<6; j++){
				printf("\t.....");
			}
		printf("\n\n\n");	
		}
		printf("        \t\tA\tB\tC\tD\tE\tF\n\n\n\n");
	comentario("Capitão, o inimigo está atirando contra nós!");
	printf("\n\n\n\n\n");
	tiros();
	
	randomizador(&r2, 150);
		
	system("pause");
		if(r2 < 42){
			system("cls");
			puts("_____________________________________________________________________________________");
			hit();
			puts("_____________________________________________________________________________________");
			for(i=0; i<6; i++){
			printf("        \t%d", 6 - i);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			for(j=0; j<6; j++){
				printf("\t.....");
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		printf("\n\n\n");	
		}
			printf("\n\n\n");
			printf("        \t\tA\tB\tC\tD\tE\tF\n\n\n\n");
			*HP -= 20;
			puts("_____________________________________________________________________________________");
			printf("\n");
			sargent("Droga, FOMOS ATINGIDOS!");
			printf("\n\n\n");
			system("pause");
			system("cls");
		//	printf("\nPontos de vida: %d\n", HP);
		}
		
		else{
			system("cls");
		puts("_____________________________________________________________________________________");
		nohit();
		puts("_____________________________________________________________________________________");
		for(i=0; i<6; i++){
			printf("        \t%d", 6 - i);
			
			for(j=0; j<6; j++){
				printf("\t.....");
			}
		printf("\n\n\n");	
		}
		printf("        \t\tA\tB\tC\tD\tE\tF\n\n\n\n");
		puts("_____________________________________________________________________________________");
		printf("\n");
		sargent0("O inimigo errou, ufa...");
		printf("\n\n\n");
		system("pause");
	system("cls");
		}
			
	}
	if(HP <=0){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		comentario("MEU DEUS! A embarcação quebrou, fomos destruídos, senhor");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		system("pause");
		
	}
}


