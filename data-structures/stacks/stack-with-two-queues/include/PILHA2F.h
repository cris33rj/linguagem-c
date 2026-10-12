#include <stdio.h>
#include <stdlib.h>

typedef struct pilha PILHA2F;

void PILHA2F_push(PILHA2F *p, char elem);
char PILHA2F_pop(PILHA2F *p);
int PILHA2F_vazia(PILHA2F *p);
PILHA2F *PILHA2F_inicializa(void);
void PILHA2F_libera(PILHA2F *p);
void PILHA2F_imprime(PILHA2F *p);
char PILHA2F_topo(PILHA2F *p);
/* void TP_concatena(TP *p1, TP *p2);
TP *TP_copia_com_pilha_auxiliar(TP *p);
TP *TP_copia_com_recursao(TP *p);
TP *f2p(FILA_DEQUE *f);
void TP_retira_pares(TP *p);
FILA_DEQUE *FILA_DEQUE_p2f(TP *p); */