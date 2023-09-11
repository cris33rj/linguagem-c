#include <stdio.h>
#include <stdlib.h>

int main()
{
    int countAlunos=0;
    int idade=0;
    float altura=0.0;

    int maioresQue20 = 0;
    float baixos;
    float somaIdades=0;
    float somaAltura=0.0;

    do
    {
        printf("Informe a idade do aluno: \n");
        scanf("%d",&idade);

        printf("Informe a altura do aluno: \n");
        scanf("%f",&altura);

        if (idade>20)
        {
            maioresQue20++;
            somaIdades+=idade;
            printf("entrou1: \n");

        }

        if (altura<1.70) {
            baixos++;
            somaAltura+=altura;
            printf("entrou2: \n");
        }

        countAlunos++;
    } while (countAlunos<2);

    printf("Media idade %.2f",somaIdades/maioresQue20);
    printf("Media altura %.2f",somaAltura/baixos);
}
