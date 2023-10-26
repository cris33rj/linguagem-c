#include "TABHASH.h"

/* int main(void)
{
  int n;
  printf("Digite n (quantidade de ids)... ");
  scanf("%d", &n);

  if ((n <= 1) || (n > TAM_VET))
    return 0;

  TABHASH tabela;
  TABHASH_inicializa(tabela);

  int i, id;
  float peso;
  for (i = 0; i < n; i++)
  {
    printf("Digite o id e o peso...\n");
    scanf("%d", &id);
    scanf("%f", &peso);
    TABHASH_insere(tabela, id, peso);
  }
  TABHASH_imprime(tabela);

  char resp;
  do
  {
    printf("Digite o id a ser removido... ");
    scanf("%d", &id);
    peso = TABHASH_retira(tabela, id);
    if (peso != -1)
      printf("%d\t%f saiu\n", id, peso);
    printf("Quer continuar? ");
    scanf(" %c", &resp);
  } while ((resp != 'N') && (resp != 'n'));
  TABHASH_imprime(tabela);

  do
  {
    printf("Digite o id a ser procurado... ");
    scanf("%d", &id);
    TA *p = TABHASH_busca(tabela, id);
    if (!p)
      printf("Elemento nao encontrado!\n");
    else
      printf("%d\t%f\n", p->id, p->peso);
    printf("Quer continuar? ");
    scanf(" %c", &resp);
  } while ((resp != 'N') && (resp != 'n'));
  TABHASH_imprime(tabela);

  TABHASH_libera(tabela);
  return 0;
} */

/* int main()
{

  int opcao, id;
  float peso;
  TABHASH tabela;
  TABHASH_inicializa(tabela);

  do
  {
    printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 -Deletar\n\t4 -Imprimir\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      printf("Digite o id e o peso...\n");
      scanf("%d", &id);
      scanf("%f", &peso);
      TABHASH_insere(tabela, id, peso);
      break;
    case 2:
      printf("Digite o id a ser procurado... ");
      scanf("%d", &id);
      TA *p = TABHASH_busca(tabela, id);
      if (!p)
        printf("Elemento nao encontrado!\n");
      else
        printf("%d\t%f\n", p->id, p->peso);
      break;
    case 3:
      printf("Digite o id a ser removido... ");
      scanf("%d", &id);
      peso = TABHASH_retira(tabela, id);
      if (peso != -1)
        printf("%d\t%f saiu\n", id, peso);
      break;
    case 4:
      TABHASH_imprime(tabela);
      break;
    default:
      printf("Opcao invalida!\n");
    }
  } while (opcao != 0);

  return 0;
} */
