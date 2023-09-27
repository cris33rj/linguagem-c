#include "DEQUE.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

DEQUE *DEQUE_inicializa(void)
{
  DEQUE *f = (DEQUE *)malloc(sizeof(DEQUE));
  f->tam = 1;
  f->vet = (int *)malloc(sizeof(int) * f->tam);
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

int DEQUE_retira_inicio(DEQUE *f)
{
  if (DEQUE_vazia(f))
    exit(1);
  int resp = f->vet[f->ini];
  f->ini = incr(f->ini, f->tam);
  f->n--;
  return resp;
}

int DEQUE_retira_fim(DEQUE *f)
{
  int ult = (f->ini + f->n - 1) % f->tam; // í n d i c e do ú l t im o
  int v = f->vet[ult];
  f->n--;
  return v;
}

void DEQUE_libera(DEQUE *f)
{
  free(f->vet);
  free(f);
}

void DEQUE_insere_fim(DEQUE *f, int x)
{
  // printf("vai inserir %d\n", x);
  if (f->n == f->tam)
  {
    // printf("n atingiu o mesmo valor de f->tam que eh %d\n", f->tam);
    int *vet = (int *)malloc(sizeof(int) * f->n * 2);
    int i = f->ini, j = 0;
    // printf("i=%d que vai ser usado no while, comeca valendo f->ini= %d\n", i, f->ini);
    while (j < f->n)
    {
      // printf("entrou no while\n");
      // printf("j=%d e f->n = %d\n", j, f->n);
      vet[j++] = f->vet[i];
      // printf("copiando %d para vetor duplicado na posicao vet[%d]\n", f->vet[i], j - 1);
      // printf("proxima posicao do i = (%d+1)%%%d==%d\n", i, f->tam, (i + 1) % f->tam);
      i = incr(i, f->tam);
      // printf("j agora eh %d\n", j);
    }
    f->ini = 0;
    f->tam *= 2;
    int *aux = f->vet;
    f->vet = vet;
    free(aux);
  }
  // printf("vai calcular a posicao fim para inserir %d que eh (%d+%d)%%%d=%d\n", x, f->ini, (f->n), f->tam, (f->ini + f->n) % f->tam);
  int fim = (f->ini + f->n++) % f->tam;
  f->vet[fim] = x;
}

void DEQUE_insere_inicio(DEQUE *f, int x)
{
  printf("vai inserir %d\n", x);
  if (f->n == f->tam)
  {
    printf("n atingiu o mesmo valor de f->tam que eh %d\n", f->tam);
    f->tam *= 2;
    printf("Vai fazer realloc aumentando tamanho para %d\n", f->tam);
    f->vet = (int *)realloc(f->vet, f->tam * sizeof(int));
    printf("=============================>%d\n", f->ini);
    if (f->ini != 0)
    {
      printf("f->ini diferente de zero = %d\n", f->ini);
      printf("Vai mover bloco de memoria comecando em vet[f->ini}->vet[%d]==%d para f->vet[f->tam - f->ini]-> vet[%d-%d]=%d\n", f->ini, f->vet[f->ini], f->tam, f->ini, f->vet[f->tam - f->ini]);
      printf("f->n eh %d\n", f->n);
      memmove(&f->vet[f->tam - f->n + f->ini],
              &f->vet[f->ini],
              (f->n - f->ini) * sizeof(int));
      f->ini = f->tam - f->n + f->ini;
    }
  } /* decrementa ( c i rc u l a rm e n t e ) í n d i c e de i n í c i o */
  printf("f-->ini = (f-->ini - 1 + f-->tam) %% f-->tam = (%d-1+%d)%%%d=%d\n", f->ini, f->tam, f->tam, (f->ini - 1 + f->tam) % f->tam);
  f->ini = (f->ini - 1 + f->tam) % f->tam;
  printf("vai inserir %d em vet[%d]\n", x, f->ini);
  f->vet[f->ini] = x;
  f->n++;
  printf("%d\n", f->vet[0]);
  printf("%d\n", f->vet[1]);
  printf("%d\n", f->vet[2]);
  printf("%d\n", f->vet[3]);
  printf("\n");
  /* printf("novo ini = (f->ini + f->n++)%%f->tam===>(%d+%d)%%%d=%d\n", f->ini, f->n, f->tam, (f->ini + f->n) % f->tam);
   ini = (f->ini - 1 + f->tam) % f->tam;
  printf("ini calculado para inserir x: %d\n", ini);
  f->vet[ini] = x;
  f->n++; */
}

void DEQUE_imprime(DEQUE *f)
{
  int ind = f->ini, i;
  for (i = 0; i < f->n; i++)
  {
    printf("%d -> %d\n", i + 1, f->vet[ind]);
    ind = incr(ind, f->tam);
  }
}

/* void DEQUE_insere_inicio(DEQUE *f, int x)
{
  printf("vai inserir %d\n", x);
  if (f->n == f->tam)
  {
    printf("n atingiu o mesmo valor de f->tam que eh %d\n", f->tam);
    f->tam *= 2;
    printf("Vai fazer realloc aumentando tamanho para %d\n", f->tam);
    f->vet = (int *)realloc(f->vet, f->tam * sizeof(int));
    printf("=============================>%d\n", f->ini);
    if (f->ini != 0)
    {
      printf("f->ini diferente de zero = %d\n", f->ini);
      printf("Vai mover bloco de memoria comecando em vet[f->ini}->vet[%d]==%d para f->vet[f->tam - f->ini]-> vet[%d-%d]=%d\n", f->ini, f->vet[f->ini], f->tam, f->ini, f->vet[f->tam - f->ini]);
      memmove(&f->vet[f->tam - f->ini],
              &f->vet[f->ini],
              (f->n - f->ini) * sizeof(int));
    }
  }
printf("f-->ini = (f-->ini - 1 + f-->tam) %% f-->tam = (%d-1+%d)%%%d=%d\n", f->ini, f->tam, f->tam, (f->ini - 1 + f->tam) % f->tam);
f->ini = (f->ini - 1 + f->tam) % f->tam;
printf("vai inserir %d em vet[%d]\n", x, f->ini);
f->vet[f->ini] = x;
f->n++;
printf("novo ini = (f->ini + f->n++)%%f->tam===>(%d+%d)%%%d=%d\n", f->ini, f->n, f->tam, (f->ini + f->n) % f->tam);
ini = (f->ini - 1 + f->tam) % f->tam;
printf("ini calculado para inserir x: %d\n", ini);
f->vet[ini] = x;
f->n++;
}
 */