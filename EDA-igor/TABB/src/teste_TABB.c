#include "TABB.h"

int main(void)
{
  TABB *a = TABB_inicializa();
  int n;

  while (1)
  {
    scanf("%d", &n);
    if (n < 0)
      break;
    a = TABB_insere(a, n);
  }

  TABB_imp_ident(a);

  /* TABB *sem_impares = TABB_retira_impares(a);
  printf("Imprimindo sem impares");
  TABB_imp_ident(sem_impares); */

  /* TABB_retira(a, 57);
  TABB_retira(a, 99);
  TABB_retira(a, 85);
  TABB_retira(a, 175);
  TABB_retira(a, 75); */

  /* TABB *maior = TABB_maior(a);
  printf("Imprimindo valor de maior -->%d", maior->info);

  TABB *menor = TABB_menor(a);
  printf("Imprimindo valor de menor -->%d", menor->info); */

  int size = TABB_quant_nos(a);
  int *menores = TABB_mN(a, 300);
  for (int i = 0; i < size; i++)
  {
    printf("%d ", menores[i]);
  }

  // TABB_libera(a);
  return 0;
}
