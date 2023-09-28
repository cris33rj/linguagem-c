#include <stdio.h>
#include <stdlib.h>

typedef struct deque
{
  int n, ini, tam;
  char *vet;
}DEQUE;

void DEQUE_insere_fim(DEQUE *f, char elem);
char DEQUE_fim(DEQUE *f);
void DEQUE_insere_inicio(DEQUE *f, char elem);
char DEQUE_inicio(DEQUE *f);
int DEQUE_vazia(DEQUE *f);
void DEQUE_libera(DEQUE *f);
DEQUE *DEQUE_inicializa(void);
char DEQUE_retira_inicio(DEQUE *f);
char DEQUE_retira_fim(DEQUE *f);
void DEQUE_imprime(DEQUE *f);
