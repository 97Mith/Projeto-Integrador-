#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include "menu\botao.h"
#include "graficos\navio0.h"
#include "graficos\mercador.h"
#include "arquivos de login e senha\cs.h"
#include <stdlib.h>
#include "jogo_elementos\inimigo.h"
#include "historia\intro.h"

//função que chama cores

void collor(numero){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),numero);
}
void yellowBar(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
}
void cian(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
}
void green(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
}
void blue(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
}
void red(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
}
void normal(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}


//jogo
void game(int* passar_de_fase, int* missil, int* pontos, int barco, int dificuldade, int fase, char nome[50]){ 

		//variáveis de controle para a matriz
		int i, j;
		
		//variaveis de linhas e colunas
		int l, c = 0;
		
		//variavel que controla a vitória
		int vitoria = 12;
				if(dificuldade == 1){       //a real dificuldade do jogo se encontra em quantos barcos o jogador deve afundar
				vitoria = 5;}
				else if(dificuldade == 2){
				vitoria = 8;}
				else{
				vitoria = 12;}
				
		//munição e vida
		
		int HP = barco;
		
		//variável que determina a fala do sargento
		int win = 0;
		
		
		
		
	int tabuleiro[6][6] = {{0}};
    int contador = 0;
    srand(time(NULL)); // Semente para geração de números aleatórios

    while (contador < 12) {
        int linha = rand() % 6; // Gera um número aleatório entre 0 e 5
        int coluna = rand() % 6;

        if (tabuleiro[linha][coluna] == 0) {
            tabuleiro[linha][coluna] = 1;
            contador++;
        }
    }


//pontos = 0;
do{ system("cls");

enemy(&HP);
if (HP <=0){
	vitoria = 1;
	break;
}
if (vitoria == 1){
	win = 5;
}
if(HP == 20){
	//cabeçalho do game que mostra a vida e os tiros que ainda faltam
	linha();
	itens();
	printf("     %d/", barco); 
	red();
	printf("20\t\t\t\t\t\t ");
	normal();
	printf("%d              %d\n", *missil, vitoria);
	linha();
	win = 4;
}
else if (HP == 5){
	linha();
	itens();
	printf("     %d/", barco); 
	red();
	printf("5\t\t\t\t\t\t ");
	normal();
	printf("%d              %d\n", *missil, vitoria);
	linha();
	win = 4;
}
else{
	
	linha();
	itens();
	printf("     %d/%d\t\t\t\t\t\t %d              %d\n", barco, HP, *missil, vitoria);
	linha();
}
	



	//impressão da matriz na tela
	
		
		for(i=0; i<6; i++){
			printf("        \t%d", 6 - i);
			
			for(j=0; j<6; j++){
				if(tabuleiro[i][j] == 2){
					red();
					printf("\t^XXX^");
					normal();
				}
				else if(tabuleiro[i][j] == 3){
					green();
					printf("\t_\\|/_");	
					normal();
				}
				else if(tabuleiro[i][j] > 3){
					blue();
					printf("\t.....");
					normal();
				}
				else {
					cian();
					printf("\t~~~~~");
					normal();
				}
			}
		printf("\n\n\n");	
		}
		
		printf("        \t\tA\tB\tC\tD\tE\tF\n\n\n\n");
		
		linha();
		printf("\t\t\t\t\t\t\t\t\tpts = %d", *pontos);
		printf("\n");
	
		
		if (win == 1){
			cap("ACERTAMOS! Excelente");
			printf("\n\n");
			
		}
		else if(win == 2){
			cap1("Erramos o alvo, senhor...");
			printf("\n\n");
		}
		else if(win == 3){
			cap("Já atiramos ali, senhor!");
			printf("\n\n");
		}
		else if(win == 4){
			blue();
			cap("Estamos por um triz...");
			normal();
			printf("\n\n");
			
		}
		else if(win == 5){
		green();
		cap("Só falta um, capitão!!");
		normal();
		printf("\n\n");
		}
		else{
			cap("Vamos lá...");
			printf("\n\n");
			
		}
		
		//validador de letras
	int i;
    int tru = 1;
    int ok_letra;
    
    char input[1];
    const char *letra[6];
    
    
    //variavel lista com as letras do alfabeto
	letra[0] = "a"; letra[1] = "b"; letra[2] = "c"; letra[3] = "d"; letra[4] = "e"; letra[5] = "f";
	
	
    
	
	do{
		
	printf("\nEscolha a coluna ('A' a 'F'): ");
    scanf("%s", input);
    fflush(stdin);
		
		
	for(i=0; i<6; i++){
		ok_letra = 0;
		ok_letra = strcmp(input, letra[i]);
		
		if(ok_letra == 0){
			l = i;
			tru = 0;
			
			break;
						}	
	}
		
	}while(tru);
		
		//validador de numeros
	//-----------------------------------------------------
	
		int truth = 1;
		do{
		puts("Excelente, agora nos digue a linha que deseja atacar!");
		scanf("%d", &c);
		fflush(stdin);
		if(c < 7){
			truth = 0;
		}
			
		}while(truth);
		
		
		
	//-----------------------------------------------------
		//calculo que fara o alvo atingir
		*missil -= 1;
		tabuleiro[6 - c][l] += 2;
		
		
		//logica que progride a vitória e determina a fala do sargento
		if(tabuleiro[6 - c][l] == 3){
			win = 1;
			vitoria --;	
			*pontos += 100;
		}
		else if(tabuleiro[6 - c][l] == 2){
			win = 2;
			*pontos -= 10;
		}
		else if(tabuleiro[6 - c][l] > 3){
			win = 3;
		}
		else{
			win = 0;
			
		}
		
		
		if (*missil < vitoria){
			break;
		}
		
		
	}while(vitoria);
		if(vitoria == 0){ system("cls");
			yellowBar();
			cabecalho("VITÓRIA!");
			printf("\n\n\n");
			cap("Parabéns, senhor. Vencemos!");
			printf("\n\n\n\n\n\n\nPontuação = %d X 2 = %d\n\n\n", *pontos, *pontos * 2);
			*pontos *= 2;
			*passar_de_fase = 1;
			puts("");
			normal();
			system("pause");
		}
		else{system("cls");
			blue();
			cabecalho("DERROTA!");
			printf("\n\n\n");
			cap1("Senhor... perdemos, infelizmente...");
			puts("");
			normal();
			
			*passar_de_fase = 0;
			system("pause");	
		}
FILE* arquivo = fopen("pontuacao.txt", "r+");
    

    int encontrou = 0;
    char linha[100];
    long posicao = 0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char nomeArquivo[100];
        int pontuacao;

        if (sscanf(linha, "%d %s", &pontuacao, nomeArquivo) == 2) {
            if (strcmp(nomeArquivo, nome) == 0) {
                encontrou = 1;
                break;
            }
        }

        posicao = ftell(arquivo);
    }

    if (encontrou) {
        fseek(arquivo, posicao, SEEK_SET);
        fprintf(arquivo, "%d %s\n", *pontos, nome);
        
    } else {
        printf("Nome não encontrado.\n");
    }

    fclose(arquivo);
}




