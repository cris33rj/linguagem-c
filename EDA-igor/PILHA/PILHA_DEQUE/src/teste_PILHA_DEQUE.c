#include "PILHA_DEQUE.h"
#include <string.h>
#include <ctype.h>

int main(void)
{
  PILHA_DEQUE *p = PILHA_DEQUE_inicializa();
  // PILHA_DEQUE *p2 = PILHA_DEQUE_inicializa();
  printf("Insira caracteres na pilha ou informe um numero para sair...\n");
  do
  {
    char letra;
    scanf(" %c", &letra);
    if (!isalpha(letra))
      break;
    PILHA_DEQUE_push(p, letra);
  } while (1);
  // printf("Antes de ordenar...\n");

  printf("\n");
  PILHA_DEQUE_imprime(p);
  char topo = PILHA_DEQUE_topo(p);
  printf("o topo eh %c\n", topo);

  printf("\n");

  char retirado = PILHA_DEQUE_pop(p);
  printf("elemento retirado eh %c\n", retirado);

  printf("\n");

  printf("Imprimindo pilha após retirada do elemento %c\n", retirado);
  PILHA_DEQUE_imprime(p);

  printf("\n");

  char topo2 = PILHA_DEQUE_topo(p);
  printf("o topo agora eh %c\n", topo2);

  printf("\n");

  char retirado2 = PILHA_DEQUE_pop(p);
  printf("elemento retirado eh %c\n", retirado2);

  printf("\n");

  printf("Imprimindo pilha após retirada do elemento %c\n", retirado2);
  PILHA_DEQUE_imprime(p);

  printf("\n");

  char topo3 = PILHA_DEQUE_topo(p);
  printf("o topo agora eh %c\n", topo3);

  printf("\n");

  PILHA_DEQUE_libera(p);
  return 0;
}
