typedef struct deque
{
    int n, inicio, fim, dim, ini;
    int *vet;

} DEQUE;
DEQUE *DEQUE_cria(void);
void DEQUE_insere_ini(DEQUE *f, int v);
void DEQUE_insere_fim(DEQUE *f, int v);
int DEQUE_retira_ini(DEQUE *f);
int DEQUE_retira_fim(DEQUE *f);
int DEQUE_vazia(DEQUE *f);
void DEQUE_libera(DEQUE *f);
void DEQUE_imprime(DEQUE *f);
