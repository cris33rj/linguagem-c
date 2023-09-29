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

/* void PILHA2F_concatena(PILHA2F *p1, PILHA2F *p2)
{

  PILHA2F *temp = PILHA2F_inicializa();
  while (!PILHA2F_vazia(p2))
  {
    PILHA2F_push(temp, PILHA2F_pop(p2));
    printf("passou na linha 91\n");
  }
  printf("imprimindo temp\n");
  PILHA2F_imprime(temp);

  printf("passou aqui\n");
  while (!PILHA2F_vazia(temp))
  {
    PILHA2F_push(p1, PILHA2F_pop(temp));
  }

  printf("imprimindo p1 concatenado com p2\n");
  PILHA2F_imprime(p1);
}

PILHA2F *PILHA2F_copia_com_pilha_auxiliar(PILHA2F *p)
{
  PILHA2F *aux = PILHA2F_inicializa();
  PILHA2F *copia = PILHA2F_inicializa();
  while (!PILHA2F_vazia(p))
  {
    PILHA2F_push(aux, PILHA2F_pop(p));
  }
  while (!PILHA2F_vazia(aux))
  {
    PILHA2F_push(copia, PILHA2F_pop(aux));
  }
  free(aux);
  return copia;
}

PILHA2F *PILHA2F_copia_recursivo(PILHA2F *p, PILHA2F *copia)
{
  if (!PILHA2F_vazia(p))
  {
    int temp = PILHA2F_pop(p);
    PILHA2F_copia_recursivo(p, copia);
    PILHA2F_push(copia, temp);

    // PILHA2F_push(copia, PILHA2F_pop(p));
    // PILHA2F_copia_recursivo(p, copia);
  }
  return copia;
}

PILHA2F *PILHA2F_copia_com_recursao(PILHA2F *p)
{
  PILHA2F *copia = PILHA2F_inicializa();
  copia = PILHA2F_copia_recursivo(p, copia);
  // PILHA2F *copia2 = PILHA2F_inicializa();
  // copia2 = PILHA2F_copia_recursivo(copia, copia2);
  printf("Vai retornar a copia com recursao\n");
  return copia;
}

PILHA2F *f2p(TF *f)
{
  PILHA2F *p_aux = PILHA2F_inicializa();
  PILHA2F *pilha_saida = PILHA2F_inicializa();
  PILHA2F *pilha_para_restaurar_fila = PILHA2F_inicializa();

  while (!TF_vazia(f))
  {
    PILHA2F_push(p_aux, TF_retira(f));
  }
  while (!PILHA2F_vazia(p_aux))
  {
    int temp = PILHA2F_pop(p_aux);
    PILHA2F_push(pilha_saida, temp);
    PILHA2F_push(pilha_para_restaurar_fila, temp);
  }

  while (!PILHA2F_vazia(pilha_para_restaurar_fila))
  {
    TF_insere(f, PILHA2F_pop(pilha_para_restaurar_fila));
  }
  return pilha_saida;
}

void PILHA2F_retira_pares(PILHA2F *p)
{
  PILHA2F *aux = PILHA2F_inicializa();
  while (!PILHA2F_vazia(p))
  {
    int val = PILHA2F_pop(p);
    if (val % 2 != 0)
      PILHA2F_push(aux, val);
  }
  while (!PILHA2F_vazia(aux))
  {
    PILHA2F_push(p, PILHA2F_pop(aux));
  }
  free(aux);
}

TF *TF_p2f(PILHA2F *p)
{

  PILHA2F *p_aux = PILHA2F_inicializa();
  PILHA2F *p_aux2 = PILHA2F_inicializa();
  TF *fila = TF_inicializa();
  while (!PILHA2F_vazia(p))
  {
    PILHA2F_push(p_aux, PILHA2F_pop(p));
  }

  while (!PILHA2F_vazia(p))
  {
    PILHA2F_push(p_aux, PILHA2F_pop(p));
  }

  while (!PILHA2F_vazia(p_aux))
  {
    int val = PILHA2F_pop(p_aux);
    PILHA2F_push(p_aux2, val);
    PILHA2F_push(p, val);
  }
  while (!PILHA2F_vazia(p_aux2))
  {
    TF_insere(fila, PILHA2F_pop(p_aux2));
  }
  return fila;
} */
