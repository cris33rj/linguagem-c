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
    return DEQUE_retira_inicio(f->dequetad);
  }
  else
  { // pilha vazia
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

  // PODERIA SER ESTE CODIGO ABAIXO TAMBEM USANDO APENAS A INTERFACE DA TAD FILADEQUE
  /* FILA_DEQUE *aux = FILA_DEQUE_inicializa();
  int ind = 1;
  while (!FILA_DEQUE_vazia(f))
  {
    char x = FILA_DEQUE_retira(f);
    prinfila_deque("%d -> %c\n", ind++, x);
    FILA_DEQUE_insere(aux, x);
  }
  while (!FILA_DEQUE_vazia(aux))
    FILA_DEQUE_insere(f, FILA_DEQUE_retira(aux));
  FILA_DEQUE_libera(aux); */
}

char FILA_DEQUE_inicio(FILA_DEQUE *f)
{
  return DEQUE_inicio(f->dequetad);
}

char FILA_DEQUE_fim(FILA_DEQUE *f)
{
  return DEQUE_fim(f->dequetad);
}

/* void FILA_DEQUE_concatena(TP *p1, TP *p2)
{

  TP *temp = FILA_DEQUE_inicializa();
  while (!FILA_DEQUE_vazia(p2))
  {
    FILA_DEQUE_insere(temf, FILA_DEQUE_retira(p2));
    prinfila_deque("passou na linha 91\n");
  }
  prinfila_deque("imprimindo temp\n");
  FILA_DEQUE_imprime(temp);

  prinfila_deque("passou aqui\n");
  while (!FILA_DEQUE_vazia(temp))
  {
    FILA_DEQUE_insere(p1, FILA_DEQUE_retira(temp));
  }

  prinfila_deque("imprimindo p1 concatenado com p2\n");
  FILA_DEQUE_imprime(p1);
}

TP *FILA_DEQUE_copia_com_pilha_auxiliar(TP *p)
{
  TP *aux = FILA_DEQUE_inicializa();
  TP *copia = FILA_DEQUE_inicializa();
  while (!FILA_DEQUE_vazia(f))
  {
    FILA_DEQUE_insere(aux, FILA_DEQUE_retira(f));
  }
  while (!FILA_DEQUE_vazia(aux))
  {
    FILA_DEQUE_insere(copia, FILA_DEQUE_retira(aux));
  }
  free(aux);
  return copia;
}

TP *FILA_DEQUE_copia_recursivo(TP *f, TP *copia)
{
  if (!FILA_DEQUE_vazia(f))
  {
    int temp = FILA_DEQUE_retira(f);
    FILA_DEQUE_copia_recursivo(f, copia);
    FILA_DEQUE_insere(copia, temp);

    // FILA_DEQUE_insere(copia, FILA_DEQUE_retira(f));
    // FILA_DEQUE_copia_recursivo(f, copia);
  }
  return copia;
}

TP *FILA_DEQUE_copia_com_recursao(TP *p)
{
  TP *copia = FILA_DEQUE_inicializa();
  copia = FILA_DEQUE_copia_recursivo(f, copia);
  // TP *copia2 = FILA_DEQUE_inicializa();
  // copia2 = FILA_DEQUE_copia_recursivo(copia, copia2);
  prinfila_deque("Vai retornar a copia com recursao\n");
  return copia;
}

TP *f2p(FILA_DEQUE *f)
{
  TP *p_aux = FILA_DEQUE_inicializa();
  TP *pilha_saida = FILA_DEQUE_inicializa();
  TP *pilha_para_restaurar_fila = FILA_DEQUE_inicializa();

  while (!FILA_DEQUE_vazia(f))
  {
    FILA_DEQUE_insere(p_aux, FILA_DEQUE_retira(f));
  }
  while (!FILA_DEQUE_vazia(p_aux))
  {
    int temp = FILA_DEQUE_retira(p_aux);
    FILA_DEQUE_insere(pilha_saida, temp);
    FILA_DEQUE_insere(pilha_para_restaurar_fila, temp);
  }

  while (!FILA_DEQUE_vazia(pilha_para_restaurar_fila))
  {
    FILA_DEQUE_insere(f, FILA_DEQUE_retira(pilha_para_restaurar_fila));
  }
  return pilha_saida;
}

void FILA_DEQUE_retira_pares(TP *p)
{
  TP *aux = FILA_DEQUE_inicializa();
  while (!FILA_DEQUE_vazia(f))
  {
    int val = FILA_DEQUE_retira(f);
    if (val % 2 != 0)
      FILA_DEQUE_insere(aux, val);
  }
  while (!FILA_DEQUE_vazia(aux))
  {
    FILA_DEQUE_insere(f, FILA_DEQUE_retira(aux));
  }
  free(aux);
}

FILA_DEQUE *FILA_DEQUE_p2f(TP *p)
{

  TP *p_aux = FILA_DEQUE_inicializa();
  TP *p_aux2 = FILA_DEQUE_inicializa();
  FILA_DEQUE *fila = FILA_DEQUE_inicializa();
  while (!FILA_DEQUE_vazia(f))
  {
    FILA_DEQUE_insere(p_aux, FILA_DEQUE_retira(f));
  }

  while (!FILA_DEQUE_vazia(f))
  {
    FILA_DEQUE_insere(p_aux, FILA_DEQUE_retira(f));
  }

  while (!FILA_DEQUE_vazia(p_aux))
  {
    int val = FILA_DEQUE_retira(p_aux);
    FILA_DEQUE_insere(p_aux2, val);
    FILA_DEQUE_insere(f, val);
  }
  while (!FILA_DEQUE_vazia(p_aux2))
  {
    FILA_DEQUE_insere(fila, FILA_DEQUE_retira(p_aux2));
  }
  return fila;
} */
