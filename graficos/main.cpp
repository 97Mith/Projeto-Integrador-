#include <stdio.h>

int main() {
    float nota, soma = 0;
    int num_notas, i = 1;
    
    

    printf("Quais notas deseja calcular? ");
    scanf("%d", &num_notas);

    while (i <= num_notas) {
        printf("Digite a nota %d: ", i);
        scanf("%f", &nota);
        soma += nota;
        i++;
    }

    float media = soma / num_notas;
    printf("A media das notas é %.2f\n", media);

    if (media >= 70)
        printf("O aluno foi aprovado!\n");
    else
        printf("O aluno foi reprovado!\n");

    return 0;
}
	
