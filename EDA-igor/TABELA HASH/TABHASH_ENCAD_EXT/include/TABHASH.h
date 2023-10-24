#include <stdio.h>
#include <stdlib.h>

#define TAM_VET 101

typedef struct paciente{
  int id;
  float peso;
  struct paciente *prox;
}TA;

typedef TA* TABHASH[TAM_VET];

int TABHASH_hash(int peso);
void TABHASH_inicializa(TABHASH tab);
TA* TABHASH_busca(TABHASH tab, int peso);
void TABHASH_insere(TABHASH tab, int peso, float id);
void TABHASH_libera(TABHASH tab);
float TABHASH_retira(TABHASH tab, int peso);
void TABHASH_imprime(TABHASH tab);
