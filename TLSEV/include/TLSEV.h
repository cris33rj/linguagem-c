#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  int info, prox;
}TNO;

typedef struct lsev{
  int n, ppl, prim, nelem;
  TNO ** vet;
}TLSEV;

TLSEV *TLSEV_inicializa(void);
TNO * TLSEV_busca(TLSEV *l, int elem);
void TLSEV_insere(TLSEV *l, int elem);
void TLSEV_imprime(TLSEV *l);
void TLSEV_libera(TLSEV *l);
void TLSEV_retira(TLSEV *l, int elem);
