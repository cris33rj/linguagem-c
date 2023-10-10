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
  printf("\n");

  printf("Imprimindo a soma das folhas\n");
  int soma = TAB_soma_nos_folhas(a, 0);
  printf("A soma eh %d ", soma);

  printf("\n");

  printf("Imprimindo a arvore no percurso pós-ordem\n");
  TAB_imp_pos(a);

  printf("\n");

  printf("Imprimindo a arvore no percurso em-ordem\n");
  TAB_imp_sim(a);

  printf("\n");

  printf("Imprimindo a arvore no percurso pré-ordem\n");
  TAB_imp_pre(a);

  printf("\n");

  /*
    ======ATENCAO======
   Ao descomentar para testar essa operação, certifique-se de você inseriu na árvore o valor correto do nó a ser testado
    printf("Imprimindo a altura do no de numero 2\n");
   int altura_no = TAB_altura_no(a, 2);
   printf("A altura eh:  %d\n", altura_no); */

  printf("\n");

  /*
   ======ATENCAO======
   Ao descomentar para testar essa operação, certifique-se de você inseriu na árvore o valor correto do nó a ser testado
   printf("Imprimindo o fator de balanceamento de 5\n");
   int fator_balanceamento = TAB_fator_balanceamento_no(a, 5);
   printf("O fator de balanceamento eh:  %d\n", fator_balanceamento); */

  printf("\n");

  int produto_nos = TAB_produto_nos(a, 1);
  printf("O produto dos nos eh: %d\n", produto_nos);
  printf("\n");

  printf("Imprimindo em níveis\n");
  TAB_percurso_em_niveis(a);

  TAB_libera(a);
  return 0;
}
