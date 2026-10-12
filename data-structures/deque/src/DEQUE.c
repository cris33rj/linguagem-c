#include "DEQUE.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

DEQUE *DEQUE_inicializa(void)
{
  DEQUE *f = (DEQUE *)malloc(sizeof(DEQUE));
  f->tam = 1;
  f->vet = (char *)malloc(sizeof(char) * f->tam);
  f->n = f->ini = 0;
  return f;
}

int DEQUE_vazia(DEQUE *f)
{
  return f->n == 0;
}

int incr(int ind, int n)
{
  return (ind + 1) % n;
}

char DEQUE_remove_inicio(DEQUE *f)
{
  if (DEQUE_vazia(f))
    exit(1);
  char resp = f->vet[f->ini];
  f->ini = incr(f->ini, f->tam);
  f->n--;
  return resp;
}

char DEQUE_inicio(DEQUE *f)
{
  if (DEQUE_vazia(f))
    exit(1);
  char resp = f->vet[f->ini];
  return resp;
}

char DEQUE_remove_fim(DEQUE *f)
{
  int ult = (f->ini + f->n - 1) % f->tam;
  char v = f->vet[ult];
  f->n--;
  return v;
}

char DEQUE_fim(DEQUE *f)
{
  int ult = (f->ini + f->n - 1) % f->tam;
  char v = f->vet[ult];
  return v;
}

void DEQUE_libera(DEQUE *f)
{
  free(f->vet);
  free(f);
}

void DEQUE_insere_fim(DEQUE *f, char x)
{
  if (f->n == f->tam)
  {
    char *vet = (char *)malloc(sizeof(char) * f->n * 2);
    int i = f->ini, j = 0;
    while (j < f->n)
    {
      vet[j++] = f->vet[i];
      i = incr(i, f->tam);
    }
    f->ini = 0;
    f->tam *= 2;
    char *aux = f->vet;
    f->vet = vet;
    free(aux);
  }
  int fim = (f->ini + f->n++) % f->tam;
  f->vet[fim] = x;
}

void DEQUE_insere_inicio(DEQUE *f, char x)
{
  if (f->n == f->tam)
  {
    f->tam *= 2;
    f->vet = (char *)realloc(f->vet, f->tam * sizeof(char));
    if (f->ini != 0)
    {
      memmove(&f->vet[f->tam - f->n + f->ini],
              &f->vet[f->ini],
              (f->n - f->ini) * sizeof(char));
      f->ini = f->tam - f->n + f->ini;
    }
  }
  f->ini = (f->ini - 1 + f->tam) % f->tam;
  f->vet[f->ini] = x;
  f->n++;
}

void DEQUE_imprime(DEQUE *f)
{
  int ind = f->ini, i;
  for (i = 0; i < f->n; i++)
  {
    printf("%d -> %c\n", i + 1, f->vet[ind]);
    ind = incr(ind, f->tam);
  }
}
