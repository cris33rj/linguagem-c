#include <float.h>
#include "TABHASH.h"

void TABHASH_inicializa(TABHASH tabela)
{
  int i;
  for (i = 0; i < TAM_VET; i++)
    tabela[i] = NULL;
}

int TABHASH_hash(int id)
{
  return id % TAM_VET;
}

TA *TABHASH_aloca(int id, float peso)
{
  TA *novo = (TA *)malloc(sizeof(TA));
  novo->id = id;
  novo->peso = peso;
  novo->prox = NULL;
  return novo;
}

TA *TABHASH_busca(TABHASH tabela, int id)
{
  int h = TABHASH_hash(id);
  TA *p = tabela[h];
  while ((p) && (p->id != id))
    p = p->prox;
  return p;
}

void TABHASH_insere(TABHASH tabela, int id, float peso)
{
  int h = TABHASH_hash(id);
  TA *p = tabela[h], *ant = NULL;
  while ((p) && (p->id < id))
  {
    ant = p;
    p = p->prox;
  }
  if ((p) && (p->id == id))
  {
    p->peso = peso;
    return;
  }
  TA *novo = TABHASH_aloca(id, peso);
  novo->prox = p;
  if (!ant)
    tabela[h] = novo;
  else
    ant->prox = novo;
}

float TABHASH_retira(TABHASH tabela, int id)
{
  int h = TABHASH_hash(id);
  if (!tabela[h])
    return FLT_MIN;
  TA *p = tabela[h], *ant = NULL;
  float peso = FLT_MIN;
  while ((p) && (p->id < id))
  {
    ant = p;
    p = p->prox;
  }
  if ((!p) || (p->id != id))
    return peso;
  if (!ant)
    tabela[h] = p->prox;
  else
    ant->prox = p->prox;
  peso = p->peso;
  free(p);
  return peso;
}

void TABHASH_imprime(TABHASH tabela)
{
  int i;
  for (i = 0; i < TAM_VET; i++)
  {
    printf("%d: ", i);
    if (tabela[i])
    {
      TA *p = tabela[i];
      printf("\n");
      while (p)
      {
        printf("\t%d\t%.2f\n", p->id, p->peso);
        p = p->prox;
      }
    }
    else
      printf("NULL\n");
  }
}

void TABHASH_libera(TABHASH tabela)
{
  int i;
  for (i = 0; i < TAM_VET; i++)
    if (tabela[i])
    {
      TA *p = tabela[i], *q;
      while (p)
      {
        q = p;
        p = p->prox;
        free(q);
      }
    }
}