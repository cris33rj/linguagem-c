#include "FILA2P.h"
#include <string.h>
#include <ctype.h>

int main(void)
{
  FILA2P *f = FILA2P_inicializa();
  printf("Insira caracteres na fila. Informe um numero para sair...\n");
  do
  {
    char letra;
    scanf(" %c", &letra);
    if (!isalpha(letra))
      break;
    FILA2P_insere(f, letra);
  } while (1);
  printf("\n");

  printf("Vai chamar o metodo fila2p_imprime\n");
  FILA2P_imprime(f);

  printf("\n");

  char inicio = FILA2P_inicio(f);
  printf("o inicio da fila eh: %c\n", inicio);

  printf("\n");

  char retirado = FILA2P_retira(f);
  printf("elemento retirado eh %c\n", retirado);

  printf("\n");

  printf("Imprimindo fila após retirada do elemento %c\n", retirado);
  FILA2P_imprime(f);

  printf("\n");

  char inicio2 = FILA2P_inicio(f);
  printf("o inicio da fila eh: %c\n", inicio2);

  printf("\n");

  char retirado2 = FILA2P_retira(f);
  printf("elemento retirado eh %c\n", retirado2);

  printf("\n");

  printf("Imprimindo fila após retirada do elemento %c\n", retirado2);
  FILA2P_imprime(f);

  printf("\n");

  char inicio3 = FILA2P_inicio(f);
  printf("o inicio da fila eh: %c\n", inicio3);

  printf("\n");

  FILA2P_libera(f);
}
