#include "FILA2P.h"
#include "PILHA_DEQUE.h"

struct fila
{
  PILHA_DEQUE *p1;
  PILHA_DEQUE *p2;
};

FILA2P *FILA2P_inicializa(void)
{
  FILA2P *f = (FILA2P *)malloc(sizeof(FILA2P));
  f->p1 = PILHA_DEQUE_inicializa();
  f->p2 = PILHA_DEQUE_inicializa();
  return f;
}

int FILA2P_vazia(FILA2P *f)
{
  return PILHA_DEQUE_vazia(f->p1) && PILHA_DEQUE_vazia(f->p2);
}

void FILA2P_insere(FILA2P *f, char elem)
{
  while (!PILHA_DEQUE_vazia(f->p1))
  {
    PILHA_DEQUE_push(f->p2, PILHA_DEQUE_pop(f->p1));
  }

  PILHA_DEQUE_push(f->p1, elem);

  while (!PILHA_DEQUE_vazia(f->p2))
  {
    PILHA_DEQUE_push(f->p1, PILHA_DEQUE_pop(f->p2));
  }
}

char FILA2P_retira(FILA2P *f)
{

  if (!PILHA_DEQUE_vazia(f->p1))
  {
    return PILHA_DEQUE_pop(f->p1);
  }
  else
    exit(1);
}

void FILA2P_libera(FILA2P *f)
{
  PILHA_DEQUE_libera(f->p1);
  PILHA_DEQUE_libera(f->p2);
  free(f);
}

void FILA2P_imprime(FILA2P *f)
{
  PILHA_DEQUE_imprime(f->p1);
}

char FILA2P_inicio(FILA2P *f)
{
  char inicio = PILHA_DEQUE_topo(f->p1);
  return inicio;
}
