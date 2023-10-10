#include <stdio.h>
#include <stdlib.h>

typedef struct arvore
{
  int info;
  struct arvore *esq, *dir;  ;
} TAB;

TAB *TAB_inicializa(void);
TAB *TAB_cria(int raiz, TAB *esq, TAB *dir);
void TAB_imp_pre(TAB *a);
void TAB_imp_pos(TAB *a);
void TAB_imp_sim(TAB *a);
void TAB_libera(TAB *a);
TAB *TAB_busca(TAB *a, int elem);
int TAB_altura(TAB *a);
int TAB_soma_nos_folhas(TAB *a, int soma);
int TAB_altura_no(TAB *a, int elem);
int TAB_fator_balanceamento_no(TAB *a, int elem);
int TAB_produto_nos(TAB *a,int produto);
void TAB_percurso_em_niveis(TAB *a);
