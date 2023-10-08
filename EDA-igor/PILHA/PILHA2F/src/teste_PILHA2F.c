#include "PILHA2F.h"
#include <string.h>
#include <ctype.h>

int main(void)
{
  PILHA2F *p = PILHA2F_inicializa();
  printf("Insira caracteres na pilha. Para sair digite um numero\n");
  do
  {
    char letra;
    scanf(" %c", &letra);
    if (!isalpha(letra))
      break;
    PILHA2F_push(p, letra);
  } while (1);

  printf("\n");

  PILHA2F_imprime(p);
  printf("\n");

  char inicio = PILHA2F_topo(p);
  printf("o topo da fila eh: %c\n", inicio);
  printf("\n");

  char retirado = PILHA2F_pop(p);
  printf("elemento retirado eh %c\n", retirado);

  printf("\n");

  printf("Imprimindo pilha após retirada do elemento %c\n", retirado);
  PILHA2F_imprime(p);

  printf("\n");

  char inicio2 = PILHA2F_topo(p);
  printf("o topo da pilha eh: %c\n", inicio2);

  printf("\n");

  char retirado2 = PILHA2F_pop(p);
  printf("elemento retirado eh %c\n", retirado2);

  printf("\n");

  printf("Imprimindo pilha após retirada do elemento %c\n", retirado2);
  PILHA2F_imprime(p);

  printf("\n");

  char inicio3 = PILHA2F_topo(p);
  printf("o topo da pilha eh: %c\n", inicio3);

  PILHA2F_libera(p);
}
