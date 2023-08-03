#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void napoleao0(char texto[30]){
	printf("         ________\n        /        \\\n     __/       (o)\\__\n    /     ______\\\\   \\\n    |____/__  __\\____|     %s\n       [  --~~--  ]           /\n        |(  L   )|           /\n  ___----\\  __  /----___\n /   |  < \\____/ >   |   \\\n/    |   < \\--/ >    |    \\\n||||||    \\ \\/ /     ||||||\n|          \\  /   o       |\n|     |     \\/   === |    |\n|     |      |o  ||| |    |\n|     \\______|   +#* |    |\n|            |o      |    |\n \\           |      /     /\n |\\__________|o    /     /\n |           |    /     /\n", texto);
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	napoleao0("Ei! Você é o novo capitão, correto?");
	system("pause");
	system("cls");
	napoleao0("Estamos com problemas...");
	system("pause");
	system("cls");
	napoleao0("Preciso que você assuma o comando da Navy Zero e acabe com os malditos piratas!");
	system("pause");
	system("cls");
	napoleao0("Arrume suas coisas! A Sargento Miranda vai te acompanhar!");
	system("pause");
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("                                __________________________________________");
	printf("\n\n\n                                                Começou!\n\n\n");
	printf("                                __________________________________________\n\n\n\n\n\n");
}
