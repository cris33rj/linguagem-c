#include <stdio.h>
#include <stdlib.h>

#define TAM_VET 101

typedef struct aluno{
  int mat;
  float cr;
  struct aluno *prox;
}TA;

typedef TA* TH[TAM_VET];

int TH_hash(int mat);
void TH_inicializa(TH tab);
TA* TH_busca(TH tab, int mat);
void TH_insere(TH tab, int mat, float cr);
void TH_libera(TH tab);
float TH_retira(TH tab, int mat);
void TH_imprime(TH tab);
