#include "PILHA_DEQUE.h"
#include <string.h>
#include <ctype.h>
/*
 typedef struct pilha PILHA_DEQUE;
 PILHA_DEQUE *PILHA_DEQUE_inicializa (void);
 void PILHA_DEQUE_push (PILHA_DEQUE *p, int v);
 int PILHA_DEQUE_pop (PILHA_DEQUE *p);
 int PILHA_DEQUE_vazia (PILHA_DEQUE *p);
 void PILHA_DEQUE_libera (PILHA_DEQUE *p);
*/

// C code to convert infix to postfix expression

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPR_SIZE 100

// Function to return precedence of operators
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

// Function to check if the scanned character
// is an operator
int isOperator(char ch)
{
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Main functio to convert infix expression
// to postfix expression
char *infixToPostfix(char *infix)
{
  int i, j;
  int len = strlen(infix);
  char *postfix = (char *)malloc(sizeof(char) * (len + 2));
  // char stack[MAX_EXPR_SIZE];
  PILHA_DEQUE *p = PILHA_DEQUE_inicializa();
  // int top = -1;

  for (i = 0, j = 0; i < len; i++)
  {
    if (infix[i] == ' ' || infix[i] == '\t')
      continue;

    // If the scanned character is operand
    // add it to the postfix expression
    if (isalnum(infix[i]))
    {
      postfix[j++] = infix[i];
      printf("inseriu %c da posicao %d de infix na posicao %d de postifx\n", infix[i], i, j - 1);
    }

    // if the scanned character is '('
    // push it in the stack
    else if (infix[i] == '(')
    {
      printf("fazendo push de '(' na pilha \n");
      // stack[++top] = infix[i];
      PILHA_DEQUE_push(p, infix[i]);
    }

    // if the scanned character is ')'
    // pop the stack and add it to the
    // output string until empty or '(' found
    else if (infix[i] == ')')
    {
      printf("Encontrou fechamento de parentes ')' na pilha. Vai retirar elementos ate chegar em '('\n");
      while (!PILHA_DEQUE_vazia(p) && PILHA_DEQUE_topo(p) != '(')
      {
        printf("Vai retirar %c da pilha\n", PILHA_DEQUE_topo(p));
        postfix[j++] = PILHA_DEQUE_pop(p);
      }
      if (!PILHA_DEQUE_vazia(p) && PILHA_DEQUE_topo(p) != '(')
        return "Invalid Expression";
      else
      {
        printf("Retirou %c da pilha na linha 93\n", PILHA_DEQUE_topo(p));
        PILHA_DEQUE_pop(p);
      }
    }

    // If the scanned character is an operator
    // push it in the stack
    else if (isOperator(infix[i]))
    {
      while (!PILHA_DEQUE_vazia(p) && precedence(PILHA_DEQUE_topo(p)) >= precedence(infix[i]))
      {
        printf("Tentou inserir %c (posicao %d) na pilha mas encontrou %c que tem maior ou igual precedencia \n ", infix[i], i, PILHA_DEQUE_topo(p));
        // printf("A precedencia do topo(%c) foi comparada com a precedencia de infix na posicao %d eh %c\n", PILHA_DEQUE_topo(p), i, infix[i]);
        printf("Elemento %c retirada da pilha e inserido na posicao %d de postfix \n ", PILHA_DEQUE_topo(p), j + 1);
        postfix[j++] = PILHA_DEQUE_pop(p);
      }
      PILHA_DEQUE_push(p, infix[i]);
      printf("Visto que não foi encontrado elemento com maior ou igual precedencia que %c (posicao %d de infix), ele foi inserido na pilha\n", infix[i], i);
    }
  }

  // Pop all remaining elements from the stack
  while (!PILHA_DEQUE_vazia(p))
  {
    if (PILHA_DEQUE_topo(p) == '(')
    {
      return "Invalid Expression";
    }
    printf("o elemento %c que restou na pilha foi inserido em postfix\n", PILHA_DEQUE_topo(p));
    postfix[j++] = PILHA_DEQUE_pop(p);
  }
  postfix[j] = '\0';
  return postfix;
}

// Driver code
int main()
{
  char infix[MAX_EXPR_SIZE] = "a+b*(c^d-e)^(f+g*h)-i";

  // Function call
  char *postfix = infixToPostfix(infix);
  printf("%s\n", postfix);
  free(postfix);
  return 0;
}
