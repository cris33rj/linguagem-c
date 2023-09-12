#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa
{
  int mat;
  char data_nasc[9];
  char nome[31];
} TP;

TP *retira_k(TP **vet, int *n, int k);

int qSortCompara(const void *void_x, const void *void_y)
{
  TP *x = (TP *)void_x;
  TP *y = (TP *)void_y;

  int cmp_ano = strncmp(x->data_nasc + 4, y->data_nasc + 4, 4);
  if (cmp_ano != 0)
  {
    return cmp_ano;
    printf("=====>%d", cmp_ano);
  }
  else
    printf("SAO IGUAIS");
  /* int cmp_mes = strncmp(x->data_nasc + 2, y->data_nasc + 2, 2);
  if (cmp_mes != 0)
    return cmp_mes;
  int cmp_dia = strncmp(x->data_nasc, y->data_nasc, 2);
  if (cmp_dia != 0)
    return cmp_dia;
  int cmp_nome = strcmp(x->nome, y->nome);
  if (cmp_nome != 0)
    return cmp_nome;
  if (x->mat < y->mat)
    return -1;
  if (x->mat > y->mat)
    return 1; */
}

void ordena(TP **vet, int n)
{
  qsort(vet, n, sizeof(TP *), qSortCompara);
}

TP *ler_pessoa()
{
  TP *pessoa = malloc(sizeof(TP));
  printf("digite os dados(mat, data nasc e nome");
  scanf("%d", &pessoa->mat);
  scanf(" %9[^\n]", pessoa->data_nasc);
  scanf(" %31[^\n]", pessoa->nome);
  return pessoa;
}

int main(void)
{
  int n;
  printf("Digite o tamanho do vetor... ");
  scanf("%d", &n);
  if (n <= 0)
    return 0;
  TP **pessoas = (TP **)malloc(sizeof(TP *) * n);
  for (int i = 0; i < n; i++)
  {
    pessoas[i] = ler_pessoa();
  }

  printf("IMPRIMINDO ANTES DE ORDENAR\n");
  for (int i = 0; i < n; i++)
  {
    printf("nome: %s --> nasc:%s\n", pessoas[i]->nome, pessoas[i]->data_nasc + 4);
  }

  printf("IMPRIMINDO DEPOIS DE ORDENAR\n");

  ordena(pessoas, n);
  for (int i = 0; i < n; i++)
  {
    printf("nome: %s --> nasc:%s\n", pessoas[i]->nome, pessoas[i]->data_nasc);
  }

  printf("Digite a posicao do elemento a ser retirado... ");
  int k;
  scanf("%d", &k);
  TP *elem = NULL;
  elem = retira_k(pessoas, &n, k);
  /*free(elem);
  printf("Depois de retira_k:\n");
  for(i = 0; i < n; i++)
    if(vet[i]) printf("%d %s %s\n", vet[i]->mat, vet[i]->data_nasc, vet[i]->nome);
  for(i = 0; i < n; i++)
    free(vet[i]);
    */
  return 0;
}
TP *retira_k(TP **vet, int *n, int k)
{
  TP *temp = vet[k];
  vet[k] = NULL;
  for (int i = 0; i < *n; i++)
  {
    if (vet[i] != NULL)
    {
      printf("%d %s %s\n", vet[i]->mat, vet[i]->data_nasc, vet[i]->nome);
    }
  }
}
