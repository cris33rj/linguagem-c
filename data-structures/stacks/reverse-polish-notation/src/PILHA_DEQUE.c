#include "DEQUE.h"
#include "PILHA_DEQUE.h"

struct pilha
{
  DEQUE *deque_tad;
  int topo;
};

PILHA_DEQUE *PILHA_DEQUE_inicializa(void)
{
  PILHA_DEQUE *p = (PILHA_DEQUE *)malloc(sizeof(PILHA_DEQUE));
  p->deque_tad = DEQUE_inicializa();
  return p;
}

int PILHA_DEQUE_vazia(PILHA_DEQUE *p)
{
  return (DEQUE_vazia(p->deque_tad));
}

void PILHA_DEQUE_push(PILHA_DEQUE *p, char elem)
{
  DEQUE_insere_inicio(p->deque_tad, elem);
}

char PILHA_DEQUE_pop(PILHA_DEQUE *p)
{
  if (!PILHA_DEQUE_vazia(p))
  {
    return DEQUE_remove_inicio(p->deque_tad);
  }
  else
  { // pilha vazia
    exit(1);
  }
}

void PILHA_DEQUE_libera(PILHA_DEQUE *p)
{
  DEQUE_libera(p->deque_tad);
  free(p);
}

void PILHA_DEQUE_imprime(PILHA_DEQUE *p)
{
  PILHA_DEQUE *aux = PILHA_DEQUE_inicializa();
  int ind = 1;
  while (!PILHA_DEQUE_vazia(p))
  {
    char x = PILHA_DEQUE_pop(p);
    printf("%d -> %c\n", ind++, x);
    PILHA_DEQUE_push(aux, x);
  }
  while (!PILHA_DEQUE_vazia(aux))
    PILHA_DEQUE_push(p, PILHA_DEQUE_pop(aux));
  PILHA_DEQUE_libera(aux);
}

char PILHA_DEQUE_topo(PILHA_DEQUE *p)
{
  char deque_tad = PILHA_DEQUE_pop(p);
  PILHA_DEQUE_push(p, deque_tad);
  return deque_tad;
}
