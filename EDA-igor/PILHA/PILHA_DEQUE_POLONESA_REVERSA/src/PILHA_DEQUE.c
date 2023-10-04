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
    return DEQUE_retira_inicio(p->deque_tad);
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

/* void PILHA_DEQUE_concatena(PILHA_DEQUE *p1, PILHA_DEQUE *p2)
{

  PILHA_DEQUE *temp = PILHA_DEQUE_inicializa();
  while (!PILHA_DEQUE_vazia(p2))
  {
    PILHA_DEQUE_push(temp, PILHA_DEQUE_pop(p2));
    printf("passou na linha 91\n");
  }
  printf("imprimindo temp\n");
  PILHA_DEQUE_imprime(temp);

  printf("passou aqui\n");
  while (!PILHA_DEQUE_vazia(temp))
  {
    PILHA_DEQUE_push(p1, PILHA_DEQUE_pop(temp));
  }

  printf("imprimindo p1 concatenado com p2\n");
  PILHA_DEQUE_imprime(p1);
}

PILHA_DEQUE *PILHA_DEQUE_copia_com_pilha_auxiliar(PILHA_DEQUE *p)
{
  PILHA_DEQUE *aux = PILHA_DEQUE_inicializa();
  PILHA_DEQUE *copia = PILHA_DEQUE_inicializa();
  while (!PILHA_DEQUE_vazia(p))
  {
    PILHA_DEQUE_push(aux, PILHA_DEQUE_pop(p));
  }
  while (!PILHA_DEQUE_vazia(aux))
  {
    PILHA_DEQUE_push(copia, PILHA_DEQUE_pop(aux));
  }
  free(aux);
  return copia;
}

PILHA_DEQUE *PILHA_DEQUE_copia_recursivo(PILHA_DEQUE *p, PILHA_DEQUE *copia)
{
  if (!PILHA_DEQUE_vazia(p))
  {
    int temp = PILHA_DEQUE_pop(p);
    PILHA_DEQUE_copia_recursivo(p, copia);
    PILHA_DEQUE_push(copia, temp);

    // PILHA_DEQUE_push(copia, PILHA_DEQUE_pop(p));
    // PILHA_DEQUE_copia_recursivo(p, copia);
  }
  return copia;
}

PILHA_DEQUE *PILHA_DEQUE_copia_com_recursao(PILHA_DEQUE *p)
{
  PILHA_DEQUE *copia = PILHA_DEQUE_inicializa();
  copia = PILHA_DEQUE_copia_recursivo(p, copia);
  // PILHA_DEQUE *copia2 = PILHA_DEQUE_inicializa();
  // copia2 = PILHA_DEQUE_copia_recursivo(copia, copia2);
  printf("Vai retornar a copia com recursao\n");
  return copia;
}

PILHA_DEQUE *f2p(TF *f)
{
  PILHA_DEQUE *p_aux = PILHA_DEQUE_inicializa();
  PILHA_DEQUE *pilha_saida = PILHA_DEQUE_inicializa();
  PILHA_DEQUE *pilha_para_restaurar_fila = PILHA_DEQUE_inicializa();

  while (!TF_vazia(f))
  {
    PILHA_DEQUE_push(p_aux, TF_retira(f));
  }
  while (!PILHA_DEQUE_vazia(p_aux))
  {
    int temp = PILHA_DEQUE_pop(p_aux);
    PILHA_DEQUE_push(pilha_saida, temp);
    PILHA_DEQUE_push(pilha_para_restaurar_fila, temp);
  }

  while (!PILHA_DEQUE_vazia(pilha_para_restaurar_fila))
  {
    TF_insere(f, PILHA_DEQUE_pop(pilha_para_restaurar_fila));
  }
  return pilha_saida;
}

void PILHA_DEQUE_retira_pares(PILHA_DEQUE *p)
{
  PILHA_DEQUE *aux = PILHA_DEQUE_inicializa();
  while (!PILHA_DEQUE_vazia(p))
  {
    int val = PILHA_DEQUE_pop(p);
    if (val % 2 != 0)
      PILHA_DEQUE_push(aux, val);
  }
  while (!PILHA_DEQUE_vazia(aux))
  {
    PILHA_DEQUE_push(p, PILHA_DEQUE_pop(aux));
  }
  free(aux);
}

TF *TF_p2f(PILHA_DEQUE *p)
{

  PILHA_DEQUE *p_aux = PILHA_DEQUE_inicializa();
  PILHA_DEQUE *p_aux2 = PILHA_DEQUE_inicializa();
  TF *fila = TF_inicializa();
  while (!PILHA_DEQUE_vazia(p))
  {
    PILHA_DEQUE_push(p_aux, PILHA_DEQUE_pop(p));
  }

  while (!PILHA_DEQUE_vazia(p))
  {
    PILHA_DEQUE_push(p_aux, PILHA_DEQUE_pop(p));
  }

  while (!PILHA_DEQUE_vazia(p_aux))
  {
    int val = PILHA_DEQUE_pop(p_aux);
    PILHA_DEQUE_push(p_aux2, val);
    PILHA_DEQUE_push(p, val);
  }
  while (!PILHA_DEQUE_vazia(p_aux2))
  {
    TF_insere(fila, PILHA_DEQUE_pop(p_aux2));
  }
  return fila;
} */
