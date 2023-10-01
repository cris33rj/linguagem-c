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
    printf("entrou\n");

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

/* void FILA2P_concatena(FILA2P *f1, FILA2P *f2)
{

  FILA2P *temp = FILA2P_inicializa();
  while (!FILA2P_vazia(p2))
  {
    FILA2P_push(temp, FILA2P_pop(p2));
    printf("passou na linha 91\n");
  }
  printf("imprimindo temp\n");
  FILA2P_imprime(temp);

  printf("passou aqui\n");
  while (!FILA2P_vazia(temp))
  {
    FILA2P_push(p1, FILA2P_pop(temp));
  }

  printf("imprimindo p1 concatenado com p2\n");
  FILA2P_imprime(p1);
}

FILA2P *FILA2P_copia_com_pilha_auxiliar(FILA2P *f)
{
  FILA2P *aux = FILA2P_inicializa();
  FILA2P *copia = FILA2P_inicializa();
  while (!FILA2P_vazia(p))
  {
    FILA2P_push(aux, FILA2P_pop(p));
  }
  while (!FILA2P_vazia(aux))
  {
    FILA2P_push(copia, FILA2P_pop(aux));
  }
  free(aux);
  return copia;
}

FILA2P *FILA2P_copia_recursivo(FILA2P *f, FILA2P *copia)
{
  if (!FILA2P_vazia(p))
  {
    int temp = FILA2P_pop(p);
    FILA2P_copia_recursivo(p, copia);
    FILA2P_push(copia, temp);

    // FILA2P_push(copia, FILA2P_pop(p));
    // FILA2P_copia_recursivo(p, copia);
  }
  return copia;
}

FILA2P *FILA2P_copia_com_recursao(FILA2P *f)
{
  FILA2P *copia = FILA2P_inicializa();
  copia = FILA2P_copia_recursivo(p, copia);
  // FILA2P *copia2 = FILA2P_inicializa();
  // copia2 = FILA2P_copia_recursivo(copia, copia2);
  printf("Vai retornar a copia com recursao\n");
  return copia;
}

FILA2P *f2p(TF *f)
{
  FILA2P *f_aux = FILA2P_inicializa();
  FILA2P *filha_saida = FILA2P_inicializa();
  FILA2P *filha_para_restaurar_fila = FILA2P_inicializa();

  while (!TF_vazia(f))
  {
    FILA2P_push(p_aux, TF_retira(f));
  }
  while (!FILA2P_vazia(p_aux))
  {
    int temp = FILA2P_pop(p_aux);
    FILA2P_push(pilha_saida, temp);
    FILA2P_push(pilha_para_restaurar_fila, temp);
  }

  while (!FILA2P_vazia(pilha_para_restaurar_fila))
  {
    TF_insere(f, FILA2P_pop(pilha_para_restaurar_fila));
  }
  return pilha_saida;
}

void FILA2P_retira_pares(FILA2P *f)
{
  FILA2P *aux = FILA2P_inicializa();
  while (!FILA2P_vazia(p))
  {
    int val = FILA2P_pop(p);
    if (val % 2 != 0)
      FILA2P_push(aux, val);
  }
  while (!FILA2P_vazia(aux))
  {
    FILA2P_push(p, FILA2P_pop(aux));
  }
  free(aux);
}

TF *TF_p2f(FILA2P *f)
{

  FILA2P *f_aux = FILA2P_inicializa();
  FILA2P *f_aux2 = FILA2P_inicializa();
  TF *fila = TF_inicializa();
  while (!FILA2P_vazia(p))
  {
    FILA2P_push(p_aux, FILA2P_pop(p));
  }

  while (!FILA2P_vazia(p))
  {
    FILA2P_push(p_aux, FILA2P_pop(p));
  }

  while (!FILA2P_vazia(p_aux))
  {
    int val = FILA2P_pop(p_aux);
    FILA2P_push(p_aux2, val);
    FILA2P_push(p, val);
  }
  while (!FILA2P_vazia(p_aux2))
  {
    TF_insere(fila, FILA2P_pop(p_aux2));
  }
  return fila;
} */
