#include "PILHA_DEQUE.h"
#include "FILA_DEQUE.h"
#include <string.h>
#include <ctype.h>

void transfere(PILHA_DEQUE *p1, PILHA_DEQUE *p2)
{
  while (!PILHA_DEQUE_vazia(p1))
  {
    PILHA_DEQUE_push(p2, PILHA_DEQUE_pop(p1));
  }
}

void transfere_n(PILHA_DEQUE *p1, PILHA_DEQUE *p2, int n)
{
  // printf("entrou em transfere_n\n");
  for (int i = 0; i < n; i++)
  {
    // Store the top element
    // in a temporary variable
    int temp = PILHA_DEQUE_topo(p1);

    // Pop out of the stack
    PILHA_DEQUE_pop(p1);

    // Push it into s2
    PILHA_DEQUE_push(p2, temp);
  }
}

void inverte_com_uma_pilha_v1(PILHA_DEQUE *p, int n)
{
  // printf("entrou em inverte_com_uma_pilha\n");
  PILHA_DEQUE *p_aux = PILHA_DEQUE_inicializa();
  for (int i = 0; i < n; i++)
  {
    // Store the top element
    // of the given stack
    char x = PILHA_DEQUE_topo(p);

    // Pop that element
    // out of the stack
    PILHA_DEQUE_pop(p);

    transfere_n(p, p_aux, n - i - 1);
    PILHA_DEQUE_push(p, x);
    transfere_n(p_aux, p, n - i - 1);
  }
}

/* PILHA_DEQUE *inverte_com_uma_pilha_v2(PILHA_DEQUE *p, int n)
{
  PILHA_DEQUE *p_aux = PILHA_DEQUE_inicializa();

  for (int i = 0; i < n; i++)
  {
    PILHA_DEQUE_push(p_aux, PILHA_DEQUE_pop(p));
  }
  return p_aux;
} */

/* void inverte_com_uma_pilha_v2(PILHA_DEQUE *p)
{
  PILHA_DEQUE *p_aux = PILHA_DEQUE_inicializa();

  while (!PILHA_DEQUE_vazia(p))
  {
    PILHA_DEQUE_push(p_aux, PILHA_DEQUE_pop(p));
  }
  return p_aux;
} */

void inverte_com_duas_pilhas(PILHA_DEQUE *p)
{
  PILHA_DEQUE *p_aux1 = PILHA_DEQUE_inicializa();
  PILHA_DEQUE *p_aux2 = PILHA_DEQUE_inicializa();

  transfere(p, p_aux1);
  transfere(p_aux1, p_aux2);
  transfere(p_aux2, p);
}

void inverte_com_uma_fila(PILHA_DEQUE *p)
{
  FILA_DEQUE *f = FILA_DEQUE_inicializa();
  while (!PILHA_DEQUE_vazia(p))
  {
    FILA_DEQUE_insere(f, PILHA_DEQUE_pop(p));
  }

  while (!FILA_DEQUE_vazia(f))
  {
    PILHA_DEQUE_push(p, FILA_DEQUE_retira(f));
  }
}

int main(void)
{
  int n = 0;
  PILHA_DEQUE *p = PILHA_DEQUE_inicializa();
  // TP *p2 = PILHA_DEQUE_inicializa();
  printf("Insira caracteres na pilha...\n");
  do
  {
    char letra;
    scanf(" %c", &letra);
    if (!isalpha(letra))
      break;
    PILHA_DEQUE_push(p, letra);
    n++;
  } while (1);
  // prinPILHA_DEQUE("Antes de ordenar...\n");

  // printf("imprimindo N -----------> %d\n", n);
  PILHA_DEQUE_imprime(p);

  inverte_com_uma_fila(p);
  printf("pilha após a inversao com uso de uma fila\n\n");
  PILHA_DEQUE_imprime(p);

  inverte_com_duas_pilhas(p);
  printf("pilha após a inversao com uso de duas pilhas\n\n");
  PILHA_DEQUE_imprime(p);

  printf("vai inverter com uso de uma pilha\n\n");
  inverte_com_uma_pilha_v1(p, n);
  printf("pilha após a inversao com uso de uma pilha - versao 1\n\n");
  PILHA_DEQUE_imprime(p);

  /*   printf("vai inverter com uso de uma pilha\n\n");
    inverte_com_uma_pilha_v1(p, n);
    printf("pilha após a inversao com uso de uma pilha - versao 1\n\n");
    PILHA_DEQUE_imprime(p); */
}
