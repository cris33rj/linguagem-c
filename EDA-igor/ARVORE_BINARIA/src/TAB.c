#include "TAB.h"

TAB *TAB_inicializa(void)
{
  return NULL;
}

TAB *TAB_cria(int raiz, TAB *esq, TAB *dir)
{
  TAB *novo = (TAB *)malloc(sizeof(TAB));
  novo->info = raiz;
  novo->esq = esq;
  novo->dir = dir;
  novo->cor = 0;
  return novo;
}

TAB *TAB_busca(TAB *a, int elem)
{
  if ((!a) || (a->info == elem))
    return a;
  TAB *resp = TAB_busca(a->esq, elem);
  if (resp)
    return resp;
  return TAB_busca(a->dir, elem);
}

void TAB_imp_pre(TAB *a)
{
  if (a)
  {
    printf("%d ", a->info);
    TAB_imp_pre(a->esq);
    TAB_imp_pre(a->dir);
  }
}

void TAB_imp_pos(TAB *a)
{
  if (a)
  {
    TAB_imp_pos(a->esq);
    TAB_imp_pos(a->dir);
    printf("%d ", a->info);
  }
}

void TAB_imp_sim(TAB *a)
{
  if (a)
  {
    TAB_imp_sim(a->esq);
    printf("%d ", a->info);
    TAB_imp_sim(a->dir);
  }
}

void imp_aux(TAB *a, int andar)
{
  int j;
  if (a)
  {
    imp_aux(a->esq, andar + 1);
    for (j = 0; j <= andar; j++)
      printf("\t"); // printf("   ");
    printf("%d\n", a->info);
    imp_aux(a->dir, andar + 1);
  }
  else
  {
    for (j = 0; j <= andar; j++)
      printf("\t");
    printf("N\n");
  }
}

void TAB_imp_ident(TAB *a)
{
  imp_aux(a, 0);
}

void TAB_libera(TAB *a)
{
  if (a)
  {
    TAB_libera(a->esq);
    TAB_libera(a->dir);
    free(a);
  }
}

TAB *TAB_copia(TAB *a)
{
  if (!a || (!a->esq && !a->dir))
    return a;
  TAB *b = TAB_cria(a->info, NULL, NULL);
  b->esq = TAB_copia(a->esq);
  b->dir = TAB_copia(a->dir);
  return b;
}

TAB *TAB_espelho(TAB *a)
{
  if (!a || (!a->esq && !a->dir))
    return a;
  TAB *b = TAB_cria(a->info, NULL, NULL);
  b->esq = TAB_espelho(a->dir);
  b->dir = TAB_espelho(a->esq);
  return b;
}

TAB *TAB_maior(TAB *a)
{

  if (!a)
    return a;

  TAB *maior_esq = TAB_maior(a->esq);
  TAB *maior_dir = TAB_maior(a->dir);
  TAB *maior = a;
  if (maior_esq != NULL && (maior_esq->info > maior->info))
    maior = maior_esq;

  if (maior_dir != NULL && (maior_dir->info > maior->info))
    maior = maior_dir;
  return maior;
}

TAB *TAB_menor(TAB *a)
{

  if (!a)
    return a;

  TAB *menor_esq = TAB_menor(a->esq);
  TAB *menor_dir = TAB_menor(a->dir);
  TAB *menor = a;
  if (menor_esq != NULL && (menor_esq->info < menor->info))
    menor = menor_esq;
  if (menor_dir != NULL && (menor_dir->info < menor->info))
    menor = menor_dir;
  return menor;
}

// versao aperfeiçoada mais ainda
int TAB_igual(TAB *a1, TAB *a2)
{
  /*1. both empty */
  if (!a1 && !a2)
    return 1;

  /* 2. both non-empty -> compare them */
  if (a1 && a2)
  {
    return (a1->info == a2->info && TAB_igual(a1->esq, a2->esq) && TAB_igual(a1->dir, a2->dir));
  }
  /* 3. one empty, one not -> false */
  return 0;
}

