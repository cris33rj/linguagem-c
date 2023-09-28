#include "TF.h"
#include <string.h>
#include <ctype.h>
/*
 typedef struct pilha TP;
 TP *TF_inicializa (void);
 void TF_push (TP *p, int v);
 int TF_pop (TP *p);
 int TF_vazia (TP *p);
 void TF_libera (TP *p);
*/

/* void ordena(TF * f)
{
  tf *aux = TF_inicializa(), *q = TF_inicializa();
  while (!TF_vazia(p))
    TF_push(aux, TF_pop(p));
  while (!TF_vazia(aux))
  {
    int maior = TF_pop(aux);
    while (!TF_vazia(aux))
    {
      int x = TF_pop(aux);
      if (x <= maior)
        TF_push(q, x);
      else
      {
        TF_push(q, maior);
        maior = x;
      }
    }
    TF_push(p, maior);
    while (!TF_vazia(q))
      TF_push(aux, TF_pop(q));
  }
  TF_libera(aux);
  TF_libera(q);
}
 */
int main(void)
{
  TF *f = TF_inicializa();
  // TP *p2 = TF_inicializa();
  printf("Insira elementos maiores ou iguais a zero para inclusao na fila...\n");
  do
  {
    char letra;
    scanf(" %c", &letra);
    if (!isalpha(letra))
      break;
    TF_insere(f, letra);
  } while (1);
  // printf("Antes de ordenar...\n");

  TF_imprime(f);
  char fim = TF_fim(f);
  printf("o fim da fila eh: %c\n", fim);
  char inicio = TF_inicio(f);
  printf("o inicio da fila eh: %c\n", inicio);

  char retirado = TF_retira(f);
  printf("elemento retirado eh %c\n", retirado);

  printf("Imprimindo fila após retirada do elemento %c\n", retirado);
  TF_imprime(f);
  char fim2 = TF_fim(f);
  printf("o fim da fila eh: %c\n", fim2);
  char inicio2 = TF_inicio(f);
  printf("o inicio da fila eh: %c\n", inicio2);
  /* printf("Criando segunda pilha\n");
  do
  {
    int n2;
    scanf("%d", &n2);
    if (n2 < 0)
      break;
    TF_push(p2, n2);
  } while (1);
  TF_imprime(p2);

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
  printf("\n");  */

  /* ordena(p);
  printf("Depois de ordenar...\n");
  TF_imprime(p);


  int topo = TF_topo(p);
  printf("Topo=%d\n", topo);
  TF_imprime(p);

  TF_concatena(p, p2);

  printf("vai copiar\n");
  TP *copia = TF_copia_com_pilha_auxiliar(p);
  printf("vai imprimir copia\n");
  TF_imprime(copia); */

  /*  printf("vai copiar\n");
   TP *copia = TF_copia_com_recursao(p);
   printf("vai imprimir copia\n");
   TF_imprime(copia);


  TP *stack_from_queue = f2p(f1);
  printf("imprimindo pilha a partir da fila 1\n");
  TF_imprime(stack_from_queue);
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


  TF_retira_pares(p);
  printf("imprimindo a pilha sem os pares\n");
  TF_imprime(p);  */

  /* TF *queue_from_stack = TF_p2f(p);
  printf("imprimindo fila criada a partir da pilha\n");
  TF_imprime(queue_from_stack);
  printf("\n");
  printf("imprimindo pilha original\n");
  TF_imprime(p);
 */
  // TF_libera(p);
  return 0;
}
