#include <stdio.h>
#include <stdlib.h>

typedef struct deque
{
  int n, ini, tam;
  int *vet;
}DEQUE;

void DEQUE_insere_fim(DEQUE *f, int elem);
void DEQUE_insere_inicio(DEQUE *f, int elem);
int DEQUE_vazia(DEQUE *f);
void DEQUE_libera(DEQUE *f);
DEQUE *DEQUE_inicializa(void);
int DEQUE_retira_inicio(DEQUE *f);
int DEQUE_retira_fim(DEQUE *f);
void DEQUE_imprime(DEQUE *f);
