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
  DEQUE_insere_inicio(f, 'a');
  DEQUE_insere_fim(f, 'b');
  DEQUE_insere_inicio(f, 'c');
  DEQUE_insere_fim(f, 'e');
  DEQUE_insere_inicio(f, 'f');
  DEQUE_insere_fim(f, 'g');
  DEQUE_insere_inicio(f, 'h');
  DEQUE_insere_fim(f, 'i');
  DEQUE_insere_inicio(f, 'j');
  DEQUE_insere_fim(f, 'l');
  DEQUE_insere_inicio(f, 'm');
  DEQUE_insere_fim(f, 'n');
  DEQUE_insere_inicio(f, 'o');
  DEQUE_insere_fim(f, 'p');
  DEQUE_insere_inicio(f, 'q');
  DEQUE_insere_fim(f, 'r');
  DEQUE_insere_inicio(f, 's');
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
  // printf("\n");
  DEQUE_retira_inicio(f);
  DEQUE_retira_inicio(f);
  printf("\n");
  // ordena(f);
  DEQUE_imprime(f);
  printf("\n");
  DEQUE_retira_fim(f);
  DEQUE_retira_fim(f);
  printf("\n");
  // ordena(f);
  DEQUE_imprime(f);
  DEQUE_libera(f);
  return 0;
}
