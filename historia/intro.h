#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void napoleao0(char texto[50]){
	printf("\n\n\n\n\n         ________\n        /        \\\n     __/       (o)\\__\n    /     ______\\\\   \\\n    |____/__  __\\____|     %s\n       [  --~~--  ]           /\n        |(  L   )|           /\n  ___----\\  __  /----___\n /   |  < \\____/ >   |   \\\n/    |   < \\--/ >    |    \\\n||||||    \\ \\/ /     ||||||\n|          \\  /   o       |\n|     |     \\/   === |    |\n|     |      |o  ||| |    |\n|     \\______|   +#* |    |\n|            |o      |    |\n \\           |      /     /\n |\\__________|o    /     /\n |           |    /     /\n", texto);
}

void introd(){
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	napoleao0("Ei! Você é o novo capitão, correto?");
	system("pause");
	system("cls");
	napoleao0("Estamos com problemas...");
	system("pause");
	system("cls");
	napoleao0("Preciso que você assuma o comando da Navy Zero e acabe com os piratas!");
	system("pause");
	system("cls");
	napoleao0("Para iniciar tome este dinheiro e alguns ítens para negociar antes da jornada");
	system("pause");
	system("cls");
	napoleao0("Depois de passar no mercador, Sargento Miranda vai te acompanhar");
	system("pause");
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("                                __________________________________________");
	printf("\n\n\n                                                Boa sorte!\n\n\n");
	printf("                                __________________________________________\n\n\n\n\n\n");
	system("pause");
}
