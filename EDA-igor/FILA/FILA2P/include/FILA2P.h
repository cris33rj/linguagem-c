#include <stdio.h>
#include <stdlib.h>

typedef struct fila FILA2P;

void FILA2P_insere(FILA2P *f, char elem);
char FILA2P_retira(FILA2P *f);
int FILA2P_vazia(FILA2P *f);
FILA2P *FILA2P_inicializa(void);
void FILA2P_libera(FILA2P *f);
void FILA2P_imprime(FILA2P *f);
char FILA2P_inicio(FILA2P *f);
/* void TP_concatena(TP *p1, TP *p2);
TP *TP_copia_com_pilha_auxiliar(TP *p);
TP *TP_copia_com_recursao(TP *p);
TP *f2p(FILA_DEQUE *f);
void TP_retira_pares(TP *p);
FILA_DEQUE *FILA_DEQUE_p2f(TP *p); */