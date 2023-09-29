#include "PILHA_DEQUE.h"
#include <string.h>
#include <ctype.h>
/*
 typedef struct pilha PILHA_DEQUE;
 PILHA_DEQUE *PILHA_DEQUE_inicializa (void);
 void PILHA_DEQUE_push (PILHA_DEQUE *p, int v);
 int PILHA_DEQUE_pop (PILHA_DEQUE *p);
 int PILHA_DEQUE_vazia (PILHA_DEQUE *p);
 void PILHA_DEQUE_libera (PILHA_DEQUE *p);
*/

void ordena(PILHA_DEQUE *p)
{
  PILHA_DEQUE *aux = PILHA_DEQUE_inicializa(), *q = PILHA_DEQUE_inicializa();
  while (!PILHA_DEQUE_vazia(p))
    PILHA_DEQUE_push(aux, PILHA_DEQUE_pop(p));
  while (!PILHA_DEQUE_vazia(aux))
  {
    int maior = PILHA_DEQUE_pop(aux);
    while (!PILHA_DEQUE_vazia(aux))
    {
      int x = PILHA_DEQUE_pop(aux);
      if (x <= maior)
        PILHA_DEQUE_push(q, x);
      else
      {
        PILHA_DEQUE_push(q, maior);
        maior = x;
      }
    }
    PILHA_DEQUE_push(p, maior);
    while (!PILHA_DEQUE_vazia(q))
      PILHA_DEQUE_push(aux, PILHA_DEQUE_pop(q));
  }
  PILHA_DEQUE_libera(aux);
  PILHA_DEQUE_libera(q);
}

int main(void)
{
  PILHA_DEQUE *p = PILHA_DEQUE_inicializa();
  // PILHA_DEQUE *p2 = PILHA_DEQUE_inicializa();
  printf("Insira elementos maiores ou iguais a zero para inclusao na pilha...\n");
  do
  {
    char letra;
    scanf(" %c", &letra);
    if (!isalpha(letra))
      break;
    PILHA_DEQUE_push(p, letra);
  } while (1);
  // printf("Antes de ordenar...\n");

  PILHA_DEQUE_imprime(p);
  char topo = PILHA_DEQUE_topo(p);
  printf("o topo eh %c\n", topo);

  char retirado = PILHA_DEQUE_pop(p);
  printf("elemento retirado eh %c\n", retirado);

  printf("Imprimindo pilha após retirada do elemento %c\n", retirado);
  PILHA_DEQUE_imprime(p);

  char topo2 = PILHA_DEQUE_topo(p);
  printf("o topo agora eh %c\n", topo2);

  char retirado2 = PILHA_DEQUE_pop(p);
  printf("elemento retirado eh %c\n", retirado2);

  printf("Imprimindo pilha após retirada do elemento %c\n", retirado2);
  PILHA_DEQUE_imprime(p);

  char topo3 = PILHA_DEQUE_topo(p);
  printf("o topo agora eh %c\n", topo3);

  /* printf("Criando segunda pilha\n");
  do
  {
    int n2;
    scanf("%d", &n2);
    if (n2 < 0)
      break;
    PILHA_DEQUE_push(p2, n2);
  } while (1);
  PILHA_DEQUE_imprime(p2);

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
  PILHA_DEQUE_imprime(p);


  int topo = PILHA_DEQUE_topo(p);
  printf("Topo=%d\n", topo);
  PILHA_DEQUE_imprime(p);

  PILHA_DEQUE_concatena(p, p2);

  printf("vai copiar\n");
  PILHA_DEQUE *copia = PILHA_DEQUE_copia_com_pilha_auxiliar(p);
  printf("vai imprimir copia\n");
  PILHA_DEQUE_imprime(copia); */

  /*  printf("vai copiar\n");
   PILHA_DEQUE *copia = PILHA_DEQUE_copia_com_recursao(p);
   printf("vai imprimir copia\n");
   PILHA_DEQUE_imprime(copia);


  PILHA_DEQUE *stack_from_queue = f2p(f1);
  printf("imprimindo pilha a partir da fila 1\n");
  PILHA_DEQUE_imprime(stack_from_queue);
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


  PILHA_DEQUE_retira_pares(p);
  printf("imprimindo a pilha sem os pares\n");
  PILHA_DEQUE_imprime(p);  */

  /* TF *queue_from_stack = TF_p2f(p);
  printf("imprimindo fila criada a partir da pilha\n");
  TF_imprime(queue_from_stack);
  printf("\n");
  printf("imprimindo pilha original\n");
  PILHA_DEQUE_imprime(p);
 */
  // PILHA_DEQUE_libera(p);
  return 0;
}
