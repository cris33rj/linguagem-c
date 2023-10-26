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
void TABHASH_inicializa(TABHASH tabela);
TA* TABHASH_busca(TABHASH tabela, int peso);
void TABHASH_insere(TABHASH tabela, int peso, float id);
void TABHASH_libera(TABHASH tabela);
float TABHASH_retira(TABHASH tabela, int peso);
void TABHASH_imprime(TABHASH tabela);
