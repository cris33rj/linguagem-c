#include <string.h>
#include "TAB.h"

int main(void)
{
  int no, pai;
  printf("Digite a raiz da arvore... ");
  scanf("%d", &no);
  TAB *a = TAB_cria(no, NULL, NULL), *resp;
  char repete;
  do
  {
    char lado[2];
    printf("Quer continuar inserindo nos na árvore (digite N ou n para parar)? ");
    scanf(" %c", &repete);
    if ((repete == 'N') || (repete == 'n'))
      break;
    printf("Digite o pai (que deve existir), o filho a ser inserido na arvore e a posição E(ESQ) ou D(DIR)... ");
    scanf("%d%d%s", &pai, &no, lado);
    resp = TAB_busca(a, pai);
    if (!resp)
    {
      TAB_libera(a);
      return 0;
    }
    if (strcmp(lado, "E") == 0)
      resp->esq = TAB_cria(no, NULL, NULL);
    else
      resp->dir = TAB_cria(no, NULL, NULL);
  } while (1);
  TAB_imp_ident(a);
  printf("\n");

  /* TAB *copia = TAB_copia(a);
  printf("imprimindo copia\n");
  TAB_imp_ident(copia);

  TAB *espelho = TAB_espelho(a);
  printf("imprimindo espelho\n");
  TAB_imp_ident(espelho);
  */

  /* TAB *maior = TAB_maior(a);
  printf("O maior valor da arvore eh %d:\n", maior->info);

  TAB *menor = TAB_menor(a);
  printf("O menor valor da arvore eh %d:\n", menor->info);
 */
  /* TAB *copia = TAB_copia(a);
  printf("imprimindo copia\n");
  TAB_imp_ident(copia);

  int igual = TAB_igual(a, copia);
  if (igual == 1)
    printf("IGUAL A COPIA\n");
  else
    printf("DIFERENTE DE COPIA\n");

  TAB *espelho = TAB_espelho(a);
  printf("imprimindo espelho\n");
  TAB_imp_ident(espelho);

  int igual2 = TAB_igual(a, espelho);
  if (igual2 == 1)
    printf("IGUAL A ESPELHO\n");
  else
    printf("DIFERENTE DE ESPELHO\n");
 */

  TAB *sem_pares = TAB_retira_pares(a);
  printf("IMPRIMINDO SEM PARES\n");
  TAB_imp_ident(sem_pares);

  /* TAB *menor = TAB_menor(a);
  printf("O valor de menor eh %d:\n", menor->info); */

  // TAB_libera(a);

  return 0;
}
