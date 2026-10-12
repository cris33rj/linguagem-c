#include "PILHA2F.h"
#include "FILA_DEQUE.h"

struct pilha
{
  FILA_DEQUE *f1;
  FILA_DEQUE *f2;
};

PILHA2F *PILHA2F_inicializa(void)
{
  PILHA2F *p = (PILHA2F *)malloc(sizeof(PILHA2F));
  p->f1 = FILA_DEQUE_inicializa();
  p->f2 = FILA_DEQUE_inicializa();
  return p;
}

int PILHA2F_vazia(PILHA2F *p)
{
  return FILA_DEQUE_vazia(p->f1) && FILA_DEQUE_vazia(p->f2);
}

void PILHA2F_push(PILHA2F *p, char elem)
{
  FILA_DEQUE_insere(p->f2, elem);
  while (!FILA_DEQUE_vazia(p->f1))
  {
    FILA_DEQUE_insere(p->f2, FILA_DEQUE_inicio(p->f1));
    FILA_DEQUE_retira(p->f1);
  }
  FILA_DEQUE *q = FILA_DEQUE_inicializa();
  q = p->f1;
  p->f1 = p->f2;
  p->f2 = q;
}

char PILHA2F_pop(PILHA2F *p)
{
  if (!FILA_DEQUE_vazia(p->f1))
    return FILA_DEQUE_retira(p->f1);
  else
    exit(1);
}

void PILHA2F_libera(PILHA2F *p)
{
  FILA_DEQUE_libera(p->f1);
  FILA_DEQUE_libera(p->f2);
  free(p);
}

void PILHA2F_imprime(PILHA2F *p)
{
  FILA_DEQUE_imprime(p->f1);
}

char PILHA2F_topo(PILHA2F *p)
{
  char topo = FILA_DEQUE_inicio(p->f1);
  return topo;
}
