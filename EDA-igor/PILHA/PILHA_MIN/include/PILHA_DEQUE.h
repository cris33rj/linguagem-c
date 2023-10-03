#include <stdio.h>
#include <stdlib.h>

typedef struct pilha PILHA_DEQUE;

void PILHA_DEQUE_push(PILHA_DEQUE *p, int elem);
int PILHA_DEQUE_pop(PILHA_DEQUE *p);
int PILHA_DEQUE_vazia(PILHA_DEQUE *p);
PILHA_DEQUE *PILHA_DEQUE_inicializa(void);
void PILHA_DEQUE_libera(PILHA_DEQUE *p);
void PILHA_DEQUE_imprime(PILHA_DEQUE *p);
int PILHA_DEQUE_topo(PILHA_DEQUE *p);
int PILHA_DEQUE_obter_minimo(PILHA_DEQUE *p);
/* void PILHA_DEQUE_concatena(PILHA_DEQUE *p1, PILHA_DEQUE *p2);
PILHA_DEQUE *PILHA_DEQUE_copia_com_pilha_auxiliar(PILHA_DEQUE *p);
PILHA_DEQUE *PILHA_DEQUE_copia_com_recursao(PILHA_DEQUE *p);
PILHA_DEQUE *f2p(TF *f);
void PILHA_DEQUE_retira_pares(PILHA_DEQUE *p);
TF *TF_p2f(PILHA_DEQUE *p); */