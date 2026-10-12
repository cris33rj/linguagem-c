#include "TABHASH.h"

int main()
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
      printf("Digite o id e o peso do paciente...\n");
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
        printf("%d\t%.2f\n", p->id, p->peso);
      break;
    case 3:
      printf("Digite o id a ser removido... ");
      scanf("%d", &id);
      TA *p_existe = TABHASH_busca(tabela, id);
      if (!p_existe)
        printf("Elemento nao encontrado!\n");
      else
      {
        peso = TABHASH_retira(tabela, id);
        if (peso != -1)
          printf("%d\t%.2f saiu\n", id, peso);
      }
      break;
    case 4:
      TABHASH_imprime(tabela);
      break;
    default:
      printf("Opcao invalida!\n");
    }
  } while (opcao != 0);

  return 0;
}
