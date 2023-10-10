#include "TAB.h"

TAB *TAB_inicializa(void)
{
  return NULL;
}

TAB *TAB_cria(int raiz, TAB *esq, TAB *dir)
{
  TAB *novo = (TAB *)malloc(sizeof(TAB));
  novo->info = raiz;
  novo->esq = esq;
  novo->dir = dir;

  return novo;
}
void TAB_libera(TAB *a)
{
  if (a)
  {
    TAB_libera(a->esq);
    TAB_libera(a->dir);
    free(a);
  }
}

TAB *TAB_busca(TAB *a, int elem)
{
  if ((!a) || (a->info == elem))
    return a;
  TAB *resp = TAB_busca(a->esq, elem);
  if (resp)
    return resp;
  return TAB_busca(a->dir, elem);
}

int maximo(int a, int b)
{
  if (a > b)
    return a;
  return b;
}

int TAB_altura(TAB *a)
{
  if (!a)
    return -1;
  return maximo(TAB_altura(a->esq), TAB_altura(a->dir)) + 1;
}

int calcula_balanceamento(TAB *a)
{
  int altura_esq = TAB_altura(a->esq);
  int altura_dir = TAB_altura(a->dir);
  return altura_esq - altura_dir;
}
//(a) Escreva um algoritmo para computar a soma das folhas
int TAB_soma_nos_folhas(TAB *a, int soma)
{
  if (!a)
    return 0;

  if (!a->esq && !a->dir)
    soma += a->info;

  return soma + TAB_soma_nos_folhas(a->esq, soma) + TAB_soma_nos_folhas(a->dir, soma);
}

//(b) Escreva um algoritmo para efetuar um percurso de pos-ordem
void TAB_imp_pos(TAB *a)
{
  if (a)
  {
    TAB_imp_pos(a->esq);
    TAB_imp_pos(a->dir);
    printf("%d ", a->info);
  }
}

//(c) Escreva um algoritmo para efetuar um percurso de em-ordem
void TAB_imp_sim(TAB *a)
{
  if (a)
  {
    TAB_imp_sim(a->esq);
    printf("%d ", a->info);
    TAB_imp_sim(a->dir);
  }
}

//(d) Escreva um algoritmo para efetuar um percurso de pre-ordem
void TAB_imp_pre(TAB *a)
{
  if (a)
  {
    printf("%d ", a->info);
    TAB_imp_pre(a->esq);
    TAB_imp_pre(a->dir);
  }
}

//(f) Escreva um algoritmo para computar o fator de balanceamento de um dado no
int TAB_fator_balanceamento_no(TAB *a, int elem)
{
  TAB *no = TAB_busca(a, elem);
  int fator_balanceamento = calcula_balanceamento(no);
  return fator_balanceamento;
}

//(e) Escreva um algoritmo para computar a altura de um dado no
int TAB_altura_no(TAB *a, int elem)
{
  TAB *no = TAB_busca(a, elem);
  int altura = TAB_altura(no);
  return altura;
}

void imprime_nivel(TAB *a, int level_no)
{
  if (!a)
    return;
  if (level_no == 0)
  {
    printf("%d -> ", a->info);
  }
  else
  {
    imprime_nivel(a->esq, level_no - 1);
    imprime_nivel(a->dir, level_no - 1);
  }
}

//(g) Escreva um algoritmo para percorrer a árvore em níveis
void TAB_percurso_em_niveis(TAB *a)
{
  if (!a)
    return;
  int height = TAB_altura(a) + 1;
  for (int i = 0; i < height; i++)
  {
    printf("Nivel %d: ", i);
    imprime_nivel(a, i);
    printf("\n");
  }
  printf("\n\n-----Impressao completa em niveis:-----\n");
  for (int i = 0; i < height; i++)
  {
    imprime_nivel(a, i);
  }
  printf("\n");
}

//(h) Escreva um algoritmo para computar o produto dos nós
int TAB_produto_nos(TAB *a, int produto)
{
  if (a)
  {

    produto = TAB_produto_nos(a->esq, produto);
    produto *= a->info;
    produto = TAB_produto_nos(a->dir, produto);
  }
  return produto;
}
