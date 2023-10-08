#include <stdio.h>
#include "DEQUE.h"
int main()
{
    DEQUE *d = DEQUE_cria();

    DEQUE_insere_fim(d, 1);
    DEQUE_insere_fim(d, 2);
    DEQUE_insere_fim(d, 3);
    DEQUE_insere_fim(d, 4);
    DEQUE_insere_fim(d, 5);
    DEQUE_insere_fim(d, 6);
    DEQUE_insere_fim(d, 7);
    DEQUE_insere_fim(d, 8);
    DEQUE_insere_fim(d, 9);

    DEQUE_imprime(d);
}