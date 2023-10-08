#include "DEQUE.h"
#include "FILA_DEQUE.h"

struct fila
{
  DEQUE *dequetad;
};

FILA_DEQUE *FILA_DEQUE_inicializa(void)
{
  FILA_DEQUE *f = (FILA_DEQUE *)malloc(sizeof(FILA_DEQUE));
  f->dequetad = DEQUE_inicializa();
  return f;
}

int FILA_DEQUE_vazia(FILA_DEQUE *f)
{
  return (DEQUE_vazia(f->dequetad));
}

void FILA_DEQUE_insere(FILA_DEQUE *f, char elem)
{
  DEQUE_insere_fim(f->dequetad, elem);
}

char FILA_DEQUE_retira(FILA_DEQUE *f)
{
  if (!FILA_DEQUE_vazia(f))
  {
    return DEQUE_remove_inicio(f->dequetad);
  }
  else
  {
    exit(1);
  }
}

void FILA_DEQUE_libera(FILA_DEQUE *f)
{
  DEQUE_libera(f->dequetad);
  free(f);
}

void FILA_DEQUE_imprime(FILA_DEQUE *f)
{
  DEQUE_imprime(f->dequetad);
}

char FILA_DEQUE_inicio(FILA_DEQUE *f)
{
  return DEQUE_inicio(f->dequetad);
}

char FILA_DEQUE_fim(FILA_DEQUE *f)
{
  return DEQUE_fim(f->dequetad);
}
