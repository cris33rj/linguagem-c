#include <stdio.h>
#include <stdlib.h>

typedef struct arvbin
{
  int info;
  struct arvbin *esq, *dir;
  int cor;
} TAB;

TAB *TAB_inicializa(void);
TAB *TAB_cria(int raiz, TAB *esq, TAB *dir);
void TAB_imp_pre(TAB *a);
void TAB_imp_pos(TAB *a);
void TAB_imp_sim(TAB *a);
void TAB_imp_ident(TAB *a);
void TAB_libera(TAB *a);
TAB *TAB_busca(TAB *a, int elem);
TAB *TAB_copia(TAB *a);
TAB *TAB_espelho(TAB *a);
TAB *TAB_maior(TAB *a);
TAB *TAB_menor(TAB *a);
int TAB_igual(TAB *a1, TAB *a2);
TAB *TAB_retira_pares(TAB *arv);
void TAB_colore(TAB *arv);
int TAB_ni(TAB *a);
int TAB_nf(TAB *a);
void TAB_imp_ident_cor(TAB * a);
