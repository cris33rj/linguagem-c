#include "PILHA_DEQUE.h"
#include <string.h>
#include <ctype.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPR_SIZE 100

int precedencia(char operador)
{
  switch (operador)
  {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case '^':
    return 3;
  default:
    return -1;
  }
}

int isOperador(char ch)
{
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void polonesa(char *expressao, int N, char *saida_polonesa)
{
  int i, j;
  PILHA_DEQUE *p = PILHA_DEQUE_inicializa();

  for (i = 0, j = 0; i < N; i++)
  {
    if (expressao[i] == ' ' || expressao[i] == '\t')
      continue;

    if (isalnum(expressao[i]))
    {
      saida_polonesa[j++] = expressao[i];
    }

    else if (expressao[i] == '(')
    {
      PILHA_DEQUE_push(p, expressao[i]);
    }

    else if (expressao[i] == ')')
    {
      while (!PILHA_DEQUE_vazia(p) && PILHA_DEQUE_topo(p) != '(')
      {
        saida_polonesa[j++] = PILHA_DEQUE_pop(p);
      }
      if (!PILHA_DEQUE_vazia(p) && PILHA_DEQUE_topo(p) != '(')
        printf("Expressao invalida\n");
      else
      {
        PILHA_DEQUE_pop(p);
      }
    }

    else if (isOperador(expressao[i]))
    {
      while (!PILHA_DEQUE_vazia(p) && precedencia(PILHA_DEQUE_topo(p)) >= precedencia(expressao[i]))
      {
        saida_polonesa[j++] = PILHA_DEQUE_pop(p);
      }
      PILHA_DEQUE_push(p, expressao[i]);
    }
  }

  while (!PILHA_DEQUE_vazia(p))
  {
    if (PILHA_DEQUE_topo(p) == '(')
    {
      printf("Expressao invalida\n");
    }
    saida_polonesa[j++] = PILHA_DEQUE_pop(p);
  }
  saida_polonesa[j] = '\0';
}

int main()
{
  char expressao[MAX_EXPR_SIZE] = "((A+B)*(C-(F/D)))";
  int N = strlen(expressao);

  char *saida_polonesa = (char *)malloc(sizeof(char) * (N + 2));
  polonesa(expressao, N, saida_polonesa);
  printf("Imprimindo expressao original:\n");
  printf("%s\n", expressao);
  printf("\n");

  printf("Imprimindo saida em notacao polonesa reversa:\n");
  printf("%s\n", saida_polonesa);

  free(saida_polonesa);
  return 0;
}
