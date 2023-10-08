#include "PILHA_DEQUE.h"
#include "FILA_DEQUE.h"
#include <string.h>
#include <ctype.h>

void inverte_com_duas_filas(FILA_DEQUE *f)
{
  FILA_DEQUE *f1 = FILA_DEQUE_inicializa();
  FILA_DEQUE *f2 = FILA_DEQUE_inicializa();
  while (!FILA_DEQUE_vazia(f))
  {
    FILA_DEQUE_insere(f2, FILA_DEQUE_retira(f));
    while (!FILA_DEQUE_vazia(f1))
    {
      FILA_DEQUE_insere(f2, FILA_DEQUE_inicio(f1));
      FILA_DEQUE_retira(f1);
    }
    FILA_DEQUE *q = FILA_DEQUE_inicializa();
    q = f1;
    f1 = f2;
    f2 = q;
  }
  while (!FILA_DEQUE_vazia(f1))
  {
    FILA_DEQUE_insere(f, FILA_DEQUE_retira(f1));
  }
}

void inverte_com_uma_pilha(FILA_DEQUE *f)
{
  PILHA_DEQUE *p_aux = PILHA_DEQUE_inicializa();
  while (!FILA_DEQUE_vazia(f))
  {
    PILHA_DEQUE_push(p_aux, FILA_DEQUE_retira(f));
  }

  while (!PILHA_DEQUE_vazia(p_aux))
  {
    FILA_DEQUE_insere(f, PILHA_DEQUE_pop(p_aux));
  }
}

int main(void)
{
  FILA_DEQUE *f = FILA_DEQUE_inicializa();
  // TP *p2 = FILA_DEQUE_inicializa();
  printf("Insira elementos maiores ou iguais a zero para inclusao na fila...\n");
  do
  {
    char letra;
    scanf(" %c", &letra);
    if (!isalpha(letra))
      break;
    FILA_DEQUE_insere(f, letra);
  } while (1);
  // prinfila_deque("Antes de ordenar...\n");

  printf("\n");
  FILA_DEQUE_imprime(f);
  char fim = FILA_DEQUE_fim(f);
  printf("o fim da fila eh: %c\n", fim);
  char inicio = FILA_DEQUE_inicio(f);
  printf("o inicio da fila eh: %c\n", inicio);

  printf("\n");

  inverte_com_uma_pilha(f);
  printf("Imprimindo fila invertida com uso de uma pilha\n");
  FILA_DEQUE_imprime(f);
  printf("\n");

  printf("\n");

  inverte_com_duas_filas(f);
  printf("Imprimindo fila invertida com uso de duas filas\n");
  FILA_DEQUE_imprime(f);
  printf("\n");

  return 0;
}