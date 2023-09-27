#include <limits.h>
#include "DEQUE.h"

int menor(DEQUE *f)
{
  if (DEQUE_vazia(f))
    exit(1);
  int resp = DEQUE_retira_inicio(f), prox;
  DEQUE *aux = DEQUE_inicializa();
  while (!DEQUE_vazia(f))
  {
    prox = DEQUE_retira_inicio(f);
    if (resp <= prox)
      DEQUE_insere_fim(aux, prox);
    else
    {
      DEQUE_insere_fim(aux, resp);
      resp = prox;
    }
  }
  // f = aux; NUNCA!!!
  while (!DEQUE_vazia(aux))
    DEQUE_insere_fim(f, DEQUE_retira_inicio(aux));
  DEQUE_libera(aux);
  return resp;
}

void ordena(DEQUE *f)
{
  if (DEQUE_vazia(f))
    return;
  DEQUE *aux = DEQUE_inicializa();
  while (!DEQUE_vazia(f))
    DEQUE_insere_fim(aux, DEQUE_retira_inicio(f));
  while (!DEQUE_vazia(aux))
    DEQUE_insere_fim(f, menor(aux));
  DEQUE_libera(aux);
}

int main(void)
{
  DEQUE *f = DEQUE_inicializa();
  printf("f:\n");
  int n;
  /* while (1)
  {
    scanf("%d", &n);
    if (n < 0)
      break;
    DEQUE_insere_fim(f, n);
  } */
  /*
  DEQUE_retira_inicio(f);
  DEQUE_retira_inicio(f);
  */
  DEQUE_insere_inicio(f, 18);
  DEQUE_insere_fim(f, 17);
  DEQUE_insere_inicio(f, 16);
  DEQUE_insere_fim(f, 15);
  DEQUE_insere_inicio(f, 14);
  DEQUE_insere_fim(f, 13);
  DEQUE_insere_inicio(f, 12);
  DEQUE_insere_fim(f, 11);
  DEQUE_insere_inicio(f, 19);
  DEQUE_insere_fim(f, 20);
  DEQUE_insere_inicio(f, 21);
  DEQUE_insere_fim(f, 22);
  DEQUE_insere_inicio(f, 23);
  DEQUE_insere_fim(f, 24);
  DEQUE_insere_inicio(f, 25);
  DEQUE_insere_fim(f, 26);
  DEQUE_insere_inicio(f, 27);
  // DEQUE_insere_inicio(f, 10);

  //  DEQUE_insere_inicio(f, 3);
  //   DEQUE_insere_inicio(f, 3);
  /* DEQUE_insere_fim(f, 4);
  DEQUE_insere_fim(f, 5);
  DEQUE_insere_inicio(f, 6);
  DEQUE_insere_inicio(f, 7);
  DEQUE_insere_inicio(f, 8);
  DEQUE_insere_inicio(f, 9);
  DEQUE_insere_inicio(f, 10);
  DEQUE_insere_inicio(f, 11); */
  DEQUE_imprime(f);
  printf("\n");
  // ordena(f);
  // DEQUE_imprime(f);
  /* printf("\n");
  DEQUE_retira_inicio(f);
  DEQUE_retira_inicio(f);
  printf("\n");
  ordena(f);
  DEQUE_imprime(f);
  printf("\n");
  DEQUE_retira_fim(f);
  DEQUE_retira_fim(f);
  printf("\n");
  ordena(f);
  DEQUE_imprime(f); */
  DEQUE_libera(f);
  return 0;
}
