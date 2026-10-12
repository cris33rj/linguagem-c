#include "TABB.h"
#include "limits.h"

TABB *TABB_inicializa(void)
{
  return NULL;
}

TABB *TABB_cria(int raiz, TABB *esq, TABB *dir)
{
  TABB *novo = (TABB *)malloc(sizeof(TABB));
  novo->info = raiz;
  novo->esq = esq;
  novo->dir = dir;
  return novo;
}

void TABB_imp_pre(TABB *a)
{
  if (a)
  {
    printf("%d ", a->info);
    TABB_imp_pre(a->esq);
    TABB_imp_pre(a->dir);
  }
}

void TABB_imp_pos(TABB *a)
{
  if (a)
  {
    TABB_imp_pos(a->esq);
    TABB_imp_pos(a->dir);
    printf("%d ", a->info);
  }
}

void TABB_imp_sim(TABB *a)
{
  if (a)
  {
    TABB_imp_sim(a->esq);
    printf("%d ", a->info);
    TABB_imp_sim(a->dir);
  }
}

void imp_aux(TABB *a, int andar)
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

void TABB_imp_ident(TABB *a)
{
  imp_aux(a, 0);
}

void TABB_libera(TABB *a)
{
  if (a)
  {
    TABB_libera(a->esq);
    TABB_libera(a->dir);
    free(a);
  }
}

TABB *TABB_busca(TABB *a, int elem)
{
  if ((!a) || (a->info == elem))
    return a;
  if (a->info > elem)
    return TABB_busca(a->esq, elem);
  return TABB_busca(a->dir, elem);
}

TABB *TABB_insere(TABB *a, int elem)
{
  if (!a)
    return TABB_cria(elem, NULL, NULL);
  if (a->info > elem)
    a->esq = TABB_insere(a->esq, elem);
  else if (a->info < elem)
    a->dir = TABB_insere(a->dir, elem);
  return a;
}

TABB *TABB_retira(TABB *a, int info)
{
  if (!a)
    return a;
  if (info < a->info)
    a->esq = TABB_retira(a->esq, info);
  else if (info > a->info)
    a->dir = TABB_retira(a->dir, info);
  else
  { // info encontrada
    if ((!a->esq) && (!a->dir))
    { // CASO (1)
      free(a);
      a = NULL;
    }
    else if ((!a->esq) || (!a->dir))
    { // CASO (2)
      TABB *temp = a;
      if (!a->esq)
        a = a->dir;
      else
        a = a->esq;
      free(temp);
    }
    else
    { // CASO (3)
      TABB *filho = a->esq;
      while (filho->dir)
        filho = filho->dir;
      a->info = filho->info;
      filho->info = info;
      a->esq = TABB_retira(a->esq, info);
    }
  }
  return a;
}

TABB *TABB_retira_impares(TABB *a)
{

  if (!a)
    return NULL;

  TABB_retira_impares(a->esq);
  TABB_retira_impares(a->dir);

  if (a)
  {
    if (a->esq && a->esq->info % 2 != 0 && (a->esq->esq == NULL && a->esq->dir == NULL))
    {
      free(a->esq);
      a->esq = NULL;
    }
    if (a->dir && a->dir->info % 2 != 0 && (a->dir->esq == NULL && a->dir->dir == NULL))
    {
      free(a->dir);
      a->dir = NULL;
    }
  }

  if (a && a->info % 2 != 0 && a->esq != NULL)
  {
    TABB *temp = a;
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

  if (a && a->info % 2 != 0 && a->dir != NULL)
  {
    TABB *temp = a;
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

/* TABB *TABB_maior(TABB *a)
{
  TABB *maior;
  while (a->dir)
  {
    maior = a->dir;
    a = a->dir;
  }
  return maior;
} */

TABB *TABB_maior(TABB *a)
{
  if (!a)
    return a;
  if (a->dir)
    return TABB_maior(a->dir);
  else
    return a;
}

TABB *TABB_menor(TABB *a)
{
  if (!a)
    return a;
  if (a->esq)
    return TABB_menor(a->esq);
  else
    return a;
}

int TABB_mN_recursivo(TABB *a, int *menores, int index, int N)
{
  if (!a)
    return index;
  index = TABB_mN_recursivo(a->esq, menores, index, N);
  if (a->info < N)
  {
    menores[index++] = a->info;
  }
  index = TABB_mN_recursivo(a->dir, menores, index, N);
  return index;
}

// FUNCAO 1 DO CONTADOR, FUNCIONANDO CORRETAMENTE
int TABB_quant_nos(TABB *a)
{
  if (!a)
    return 0;
  return 1 + TABB_quant_nos(a->esq) + TABB_quant_nos(a->dir);
}

// FUNCAO 2 DO CONTADOR, FUNCIONANDO CORRETAMENTE
int TABB_quant_nos_2(TABB *a, int contador)
{
  if (a)
  {

    contador = TABB_quant_nos_2(a->esq, contador);
    contador++;
    contador = TABB_quant_nos_2(a->dir, contador);
  }
  return contador;
}

// FUNCAO ALTERNATIVA DO CONTADOR 2. NUNCA VAI DAR SE TIVER UM CASO BASE RETORNANDO 0 OU 1. PRA EFEITO DE CONTAGEM, SEMPRE TEM DE COMEÇAR ASSIM
// IF (a){...}
/* int TABB_quant_nos_2(TABB *a, int contador)
{
  if (!a)
  {
    printf("a eh nulo. vai retornar 1\n");
    return 1;
  }

  printf("Vai para a esquerda de %d\n", a->info);
  contador = TABB_quant_nos_2(a->esq, contador);
  contador++;
  printf("Valor de contador que  depois de contador++ ---> %d\n", contador);
  printf("Vai para a direita de %d\n", a->info);
  contador = TABB_quant_nos_2(a->dir, contador);

  printf("Valor de contador que NO FINAL DA FUNCAO ---> %d\n", contador);
  return contador;
} */

// Fiz com base em https://stackoverflow.com/questions/64847529/function-to-create-array-of-post-order-binary-tree
int *TABB_mN(TABB *a, int N)
{
  int *menores = malloc(sizeof(int) * TABB_quant_nos(a));
  TABB_mN_recursivo(a, menores, 0, N);
  return menores;
}