//função da tela do mercador 
void mercador_tela(int* missil, int* barco, int* dinheiro, int* espolios, int* tesouro){ 
		//variaveis
	int sair = 1;
	
	int confirma = 0;
	int opcao, nav, lixo;
	
	do{
	
	opcao = 0;
	nav = 0;
	system("cls");
	
	//tela
	yellowBar();
	cabecalho("Lojinha");
	printf("\t\t\t\t\t\t\t\t\t$ %d\n\n\n\n", *dinheiro);
	normal();
	mercador_fala("Eai, truta. Vai querer o que?");
	yellowBar();
	linha();
	printf("\n\n");
	opcao0(" 1 Comprar", "\t     2 Vender", "\t      3 Zarpar");
	printf("\n\n");
	linha();
	normal();
	puts("Escolha sua opção: ");
	yellowBar();
	scanf("%d", &opcao);
	
	//OPÇÃO DE COMPRAS
	if (opcao == 1){
		fflush(stdin);
		
		system("cls");
		cabecalho("Compras");
		printf("\t\t\t\t\t\t\t\t\t$ %d\n\n\n\n", *dinheiro);
		normal();
		mercador_fala("Cuidado pra não explodir alguém com essas coisas.");
		yellowBar();
		linha();
		printf("\n\n");
		opcao0("1 (5) Mísseis", "2 Melhorar embarc", "3 Voltar");
		printf("\t\t$2000\t\t\t$5000");
		printf("\n\n");
		linha();
	normal();
	puts("Escolha sua opção: ");
	yellowBar();
		scanf("%d", &nav);
		
		if (nav == 1){
			system("cls");
			cabecalho("	  Compras");
			printf("\t\t\t\t\t\t\t\t\t$ %d\n\n\n\n", *dinheiro);
			cabecalho("Confirmar compra?");
			printf("\n\n\n\n");
			puts("			   1 Sim                         2 Não");
			printf("\n\n\n\n");
			linha();
			scanf("%d", &confirma);
			
			//confirmação de compra
			if (confirma == 1){
				fflush(stdin);
				if (*dinheiro >= 2000){
					*dinheiro -= 2000;
					*missil += 5;
					system("cls");
					cabecalho("Lojinha");
					printf("\t\t\t\t\t\t\t\t\t$ %d\n\n\n\n", *dinheiro);
					normal();
					mercador_fala("Hehe, obrigado.");
					yellowBar();
					printf("\n\n");
					cabecalho(" ");
					system("pause");
					/*puts("Pressione qualquer tecla");
					scanf("%d", &lixo);*/
					}
				else{
					system("cls");
					cabecalho("Lojinha");
					printf("\t\t\t\t\t\t\t\t\t$ %d\n\n\n\n", *dinheiro);
					normal();
					mercador_bravo("Ei, você não tem grana pra comprar isso!!");
					yellowBar();
					printf("\n\n");
					cabecalho(" ");
					printf("\n\n");
					
					system("pause");
				}
				}
			
	}
		}
		if (nav == 2){
			
			system("cls");
			cabecalho("	  Compras");
			printf("\t\t\t\t\t\t\t\t\t$ %d\n\n\n\n", *dinheiro);
			cabecalho("Confirmar compra?");
			printf("\n\n\n\n");
			puts("			   1 Sim                         2 Não");
			printf("\n\n\n\n");
			linha();
			scanf("%d", &confirma);
			
			//confirmação de compra
			if (confirma == 1){
				fflush(stdin);
				if (*dinheiro >= 5000){
					*dinheiro -= 5000;
					*barco += 25;
					system("cls");
					cabecalho("Lojinha");
					printf("\t\t\t\t\t\t\t\t\t$ %d\n\n\n\n", *dinheiro);
					normal();
					mercador_fala("Cuida bem do barco, meu amigo!.");
					yellowBar();
					printf("\n\n");
					cabecalho(" ");
					
					system("pause");
					}
				else{
					system("cls");
					cabecalho("Lojinha");
					cian();
					printf("\t\t\t\t\t\t\t\t\t$ %d\n\n\n\n", *dinheiro);
					mercador_bravo("Não vendo isso para pobretões!!");
					yellowBar();
					printf("\n\n");
					cabecalho(" ");
					printf("\n\n");
					
					system("pause");
				}
				}
		
		}

//OPCAO DE VENDA
		if (opcao == 2){
			fflush(stdin);
			
			system("cls");
			cabecalho("Vendas");
			printf("\t\t\t\t\t\t\t\t\t$ %d\n\n\n\n", *dinheiro);
			normal();
			mercador_fala("Eu compro o que for.");
			yellowBar();
			linha();
			printf("\n\n");	
			opcao1(*espolios, *tesouro);
			printf("\n\n");
			linha();
			normal();
			puts("Escolha sua opção: ");
			yellowBar();
			scanf("%d", &nav);
			fflush(stdin);
			//venda dos espólios
			if (nav == 1){
				system("cls");
				fflush(stdin);
				cabecalho("	  Vendas");
				printf("\t\t\t\t\t\t\t\t\t$ %d\n\n\n\n", *dinheiro);
				cabecalho("Confirmar venda");
				printf("\n\n");
				printf("\t\t\t       Vender os espólios por $%d?\n\n\n", *espolios * 500);
				puts("			   1 Sim                         2 Não");
				printf("\n\n\n\n");
				linha();
				scanf("%d", &confirma);
				if (confirma == 1){
					*dinheiro += (*espolios * 500);
					*espolios = 0;
					fflush(stdin);
				}
			}
			//venda dos tesouros
			if (nav == 2){
				if (tesouro == 0){
					system("cls");
					cabecalho("	  Vendas");
					printf("\t\t\t\t\t\t\t\t\t$ %d\n\n\n\n", *dinheiro);
					cian();
					mercador_bravo("Some daqui, você não tem tesouros!");
					yellowBar();
					cabecalho(" ");
					
					system("pause");
			}
				else{
					system("cls");
				fflush(stdin);
				cabecalho("	  Vendas");
				printf("\t\t\t\t\t\t\t\t\t$ %d\n\n\n\n", *dinheiro);
				cabecalho("Confirmar venda");
				printf("\n\n");
				printf("\t\t\t       Vender os tesouros por $%d?\n\n\n", *tesouro * 7000);
				puts("			   1 Sim                         2 Não");
				printf("\n\n\n\n");
				linha();
				scanf("%d", &confirma);
				if (confirma == 1){
					system("cls");
					cabecalho("	  Vendas");
					printf("\t\t\t\t\t\t\t\t\t$ %d\n\n\n\n", *dinheiro);
					mercador_surp("Lá se vão minhas economias!");
					cabecalho(" ");
					
					system("pause");
					*dinheiro += (*tesouro * 7000);
					fflush(stdin);
					*tesouro = 0;
				}
				}
				
			}
			
			
		}
		if (opcao == 3){
			system("cls");
				cabecalho("	  Sair");
				printf("\t\t\t\t\t\t\t\t\t$ %d\n\n\n\n", *dinheiro);
				cabecalho("Isso é tudo, parceiro?");
				printf("\n\n\n\n");
				puts("			         Pressione '0' para zarpar");
				printf("\n\n\n\n");
				linha();
				normal();
				scanf("%d", &sair);
		}

} while(sair);

}

