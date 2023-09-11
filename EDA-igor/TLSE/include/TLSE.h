#include <stdio.h>
#include <stdlib.h>

typedef struct lse
{
  int info;
  struct lse *prox;
} TLSE;
TLSE *TLSE_inicializa();
TLSE *TLSE_insere(TLSE *l, int elem);
void TLSE_imprime(TLSE *l);
void TLSE_libera(TLSE *l);
TLSE *TLSE_retira(TLSE *l, int elem);
TLSE *TLSE_busca(TLSE *l, int elem);

void TLSE_imp_rec(TLSE *l);
void TLSE_imp_rec_rev(TLSE *l);
void TLSE_lib_rec(TLSE *l);
TLSE *TLSE_busca_rec(TLSE *l, int elem);
TLSE *TLSE_retira_rec(TLSE *l, int elem);
void TLSE_inverte(TLSE **l);
TLSE *TLSE_copia_inverte_retorna(TLSE *l);
TLSE *TLSE_copia(TLSE *l);
TLSE *TLSE_inverte_com_retorno(TLSE *l);
TLSE *TLSE_desloca(TLSE *l, int n);
TLSE *TLSE_rto(TLSE *l, int elem);
TLSE *TLSE_i_p(TLSE *l);
TLSE *TLSE_insere_no_fim(TLSE *l, int elem);
int TLSE_igual(TLSE *l1, TLSE *l2);
TLSE *TLSE_junta_listas(TLSE *l1, TLSE *l2);
int TLSE_contrario(TLSE *l1, TLSE *l2);
int TLSE_comprimento(TLSE *l1);
TLSE *TLSE_ultimo(TLSE *l);
TLSE *TLSE_separa(TLSE *l, int x);
TLSE *TLSE_merge_intercala(TLSE *l1, TLSE *l2);
void TLSE_insereDepois(TLSE *l, int data, int x);
TLSE *TLSE_insereAntes(TLSE *l, int data, int x);
TLSE *TLSE_insereNaPosicao(TLSE *l, int data, int k);
TLSE *TLSE_eliminaRepetidos(TLSE *l, int data, int k);
void TLSE_misc(TLSE *l, int x);
