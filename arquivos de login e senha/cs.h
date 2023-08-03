#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define tamanho 70
// Estrutura para armazenar a pontuação e o nome
int i, j;

int len = 0;
typedef struct {
    int pontuacao;
    char nome[tamanho];
} Dado;

// Função de comparação para ordenar os dados
int compararDados(const void* a, const void* b) {
    const Dado* dadoA = (const Dado*)a;
    const Dado* dadoB = (const Dado*)b;

    return dadoB->pontuacao - dadoA->pontuacao;
}
void titulo_(void){
	char item[500] = " ___           _           _    _                _   _                       _   \n"
"(  _`\\        ( )_        (_ ) ( )              ( ) ( )                     (_ ) \n"
"| (_) )   _ _ | ,_)   _ _  | | | |__     _ _    | `\\| |   _ _  _   _    _ _  | | \n"
"|  _ <' /'_` )| |   /'_` ) | | |  _ `\\ /'_` )   | , ` | /'_` )( ) ( ) /'_` ) | | \n"
"| (_) )( (_| || |_ ( (_| | | | | | | |( (_| |   | |`\\ |( (_| || \\_/ |( (_| | | | \n"
"(____/'`\\__,_)`\\__)`\\__,_)(___)(_) (_)`\\__,_)   (_) (_)`\\__,_)`\\___/'`\\__,_)(___)\n\n";
puts(item);
}
void cadast(void){
	char item[300] = 
	"\t\t / ___|  / \\  |  _ \\  / \\  / ___|_   _|  _ \\ / _ \\ \n"
"\t\t| |     / _ \\ | | | |/ _ \\ \\___ \\ | | | |_) | | | |\n"
"\t\t| |___ / ___ \\| |_| / ___ \\ ___) || | |  _ <| |_| |\n"
"\t\t \\____/_/   \\_|____/_/   \\_|____/ |_| |_| \\_\\\\___/\n"; 
 puts(item);
}
char logn(void){
	char item[200] = 
	"\t\t\t| |   / _ \\ / ___|_ _| \\ | |\n"
"\t\t\t| |  | | | | |  _ | ||  \\| |\n"
"\t\t\t| |__| |_| | |_| || || |\\  |\n"
"\t\t\t|_____\\___/ \\____|___|_| \\_|\n";
 puts(item);
}
void l(void){
	
	puts("_____________________________________________________________________________________\n");
}
void cadastro(){
	FILE *arquivo;
	FILE *pontos;
	char cab[20] = "usu senha";
	char usuario[12];
	char dado[12]; //variavel buffer para armazenar cada linha lida no arquivo
	char senha[12];
	char senha_confirma[12];
	int validar = 0;
	int ok; //para comparar se a senha e a senha confirmada são iguais
	int duplicado = 0;
	int palavra = 0; //tamanho da palavra para fazer a verificação
	int tru = 1;
	
		l();
		titulo_();
		l();
		printf("\n\n\n\n");
		cadast();
		printf("\n\n\n\n");
		l();
		if (arquivo == NULL){
			arquivo = fopen("cadastros.txt", "w");
			fprintf(arquivo, "%s\n", cab);
			fclose(arquivo);
		}
		arquivo = fopen("cadastros.txt", "a");
		
		l();
		puts("\t\t\tEscolha seu nome de guerra: ");
		l();
		scanf("%s", usuario);
		
		//fprintf(arquivo, "%s ", usuario);
		
		fclose(arquivo);
	

	//verifica se o usuário digitado já existe no arquivo
		arquivo = fopen("cadastros.txt", "r");
		
		palavra = strlen(usuario) + 1;
		
			 while (fgets(dado, palavra, arquivo) != NULL){
			 	
			 	
			 	validar = strcmp(dado, usuario);
			 	
			 	if(validar == 0){
			 		l();
			 		puts("\t\t\tUsuário já existe, escolha outro nome...");
			 		l();
			 		system("pause");
			 		break;
				 }
				 fflush(stdin);	 
			 }
			 
		if(validar != 0){
			arquivo = fopen("cadastros.txt", "a");
		fprintf(arquivo, "%s ", usuario);
		
		
			//criando a senha com confirmação
	do{
		system("cls");
		l();
		titulo_();
		l();
		cadast();
		l();
		l();
		puts("\t\t\tDigite sua senha: ");
		l();
		
	scanf("%s", senha);
	l();
	puts("\t\t\tConfirme a senha: ");
	l();
	scanf("%s", senha_confirma);
	
	ok = strcmp(senha, senha_confirma);
	if(ok == 0){
		fprintf(arquivo, "%s\n", senha);
		pontos = fopen("pontuacao.txt", "a");
		fprintf(pontos, "0 %s\n", usuario);
		tru = 0;
	}
	else{
		printf("\n\n\n\n\n\n");
		l();
		puts("\t\t\tAs senhas diferem...");
		l();
	}
	}while(tru);
	
	
	//usando fclose para ferchar o arquivo
	fclose(arquivo);
	fclose(pontos);
	system("cls");
	printf("\n\n\n\n\n\n");
	l();
	puts("\t\t\t\tDados gravados com sucesso!");
	l();
	system("pause");
	}
		
		}