TAB *TAB_retira_pares(TAB *a)
{

  if (!a)
    return NULL;

  TAB_retira_pares(a->esq);
  TAB_retira_pares(a->dir);

  if (a)
  {
    if (a->esq && a->esq->info % 2 == 0 && (a->esq->esq == NULL && a->esq->dir == NULL))
    {
      free(a->esq);
      a->esq = NULL;
    }
    if (a->dir && a->dir->info % 2 == 0 && (a->dir->esq == NULL && a->dir->dir == NULL))
    {
      free(a->dir);
      a->dir = NULL;
    }
  }

  if (a && a->info % 2 == 0 && a->esq != NULL)
  {
    TAB *temp = a;
    while (temp->esq != NULL)
    {
      if (temp != NULL)
        temp->info = temp->esq->info;
      if (temp->esq->esq != NULL)
        temp = temp->esq;
      else
      {
        if (temp->esq->esq == NULL)
        {
          free(temp->esq);
          temp->esq = NULL;
        }
      }
    }
  }

  if (a && a->info % 2 == 0 && a->dir != NULL)
  {
    TAB *temp = a;
    while (temp->dir != NULL)
    {
      if (temp != NULL)
        temp->info = temp->dir->info;

      if (temp->dir->dir != NULL)
        temp = temp->dir;
      else
      {
        if (temp->dir->dir == NULL)
        {
          free(temp->dir);
          temp->dir = NULL;
        }
      }
    }
  }
  return a;
}

void aux_colore(TAB *a, int andar)
{

  if (a)
  {
    aux_colore(a->esq, andar + 1);

    if (andar == 0 || andar % 2 == 0)
      a->cor = 1;
    else
      a->cor = 2;

    aux_colore(a->dir, andar + 1);
  }
}

void TAB_colore(TAB *a)
{
  aux_colore(a, 0);
}

void imp_aux_cor(TAB *a, int andar)
{
  int j;
  if (a)
  {
    imp_aux_cor(a->esq, andar + 1);
    for (j = 0; j <= andar; j++)
      printf("\t"); // printf("   ");
    printf("%d\n", a->cor);
    imp_aux_cor(a->dir, andar + 1);
  }
  else
  {
    for (j = 0; j <= andar; j++)
      printf("\t");
    printf("N\n");
  }
}

void TAB_imp_ident_cor(TAB *a)
{
  imp_aux_cor(a, 0);
}

int aux_conta_ni(TAB *a, int contador)
{
  if (!a || (!a->esq && !a->dir))
    return 0;

  int cont_esq = aux_conta_ni(a->esq, contador + 1);

  aux_conta_ni(a->dir, cont_esq);

  return contador;
}

int TAB_ni(TAB *a)
{

  if (!a || (!a->esq && !a->dir))
    return 0;
  else
    return 1 + (TAB_ni(a->esq) + TAB_ni(a->dir));
}

int TAB_nf(TAB *a)
{

  if (a && (!a->esq && !a->dir))
    return 1;
  else
    return (TAB_nf(a->esq) + TAB_nf(a->dir));
}

int TAB_isArvoreBB(TAB *a)
{

  TAB *maiorEsquerda = TAB_maior(a->esq);
  TAB *maiorDireita = TAB_maior(a->dir);
  if (maiorEsquerda->info > a->info || maiorDireita->info < a->info)
    return 0;
  else
    return 1;
}

int maximo(int a, int b)
{
  if (a > b)
    return a;
  return b;
}

int TAB_altura(TAB *a)
{
  if (!a)
    return -1;
  return maximo(TAB_altura(a->esq), TAB_altura(a->dir)) + 1;
}

int TAB_isArvoreAVL(TAB *a)
{
  int altura_esq = TAB_altura(a->esq);
  int altura_dir = TAB_altura(a->dir);
  if ((altura_esq - altura_dir) > abs(1))
    return 0;
  else
    return 1;
}

int calcula_balanceamento(TAB *a)
{
  int altura_esq = TAB_altura(a->esq);
  int altura_dir = TAB_altura(a->dir);
  return altura_esq - altura_dir;
}

int TAB_fator_balanceamento_no(TAB *a, int elem)
{
  TAB *no = TAB_busca(a, elem);
  int fator_balanceamento = calcula_balanceamento(no);
  return fator_balanceamento;
}

// FUNCAO 2 DO CONTADOR, FUNCIONANDO CORRETAMENTE
int TAB_soma_nos_folhas(TAB *a, int soma)
{
  if (a)
  {

    soma = TAB_soma_nos_folhas(a->esq, soma);
    soma += a->info;
    soma = TAB_soma_nos_folhas(a->dir, soma);
  }
  return soma;
}

int TAB_altura_no(TAB *a, int elem)
{
  TAB *no = TAB_busca(a, elem);
  int altura = TAB_altura(no);
  return altura;
}