//funções da tela do menu de acordo com a dificuldade selecionada
void menu_layout_facil(void){
	linha(); yellowBar(); titulo_jogo(); normal(); linha(); s0(); printf("\n\n"); printf("\n\n\n\n\n"); cian();boat();normal(); printf("\n\n\n\t\t\t\t\t\t\t\t\t   (easy mode)\n");
}
void menu_layout_regular(void){
	linha();  //   ----------------------> modulo que chama uma linha
	yellowBar(); titulo_jogo(); normal();  //   ----------------> modulo que chama o título do jogo
	linha();
	
	s0(); //   --------------------------> modulo que chama a interface do menu
	/*printf("\n\n\n\n\n\n");*/
	cian();
	boat2();  //    ---------------------> modulo que chama o navio
	normal();
	printf("\n\n\n\t\t\t\t\t\t\t\t\t(regular mode)\n");
}
void menu_layout_dificil(void){
	
	linha(); yellowBar(); titulo_jogo(); normal(); linha(); s0(); printf("\n\n\n"); cian(); navy1();normal(); printf("\n\n\n\t\t\t\t\t\t\t\t\t   (hard mode)\n");
}

//programa em si
int main(){
	setlocale(LC_ALL, "Portuguese"); //habilita a acentuação para o português
	
			// itens que são adquiridos no passar das fases e servem para serem vendidos no mercador
			int tesouro = 1;
			int espolios = 4;
			
			//variavel para entrar no jogo se verdadeiro o jogo é iniciado
			int entrar = 0;
			char nome[50];
			int pontos = 0;
			int passar = 1;
			
			int dificuldade = 2; //define o nivel de dificuldade e design do menu
	
			int escape = 1; //variavel que segura o laço
	
			int escolha; //variável que determinara a escolha das opções do menu
			
			int dinheiro = 2000; //dineiro de exemplo, será carregado externamente junto com o save
			
			//munição
			int missil = 29;
			
			//limite de vida do jogador
			int barco = 100;
			
			int fase = 10;
		
	
		
	do{
	system("cls");
	puts("\t\t\t\tBatalha Naval em linguagem C");
	//trecho que determina o design do menu
		if (dificuldade == 1){
			menu_layout_facil();
	}
		if (dificuldade == 2){
			menu_layout_regular();
	}
		if (dificuldade == 3){
			menu_layout_dificil();
	}
		
	//navegação do menu
	scanf("%d", &escolha);
		
		if (escolha == 1){
			
			login(nome, &entrar);
			if (entrar == 1){
				
			puxarPontuacao(nome, &pontos);
			if (pontos > 600 && missil == 29){
				missil = 8;
				tesouro = 0;
			}
			else{
				blue();
				introd();
				normal();
			}
				do{
				
			
			mercador_tela(&missil, &barco, &dinheiro, &espolios, &tesouro);
			game(&passar, &missil, &pontos, barco, dificuldade, fase, nome);
			
			if(passar == 1){
				system("cls");
				printf("\n\n\n");
				green();cabecalho("Parabéns");normal();
				printf("\n\n\n");
				cap("Senhor!");linha(); printf("\n\n\n\n");cian();navy1();normal();printf("\n");
				system("pause");
				system("cls");
				printf("\n\n\n");
				green();cabecalho("!!!!!!!!!");normal();
				printf("\n\n\n");
				cap("Ítens foram encontrados nos destroços");linha(); printf("\n\n\n\n");cian();navy1();normal();printf("\n");
				system("pause");
				system("cls");
				randomizador(&fase, 100);
				
				
				if(fase < 50){
					cian();cabecalho("Recompensas!");normal();
					linha(); printf("\n\n\n\n");
					cap("encontramos 5 espólios de guerra e $ 1000");linha(); printf("\n\n\n\n");yellowBar();coin();normal();printf("\n");
					espolios += 5;
					dinheiro += 1000;
					system("pause");
				}
				else{
					cian();cabecalho("Recompensas!");normal();
					linha(); printf("\n\n\n\n");
					cap("encontramos 1 tesouro raro!!"); linha(); printf("\n");yellowBar();treasure();normal();printf("\n");
					tesouro += 1;
					system("pause");
				}
				system("cls"); printf("\n\n\n\n\n\n\n\n"); cabecalho("SALVANDO..."); printf("\n\n\n\n\n\n\n\n");system("pause");
				system("cls"); printf("\n\n\n\n\n\n\n\n"); green();cabecalho("JOGO SALVO"); yellowBar();
				linha();printf("\t\t\t\t\tDica!!\n\nUtilize os ítens encontrados para comercializar com mercador\n");
				linha();
				printf("\n\n\t\t\tDeseja parar? '0' para parar '1' para continuar"); printf("\n\n\n\n\n");normal();
				scanf("%d", &passar);
			}
			}while(passar);
			
		}
	}
		
		if (escolha == 2){
			system("cls");
			collor(10);
			cadastro();
			collor(15);
		}
		if (escolha == 3){
		
			system("cls");
			if (dificuldade == 1){
				linha();
				titulo_jogo();
				linha();
				cabecalho("DIFICULDADE");
				printf("\n\n\n\n\n");
				s1();
				printf("\n\n\n\n\n");
				navy0();
			}
			if (dificuldade == 2){
				linha();
				titulo_jogo();
				linha();
				cabecalho("DIFICULDADE");
				printf("\n\n\n\n\n");
				s2();
				printf("\n\n\n\n\n");
				navy0();
			}
			if (dificuldade == 3){
				linha();
				green();
				titulo_jogo();
				normal();
				linha();
				cabecalho("DIFICULDADE");
				printf("\n\n\n\n\n");
				s3();
				
				printf("\n\n\n\n\n");
				cian();
				navy0();
				normal();
			}
			scanf("%d", &dificuldade);
			
			// verificar uma função mais prática depois
			
			
			if (dificuldade != 1 && dificuldade != 2 && dificuldade != 3){
			dificuldade = 2;
			system("cls");
			red();
			cabecalho("		ERRO");
			cabecalho("Opção inválida!");linha();
			normal();
			printf("\n\n\n\t\t\t\t     Alto lá!\n\n\n");
			printf("\n\t\t\tNão te dei esse caminho!...\n\n \t\t\tEscolha apenas opções válidas!\n\n\n\n\n\n\n\n\n");
			linha();
			
			system("pause");	}
		
		
		
	// reservado para a tela do mercador
			
	fflush(stdin);
	
}
	
		if (escolha == 4){
			system("cls");
			linha();
			green();
			titulo_jogo();
			normal();
			linha();
			cabecalho("RANKING");
			ranking();
		}
		if (escolha == 5){
				system("cls");
				linha();
				titulo_jogo();
				cabecalho("Vai se retirar?");
				printf("\n\n\n\n\n\n\n\n");
				puts("\t\t\t\tDigite 0 para confirmar");
				printf("\n\n\n\n\n\n\n\n");
				linha();
				scanf("%d", &escape);
		}

	} while (escape);
}
	

