#include "DEQUE.h"
#include "TF.h"

struct fila
{
  DEQUE *dequetad;
};

TF *TF_inicializa(void)
{
  TF *f = (TF *)malloc(sizeof(TF));
  f->dequetad = DEQUE_inicializa();
  return f;
}

int TF_vazia(TF *f)
{
  return (DEQUE_vazia(f->dequetad));
}

void TF_insere(TF *f, char elem)
{
  DEQUE_insere_fim(f->dequetad, elem);
}

char TF_retira(TF *f)
{
  if (!TF_vazia(f))
  {
    return DEQUE_retira_inicio(f->dequetad);
  }
  else
  { // pilha vazia
    exit(1);
  }
}

void TF_libera(TF *f)
{
  DEQUE_libera(f->dequetad);
  free(f);
}

void TF_imprime(TF *f)
{
  DEQUE_imprime(f->dequetad);

  // PODERIA SER ESTE CODIGO ABAIXO TAMBEM USANDO APENAS A INTERFACE DA TAD FILADEQUE
  /* TF *aux = TF_inicializa();
  int ind = 1;
  while (!TF_vazia(f))
  {
    char x = TF_retira(f);
    printf("%d -> %c\n", ind++, x);
    TF_insere(aux, x);
  }
  while (!TF_vazia(aux))
    TF_insere(f, TF_retira(aux));
  TF_libera(aux); */
}

char TF_inicio(TF *f)
{
  return DEQUE_inicio(f->dequetad);
}

char TF_fim(TF *f)
{
  return DEQUE_fim(f->dequetad);
}

/* void TF_concatena(TP *p1, TP *p2)
{

  TP *temp = TF_inicializa();
  while (!TF_vazia(p2))
  {
    TF_insere(temf, TF_retira(p2));
    printf("passou na linha 91\n");
  }
  printf("imprimindo temp\n");
  TF_imprime(temp);

  printf("passou aqui\n");
  while (!TF_vazia(temp))
  {
    TF_insere(p1, TF_retira(temp));
  }

  printf("imprimindo p1 concatenado com p2\n");
  TF_imprime(p1);
}

TP *TF_copia_com_pilha_auxiliar(TP *p)
{
  TP *aux = TF_inicializa();
  TP *copia = TF_inicializa();
  while (!TF_vazia(f))
  {
    TF_insere(aux, TF_retira(f));
  }
  while (!TF_vazia(aux))
  {
    TF_insere(copia, TF_retira(aux));
  }
  free(aux);
  return copia;
}

TP *TF_copia_recursivo(TP *f, TP *copia)
{
  if (!TF_vazia(f))
  {
    int temp = TF_retira(f);
    TF_copia_recursivo(f, copia);
    TF_insere(copia, temp);

    // TF_insere(copia, TF_retira(f));
    // TF_copia_recursivo(f, copia);
  }
  return copia;
}

TP *TF_copia_com_recursao(TP *p)
{
  TP *copia = TF_inicializa();
  copia = TF_copia_recursivo(f, copia);
  // TP *copia2 = TF_inicializa();
  // copia2 = TF_copia_recursivo(copia, copia2);
  printf("Vai retornar a copia com recursao\n");
  return copia;
}

TP *f2p(TF *f)
{
  TP *p_aux = TF_inicializa();
  TP *pilha_saida = TF_inicializa();
  TP *pilha_para_restaurar_fila = TF_inicializa();

  while (!TF_vazia(f))
  {
    TF_insere(p_aux, TF_retira(f));
  }
  while (!TF_vazia(p_aux))
  {
    int temp = TF_retira(p_aux);
    TF_insere(pilha_saida, temp);
    TF_insere(pilha_para_restaurar_fila, temp);
  }

  while (!TF_vazia(pilha_para_restaurar_fila))
  {
    TF_insere(f, TF_retira(pilha_para_restaurar_fila));
  }
  return pilha_saida;
}

void TF_retira_pares(TP *p)
{
  TP *aux = TF_inicializa();
  while (!TF_vazia(f))
  {
    int val = TF_retira(f);
    if (val % 2 != 0)
      TF_insere(aux, val);
  }
  while (!TF_vazia(aux))
  {
    TF_insere(f, TF_retira(aux));
  }
  free(aux);
}

TF *TF_p2f(TP *p)
{

  TP *p_aux = TF_inicializa();
  TP *p_aux2 = TF_inicializa();
  TF *fila = TF_inicializa();
  while (!TF_vazia(f))
  {
    TF_insere(p_aux, TF_retira(f));
  }

  while (!TF_vazia(f))
  {
    TF_insere(p_aux, TF_retira(f));
  }

  while (!TF_vazia(p_aux))
  {
    int val = TF_retira(p_aux);
    TF_insere(p_aux2, val);
    TF_insere(f, val);
  }
  while (!TF_vazia(p_aux2))
  {
    TF_insere(fila, TF_retira(p_aux2));
  }
  return fila;
} */
