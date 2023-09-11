#include "TP.h"
#include "TF.h"

/*
 typedef struct pilha TP;
 TP *TP_inicializa (void);
 void TP_push (TP *p, int v);
 int TP_pop (TP *p);
 int TP_vazia (TP *p);
 void TP_libera (TP *p);
*/

void ordena(TP *p)
{
  TP *aux = TP_inicializa(), *q = TP_inicializa();
  while (!TP_vazia(p))
    TP_push(aux, TP_pop(p));
  while (!TP_vazia(aux))
  {
    int maior = TP_pop(aux);
    while (!TP_vazia(aux))
    {
      int x = TP_pop(aux);
      if (x <= maior)
        TP_push(q, x);
      else
      {
        TP_push(q, maior);
        maior = x;
      }
    }
    TP_push(p, maior);
    while (!TP_vazia(q))
      TP_push(aux, TP_pop(q));
  }
  TP_libera(aux);
  TP_libera(q);
}

int main(void)
{
  TP *p = TP_inicializa();
  TP *p2 = TP_inicializa();
  printf("Insira elementos maiores ou iguais a zero para inclusao na pilha...\n");
  do
  {
    int n;
    scanf("%d", &n);
    if (n < 0)
      break;
    TP_push(p, n);
  } while (1);
  // printf("Antes de ordenar...\n");

  TP_imprime(p);

  printf("Criando segunda pilha\n");
  do
  {
    int n2;
    scanf("%d", &n2);
    if (n2 < 0)
      break;
    TP_push(p2, n2);
  } while (1);
  TP_imprime(p2);

  printf("Criando primeira fila 1\n");

  TF *f1 = TF_cria();

  if (TF_vazia(f1))
  {
    printf("\nFila vazia.");
  }

  TF_insere(f1, 1);

  if (!TF_vazia(f1))
  {
    printf("\nFila não TF_vazia.");
  }

  TF_insere(f1, 2);
  TF_insere(f1, 3);
  TF_insere(f1, 4);
  TF_insere(f1, 5);
  TF_insere(f1, 6);

  printf("imprimindo fila 1\n");
  TF_imprime(f1);

  printf("\n");
  printf("Criando primeira fila 2\n");

  TF *f2 = TF_cria();

  if (TF_vazia(f2))
  {
    printf("\nFila vazia.");
  }

  TF_insere(f2, 1);

  if (!TF_vazia(f2))
  {
    printf("\nFila não vazia.");
  }

  TF_insere(f2, 6);
  TF_insere(f2, 7);
  TF_insere(f2, 8);
  TF_insere(f2, 9);
  TF_insere(f2, 10);

  printf("imprimindo fila 2\n");
  TF_imprime(f2);
  printf("\n");

  /* ordena(p);
  printf("Depois de ordenar...\n");
  TP_imprime(p);


  int topo = TP_topo(p);
  printf("Topo=%d\n", topo);
  TP_imprime(p);

  TP_concatena(p, p2);

  printf("vai copiar\n");
  TP *copia = TP_copia_com_pilha_auxiliar(p);
  printf("vai imprimir copia\n");
  TP_imprime(copia); */

  /*  printf("vai copiar\n");
   TP *copia = TP_copia_com_recursao(p);
   printf("vai imprimir copia\n");
   TP_imprime(copia);


  TP *stack_from_queue = f2p(f1);
  printf("imprimindo pilha a partir da fila 1\n");
  TP_imprime(stack_from_queue);
  printf("\n");
  printf("imprimindo fila original\n");
  TF_imprime(f1);

  TF *fila_invertida = TF_inv_fila(f1);
  printf("imprimindo versao invertida da fila 1\n");
  TF_imprime(fila_invertida);
  printf("\n");
  printf("imprimindo fila original\n");
  TF_imprime(f1);

  TF *filas_juntas = TF_junta_filas(f1, f2);
  printf("Imprimindo fila 1 e fila 2 juntas\n");
  TF_imprime(filas_juntas);
  printf("\n");
  printf("imprimindo fila 1\n");
  TF_imprime(f1);
  printf("\n");
  printf("imprimindo fila 2\n");
  TF_imprime(f2);


  TP_retira_pares(p);
  printf("imprimindo a pilha sem os pares\n");
  TP_imprime(p);  */

  TF *queue_from_stack = TF_p2f(p);
  printf("imprimindo fila criada a partir da pilha\n");
  TF_imprime(queue_from_stack);
  printf("\n");
  printf("imprimindo pilha original\n");
  TP_imprime(p);

  // TP_libera(p);
  return 0;
}
