#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  int info;
  struct no *prox;
}TNO;

typedef struct lsed{
  int nelem;
  TNO *ini, *fim;
}TLSED;

TLSED* TLSED_inicializa(void);
void TLSED_ins_ini(TLSED *l, int elem);
void TLSED_imprime(TLSED *l);
void TLSED_libera(TLSED *l);
TNO* TLSED_busca(TLSED *l, int elem);
void TLSED_retira(TLSED *l, int elem);

