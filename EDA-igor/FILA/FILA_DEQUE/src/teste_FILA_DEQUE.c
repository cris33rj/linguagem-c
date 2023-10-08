#include "FILA_DEQUE.h"
#include <string.h>
#include <ctype.h>

int main(void)
{
  FILA_DEQUE *f = FILA_DEQUE_inicializa();
  printf("Insira caracteres na fila. Digite um numero para sair...\n");
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
  printf("\n");
  char fim = FILA_DEQUE_fim(f);
  printf("o fim da fila eh: %c\n", fim);
  printf("\n");
  char inicio = FILA_DEQUE_inicio(f);
  printf("o inicio da fila eh: %c\n", inicio);
  printf("\n");

  char retirado = FILA_DEQUE_retira(f);
  printf("elemento retirado eh %c\n", retirado);
  printf("\n");

  printf("Imprimindo fila após retirada do elemento %c\n", retirado);
  FILA_DEQUE_imprime(f);
  printf("\n");
  char fim2 = FILA_DEQUE_fim(f);
  printf("o fim da fila eh: %c\n", fim2);
  printf("\n");
  char inicio2 = FILA_DEQUE_inicio(f);
  printf("o inicio da fila eh: %c\n", inicio2);
  printf("\n");

  char retirado2 = FILA_DEQUE_retira(f);
  printf("elemento retirado eh %c\n", retirado2);
  printf("\n");

  printf("Imprimindo fila após retirada do elemento %c\n", retirado2);
  FILA_DEQUE_imprime(f);
  printf("\n");
  char fim3 = FILA_DEQUE_fim(f);
  printf("o fim da fila eh: %c\n", fim3);
  printf("\n");
  char inicio3 = FILA_DEQUE_inicio(f);
  printf("o inicio da fila eh: %c\n", inicio3);
  printf("\n");

  FILA_DEQUE_libera(f);
  return 0;
}
