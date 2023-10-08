#include <stdio.h>
#include <stdlib.h>

typedef struct pilhaMin PILHA_DEQUE;

void PILHA_DEQUE_push(PILHA_DEQUE *p, int elem);
int PILHA_DEQUE_pop(PILHA_DEQUE *p);
int PILHA_DEQUE_vazia(PILHA_DEQUE *p);
PILHA_DEQUE *PILHA_DEQUE_inicializa(void);
void PILHA_DEQUE_libera(PILHA_DEQUE *p);
void PILHA_DEQUE_imprime(PILHA_DEQUE *p);
int PILHA_DEQUE_topo(PILHA_DEQUE *p);
int PILHA_DEQUE_obter_minimo(PILHA_DEQUE *p);