int login(char nome[50], int* variavel_para_entrar) {
	system("cls");

    
    char senha[50];
    char linha[50];
    int encontrado = 0;
	l();
	titulo_();
	l();
	printf("\n\n\n\n");
	logn();
	printf("\n\n\n\n");
	l();
    printf("Digite seu nome de usuário: ");
    scanf("%s", nome);

    printf("Digite sua senha: ");
    scanf("%s", senha);

    FILE* arquivo = fopen("cadastros.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while (fgets(linha, 50, arquivo) != NULL) {
        // Separa o nome de usuário e a senha da linha lida do arquivo
        char* usuario = strtok(linha, " ");
        char* senha_arquivo = strtok(NULL, "\n");

        // Remove o caractere de nova linha da senha lida do arquivo
        senha_arquivo[strcspn(senha_arquivo, "\n")] = 0;

        // Compara o nome de usuário e a senha do arquivo com a entrada do usuário
        if (strcmp(usuario, nome) == 0 && strcmp(senha_arquivo, senha) == 0) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
    	*variavel_para_entrar = 1;
    	system("cls");
        printf("\n\n\n\n\n\t\t\t\t\t\tBem - vindo à bordo!!!!!.\n\n\n\n\n\n");
        
    } 
	else {
		*variavel_para_entrar = 0;
        printf("Nome de usuário ou senha incorretos.\n");
    }

    //fclose(arquivo);
	system("pause");
    return 0;
}

void ranking(){


// Abrir o arquivo TXT
    FILE* arquivo = fopen("pontuacao.txt", "r");
    
    // Variáveis para armazenar os dados
    Dado dados[tamanho];
    char linha[tamanho];
    int numDados = 0;

    // Ler o conteúdo do arquivo e processar os dados
    while (fgets(linha, tamanho, arquivo) != NULL) {
        sscanf(linha, "%d %s", &dados[numDados].pontuacao, dados[numDados].nome);
        numDados++;
    }

    // Fechar o arquivo
    fclose(arquivo);

    // Ordenar os dados em ordem decrescente de pontuação
    qsort(dados, numDados, sizeof(Dado), compararDados);

    // Exibir o ranking
    
    for (i = 0; i < numDados; i++) {
    	
    	//definir a quantidade de pontos
len = tamanho - strlen(dados[i].nome);
    	
        printf("%s ", dados[i].nome);
        for(j=0; j<=len; j++){
		printf(".");}
        printf(" %d   ", dados[i].pontuacao);
        
        if(i<3){
        	printf("%dº", i + 1);
		}
		printf("\n\n\n");
    }
    system("pause");
}
void puxarPontuacao(const char* nome, int* points) {
    FILE* arquivo = fopen("pontuacao.txt", "r");

    int pontos = -1;
    char linha[100];
    
    //laço dentro do arquivo txt
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        int pontuacao;
        char nomeArquivo[100];

		//se o nome for o encontrado o laço para e retorna o valor da pontuação para variável pontos
        if (sscanf(linha, "%d %s", &pontuacao, nomeArquivo) == 2) {
            if (strcmp(nomeArquivo, nome) == 0) {
                pontos = pontuacao;
                break;
            }
        }
    }

    fclose(arquivo);

    if (pontos != -1) {
         *points = pontos;
}
}
