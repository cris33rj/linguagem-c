#include "DEQUE.h"
#include "PILHA_DEQUE.h"

struct pilha
{
  DEQUE *deque_main;
  DEQUE *deque_min;
};

PILHA_DEQUE *PILHA_DEQUE_inicializa(void)
{
  PILHA_DEQUE *p = (PILHA_DEQUE *)malloc(sizeof(PILHA_DEQUE));
  p->deque_main = DEQUE_inicializa();
  p->deque_min = DEQUE_inicializa();
  return p;
}

int PILHA_DEQUE_vazia(PILHA_DEQUE *p)
{
  return (DEQUE_vazia(p->deque_main));
}

void PILHA_DEQUE_push(PILHA_DEQUE *p, int elem)
{
  if (DEQUE_vazia(p->deque_main) || DEQUE_inicio(p->deque_min) >= elem)
    DEQUE_insere_inicio(p->deque_min, elem);

  DEQUE_insere_inicio(p->deque_main, elem);
}

int PILHA_DEQUE_pop(PILHA_DEQUE *p)
{
  if (!PILHA_DEQUE_vazia(p))
  {
    if (DEQUE_inicio(p->deque_main) == DEQUE_inicio(p->deque_min))
      DEQUE_retira_inicio(p->deque_min);

    return DEQUE_retira_inicio(p->deque_main);
  }
  else
  { // pilha vazia
    exit(1);
  }
}

int PILHA_DEQUE_obter_minimo(PILHA_DEQUE *p)
{
  return DEQUE_inicio(p->deque_min);
}

void PILHA_DEQUE_libera(PILHA_DEQUE *p)
{
  DEQUE_libera(p->deque_main);
  free(p);
}

void PILHA_DEQUE_imprime(PILHA_DEQUE *p)
{
  PILHA_DEQUE *aux = PILHA_DEQUE_inicializa();
  int ind = 1;
  while (!PILHA_DEQUE_vazia(p))
  {
    int x = PILHA_DEQUE_pop(p);
    printf("%d -> %d\n", ind++, x);
    PILHA_DEQUE_push(aux, x);
  }
  while (!PILHA_DEQUE_vazia(aux))
    PILHA_DEQUE_push(p, PILHA_DEQUE_pop(aux));
  PILHA_DEQUE_libera(aux);
}

int PILHA_DEQUE_topo(PILHA_DEQUE *p)
{
  int deque_main = PILHA_DEQUE_pop(p);
  PILHA_DEQUE_push(p, deque_main);
  return deque_main;
}
