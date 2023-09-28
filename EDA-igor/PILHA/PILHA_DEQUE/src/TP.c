#include "DEQUE.h"
#include "TP.h"

struct pilha
{
  DEQUE *topo;
};

TP *TP_inicializa(void)
{
  TP *p = (TP *)malloc(sizeof(TP));
  p->topo = DEQUE_inicializa();
  return p;
}

int TP_vazia(TP *p)
{
  return (DEQUE_vazia(p->topo));
}

void TP_push(TP *p, char elem)
{
  DEQUE_insere_inicio(p->topo, elem);
}

char TP_pop(TP *p)
{
  if (!TP_vazia(p))
  {
    return DEQUE_retira_inicio(p->topo);
  }
  else
  { // pilha vazia
    exit(1);
  }
}

void TP_libera(TP *p)
{
  DEQUE_libera(p->topo);
  free(p);
}

void TP_imprime(TP *p)
{
  TP *aux = TP_inicializa();
  int ind = 1;
  while (!TP_vazia(p))
  {
    char x = TP_pop(p);
    printf("%d -> %c\n", ind++, x);
    TP_push(aux, x);
  }
  while (!TP_vazia(aux))
    TP_push(p, TP_pop(aux));
  TP_libera(aux);
}

char TP_topo(TP *p)
{
  char topo = TP_pop(p);
  TP_push(p, topo);
  return topo;
}

/* void TP_concatena(TP *p1, TP *p2)
{

  TP *temp = TP_inicializa();
  while (!TP_vazia(p2))
  {
    TP_push(temp, TP_pop(p2));
    printf("passou na linha 91\n");
  }
  printf("imprimindo temp\n");
  TP_imprime(temp);

  printf("passou aqui\n");
  while (!TP_vazia(temp))
  {
    TP_push(p1, TP_pop(temp));
  }

  printf("imprimindo p1 concatenado com p2\n");
  TP_imprime(p1);
}

TP *TP_copia_com_pilha_auxiliar(TP *p)
{
  TP *aux = TP_inicializa();
  TP *copia = TP_inicializa();
  while (!TP_vazia(p))
  {
    TP_push(aux, TP_pop(p));
  }
  while (!TP_vazia(aux))
  {
    TP_push(copia, TP_pop(aux));
  }
  free(aux);
  return copia;
}

TP *TP_copia_recursivo(TP *p, TP *copia)
{
  if (!TP_vazia(p))
  {
    int temp = TP_pop(p);
    TP_copia_recursivo(p, copia);
    TP_push(copia, temp);

    // TP_push(copia, TP_pop(p));
    // TP_copia_recursivo(p, copia);
  }
  return copia;
}

TP *TP_copia_com_recursao(TP *p)
{
  TP *copia = TP_inicializa();
  copia = TP_copia_recursivo(p, copia);
  // TP *copia2 = TP_inicializa();
  // copia2 = TP_copia_recursivo(copia, copia2);
  printf("Vai retornar a copia com recursao\n");
  return copia;
}

TP *f2p(TF *f)
{
  TP *p_aux = TP_inicializa();
  TP *pilha_saida = TP_inicializa();
  TP *pilha_para_restaurar_fila = TP_inicializa();

  while (!TF_vazia(f))
  {
    TP_push(p_aux, TF_retira(f));
  }
  while (!TP_vazia(p_aux))
  {
    int temp = TP_pop(p_aux);
    TP_push(pilha_saida, temp);
    TP_push(pilha_para_restaurar_fila, temp);
  }

  while (!TP_vazia(pilha_para_restaurar_fila))
  {
    TF_insere(f, TP_pop(pilha_para_restaurar_fila));
  }
  return pilha_saida;
}

void TP_retira_pares(TP *p)
{
  TP *aux = TP_inicializa();
  while (!TP_vazia(p))
  {
    int val = TP_pop(p);
    if (val % 2 != 0)
      TP_push(aux, val);
  }
  while (!TP_vazia(aux))
  {
    TP_push(p, TP_pop(aux));
  }
  free(aux);
}

TF *TF_p2f(TP *p)
{

  TP *p_aux = TP_inicializa();
  TP *p_aux2 = TP_inicializa();
  TF *fila = TF_inicializa();
  while (!TP_vazia(p))
  {
    TP_push(p_aux, TP_pop(p));
  }

  while (!TP_vazia(p))
  {
    TP_push(p_aux, TP_pop(p));
  }

  while (!TP_vazia(p_aux))
  {
    int val = TP_pop(p_aux);
    TP_push(p_aux2, val);
    TP_push(p, val);
  }
  while (!TP_vazia(p_aux2))
  {
    TF_insere(fila, TP_pop(p_aux2));
  }
  return fila;
} */
