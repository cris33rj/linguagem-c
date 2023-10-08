#include <stdio.h>
#include <stdlib.h>

typedef struct fila FILA_DEQUE;

void FILA_DEQUE_insere(FILA_DEQUE *f, char elem);
char FILA_DEQUE_retira(FILA_DEQUE *f);
int FILA_DEQUE_vazia(FILA_DEQUE *f);
FILA_DEQUE *FILA_DEQUE_inicializa(void);
void FILA_DEQUE_libera(FILA_DEQUE *f);
void FILA_DEQUE_imprime(FILA_DEQUE *f);
char FILA_DEQUE_fim(FILA_DEQUE *f);
char FILA_DEQUE_inicio(FILA_DEQUE *f);
