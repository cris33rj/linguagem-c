#include "FILA2P.h"
#include <string.h>
#include <ctype.h>

int main(void)
{
  FILA2P *f = FILA2P_inicializa();
  // TP *p2 = FILA2P_inicializa();
  printf("Insira caracteres na fila...\n");
  do
  {
    char letra;
    scanf(" %c", &letra);
    if (!isalpha(letra))
      break;
    FILA2P_insere(f, letra);
  } while (1);
  // prinfila2p("Antes de ordenar...\n");

  printf("Vai chamar o metodo fila2p_imprime\n");
  FILA2P_imprime(f);
  printf("passou pelo metodo fila2p_imprime\n");

  char inicio = FILA2P_inicio(f);
  printf("o inicio da fila eh: %c\n", inicio);

  char retirado = FILA2P_retira(f);
  printf("elemento retirado eh %c\n", retirado);

  printf("Imprimindo fila após retirada do elemento %c\n", retirado);
  FILA2P_imprime(f);

  char inicio2 = FILA2P_inicio(f);
  printf("o inicio da fila eh: %c\n", inicio2);

  char retirado2 = FILA2P_retira(f);
  printf("elemento retirado eh %c\n", retirado2);

  printf("Imprimindo fila após retirada do elemento %c\n", retirado2);
  FILA2P_imprime(f);

  char inicio3 = FILA2P_inicio(f);
  printf("o inicio da fila eh: %c\n", inicio3);

  printf("foi ate o final\n");
}
