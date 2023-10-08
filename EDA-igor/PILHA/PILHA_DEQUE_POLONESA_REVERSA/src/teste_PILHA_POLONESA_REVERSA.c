#include "PILHA_DEQUE.h"
#include <string.h>
#include <ctype.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPR_SIZE 100

int precedence(char operator)
{
  switch (operator)
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

int isOperator(char ch)
{
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

char *infixToPostfix(char *infix)
{
  int i, j;
  int len = strlen(infix);
  char *postfix = (char *)malloc(sizeof(char) * (len + 2));
  PILHA_DEQUE *p = PILHA_DEQUE_inicializa();

  for (i = 0, j = 0; i < len; i++)
  {
    if (infix[i] == ' ' || infix[i] == '\t')
      continue;

    if (isalnum(infix[i]))
    {
      postfix[j++] = infix[i];
    }

    else if (infix[i] == '(')
    {
      PILHA_DEQUE_push(p, infix[i]);
    }

    else if (infix[i] == ')')
    {
      while (!PILHA_DEQUE_vazia(p) && PILHA_DEQUE_topo(p) != '(')
      {
        postfix[j++] = PILHA_DEQUE_pop(p);
      }
      if (!PILHA_DEQUE_vazia(p) && PILHA_DEQUE_topo(p) != '(')
        return "Invalid Expression";
      else
      {
        PILHA_DEQUE_pop(p);
      }
    }

    else if (isOperator(infix[i]))
    {
      while (!PILHA_DEQUE_vazia(p) && precedence(PILHA_DEQUE_topo(p)) >= precedence(infix[i]))
      {
        postfix[j++] = PILHA_DEQUE_pop(p);
      }
      PILHA_DEQUE_push(p, infix[i]);
    }
  }

  while (!PILHA_DEQUE_vazia(p))
  {
    if (PILHA_DEQUE_topo(p) == '(')
    {
      return "Invalid Expression";
    }
    postfix[j++] = PILHA_DEQUE_pop(p);
  }
  postfix[j] = '\0';
  return postfix;
}

int main()
{
  char infix[MAX_EXPR_SIZE] = "a+b*(c^d-e)^(f+g*h)-i";

  char *postfix = infixToPostfix(infix);
  printf("%s\n", postfix);
  free(postfix);
  return 0;
}
