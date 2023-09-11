#include <stdio.h>
#include <stdlib.h>

typedef struct PAC {
char nome[30];
int tempo;
}PAC;


typedef struct lse{
  struct lse *prox;
  struct PAC * info;
} TLSE;

TLSE* TLSE_insere(TLSE *l, PAC * novo_paci);
void TLSE_imprime(TLSE *l);
void TLSE_libera(TLSE *l);
TLSE* TLSE_retira(TLSE *l, PAC * paci);
TLSE* TLSE_busca(TLSE * l, PAC *paci);
