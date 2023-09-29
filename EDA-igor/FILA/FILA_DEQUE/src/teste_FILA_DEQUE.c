#include "FILA_DEQUE.h"
#include <string.h>
#include <ctype.h>
/*
 typedef struct pilha TP;
 TP *FILA_DEQUE_inicializa (void);
 void FILA_DEQUE_push (TP *p, int v);
 int FILA_DEQUE_pop (TP *p);
 int FILA_DEQUE_vazia (TP *p);
 void FILA_DEQUE_libera (TP *p);
*/

/* void ordena(FILA_DEQUE * f)
{
  fila_deque *aux = FILA_DEQUE_inicializa(), *q = FILA_DEQUE_inicializa();
  while (!FILA_DEQUE_vazia(p))
    FILA_DEQUE_push(aux, FILA_DEQUE_pop(p));
  while (!FILA_DEQUE_vazia(aux))
  {
    int maior = FILA_DEQUE_pop(aux);
    while (!FILA_DEQUE_vazia(aux))
    {
      int x = FILA_DEQUE_pop(aux);
      if (x <= maior)
        FILA_DEQUE_push(q, x);
      else
      {
        FILA_DEQUE_push(q, maior);
        maior = x;
      }
    }
    FILA_DEQUE_push(p, maior);
    while (!FILA_DEQUE_vazia(q))
      FILA_DEQUE_push(aux, FILA_DEQUE_pop(q));
  }
  FILA_DEQUE_libera(aux);
  FILA_DEQUE_libera(q);
}
 */
