#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[31];
    char mat[10], turma[3];
    float p1, p2;
} TALUNO;

TALUNO *lerAluno()
{
    TALUNO *aluno = (TALUNO *) malloc(sizeof(TALUNO));
    printf("digite o nome do aluno ");
    fgets(aluno->nome,31,stdin);
    printf("digite a matéria do aluno ");
    fgets(aluno->mat,10,stdin);
    printf("digite a turma do aluno ");
    fgets(aluno->turma,3,stdin);
    printf("digite a nota da prova1 ");
    scanf("%f",&aluno->p1);
    printf("digite a nota da prova2 ");
    scanf("%f",&aluno->p2);
    scanf("%c");

    printf("\n");


    return aluno;
}

void imprime (TALUNO **mat, int n)
{
    float mediaMinima= 6.0;
    for (int i=0; i<n; i++)
    {   mat[i]->nome[strcspn(mat[i]->nome, "\n")] = 0;
        mat[i]->mat[strcspn(mat[i]->mat, "\n")] = 0;
        mat[i]->turma[strcspn(mat[i]->turma, "\n")] = 0;
        float media = (mat[i]->p1+mat[i]->p2)/2;
        if ((mat[i]->p1+mat[i]->p2)/2>=mediaMinima)
        {
            printf("Nome: %s\tMatricula: %s\tTurma: %s\tP1: %.2f\tP2: %.2f\tMedia: %.2f\n",mat[i]->nome,mat[i]->mat,mat[i]->turma,mat[i]->p1,mat[i]->p2,media);
//            printf("%s",mat[i]->mat);
//            printf("%s",mat[i]->turma);
//            printf("%.2f\n",mat[i]->p1);
//            printf("%.2f\n",mat[i]->p2);
//            printf("\n ");
        }
    }




}

float media_geral(TALUNO **mat, int n, char *turma)
{
    float soma_medias=0;
    float media_geral_turma;

    for(int i=0;i<n;i++){
         //   printf("imprimindo o parametro turma %s",turma);
           // printf("imprimindo a turma do aluno %s",mat[i]->turma);
        float media = (mat[i]->p1+mat[i]->p2)/2;
        if (strcmp(mat[i]->turma,turma)==0){
        //    printf("entrou no if");
            soma_medias+= media;
        }
    }
  //  printf("saiu do metodo");
    return media_geral_turma = soma_medias/n;







}

int i,j;

int main ()
{
    TALUNO ** alunos = (TALUNO **)malloc(sizeof(TALUNO *)*3) ;

    for (i=0; i<3; i++)
    {
        alunos[i] = lerAluno();
    }
//
//    for (i=0; i<2; i++)
//    {
//        printf("%s",alunos[i]->nome);
//        printf("%s",alunos[i]->mat);
//        printf("%s",alunos[i]->turma);
//        printf("%.2f\n",alunos[i]->p1);
//        printf("%.2f\n",alunos[i]->p2);
//        printf("\n ");
//    }
    char turma[] = "10";
    imprime(alunos, 3);

    float media_geral_turma = media_geral(alunos,2,turma);
    printf("Media geral da turma de %s: %.2f",turma, media_geral_turma);

}