int main(void)
{
  FILA_DEQUE *f = FILA_DEQUE_inicializa();
  // TP *p2 = FILA_DEQUE_inicializa();
  printf("Insira elementos maiores ou iguais a zero para inclusao na fila...\n");
  do
  {
    char letra;
    scanf(" %c", &letra);
    if (!isalpha(letra))
      break;
    FILA_DEQUE_insere(f, letra);
  } while (1);
  // prinfila_deque("Antes de ordenar...\n");

  FILA_DEQUE_imprime(f);
  char fim = FILA_DEQUE_fim(f);
  printf("o fim da fila eh: %c\n", fim);
  char inicio = FILA_DEQUE_inicio(f);
  printf("o inicio da fila eh: %c\n", inicio);

  char retirado = FILA_DEQUE_retira(f);
  printf("elemento retirado eh %c\n", retirado);

  printf("Imprimindo fila após retirada do elemento %c\n", retirado);
  FILA_DEQUE_imprime(f);
  char fim2 = FILA_DEQUE_fim(f);
  printf("o fim da fila eh: %c\n", fim2);
  char inicio2 = FILA_DEQUE_inicio(f);
  printf("o inicio da fila eh: %c\n", inicio2);

  char retirado2 = FILA_DEQUE_retira(f);
  printf("elemento retirado eh %c\n", retirado2);

  printf("Imprimindo fila após retirada do elemento %c\n", retirado2);
  FILA_DEQUE_imprime(f);
  char fim3 = FILA_DEQUE_fim(f);
  printf("o fim da fila eh: %c\n", fim3);
  char inicio3 = FILA_DEQUE_inicio(f);
  printf("o inicio da fila eh: %c\n", inicio3);

  /* prinfila_deque("Criando segunda pilha\n");
  do
  {
    int n2;
    scanf("%d", &n2);
    if (n2 < 0)
      break;
    FILA_DEQUE_push(p2, n2);
  } while (1);
  FILA_DEQUE_imprime(p2);

  prinfila_deque("Criando primeira fila 1\n");

  FILA_DEQUE *f1 = FILA_DEQUE_cria();

  if (FILA_DEQUE_vazia(f1))
  {
    prinfila_deque("\nFila vazia.");
  }

  FILA_DEQUE_insere(f1, 1);

  if (!FILA_DEQUE_vazia(f1))
  {
    prinfila_deque("\nFila não FILA_DEQUE_vazia.");
  }

  FILA_DEQUE_insere(f1, 2);
  FILA_DEQUE_insere(f1, 3);
  FILA_DEQUE_insere(f1, 4);
  FILA_DEQUE_insere(f1, 5);
  FILA_DEQUE_insere(f1, 6);

  prinfila_deque("imprimindo fila 1\n");
  FILA_DEQUE_imprime(f1);

  prinfila_deque("\n");
  prinfila_deque("Criando primeira fila 2\n");

  FILA_DEQUE *f2 = FILA_DEQUE_cria();

  if (FILA_DEQUE_vazia(f2))
  {
    prinfila_deque("\nFila vazia.");
  }

  FILA_DEQUE_insere(f2, 1);

  if (!FILA_DEQUE_vazia(f2))
  {
    prinfila_deque("\nFila não vazia.");
  }

  FILA_DEQUE_insere(f2, 6);
  FILA_DEQUE_insere(f2, 7);
  FILA_DEQUE_insere(f2, 8);
  FILA_DEQUE_insere(f2, 9);
  FILA_DEQUE_insere(f2, 10);

  prinfila_deque("imprimindo fila 2\n");
  FILA_DEQUE_imprime(f2);
  prinfila_deque("\n");  */

  /* ordena(p);
  prinfila_deque("Depois de ordenar...\n");
  FILA_DEQUE_imprime(p);


  int topo = FILA_DEQUE_topo(p);
  prinfila_deque("Topo=%d\n", topo);
  FILA_DEQUE_imprime(p);

  FILA_DEQUE_concatena(p, p2);

  prinfila_deque("vai copiar\n");
  TP *copia = FILA_DEQUE_copia_com_pilha_auxiliar(p);
  prinfila_deque("vai imprimir copia\n");
  FILA_DEQUE_imprime(copia); */

  /*  prinfila_deque("vai copiar\n");
   TP *copia = FILA_DEQUE_copia_com_recursao(p);
   prinfila_deque("vai imprimir copia\n");
   FILA_DEQUE_imprime(copia);


  TP *stack_from_queue = f2p(f1);
  prinfila_deque("imprimindo pilha a partir da fila 1\n");
  FILA_DEQUE_imprime(stack_from_queue);
  prinfila_deque("\n");
  prinfila_deque("imprimindo fila original\n");
  FILA_DEQUE_imprime(f1);

  FILA_DEQUE *fila_invertida = FILA_DEQUE_inv_fila(f1);
  prinfila_deque("imprimindo versao invertida da fila 1\n");
  FILA_DEQUE_imprime(fila_invertida);
  prinfila_deque("\n");
  prinfila_deque("imprimindo fila original\n");
  FILA_DEQUE_imprime(f1);

  FILA_DEQUE *filas_juntas = FILA_DEQUE_junta_filas(f1, f2);
  prinfila_deque("Imprimindo fila 1 e fila 2 juntas\n");
  FILA_DEQUE_imprime(filas_juntas);
  prinfila_deque("\n");
  prinfila_deque("imprimindo fila 1\n");
  FILA_DEQUE_imprime(f1);
  prinfila_deque("\n");
  prinfila_deque("imprimindo fila 2\n");
  FILA_DEQUE_imprime(f2);


  FILA_DEQUE_retira_pares(p);
  prinfila_deque("imprimindo a pilha sem os pares\n");
  FILA_DEQUE_imprime(p);  */

  /* FILA_DEQUE *queue_from_stack = FILA_DEQUE_p2f(p);
  prinfila_deque("imprimindo fila criada a partir da pilha\n");
  FILA_DEQUE_imprime(queue_from_stack);
  prinfila_deque("\n");
  prinfila_deque("imprimindo pilha original\n");
  FILA_DEQUE_imprime(p);
 */
  // FILA_DEQUE_libera(p);
  return 0;
}
