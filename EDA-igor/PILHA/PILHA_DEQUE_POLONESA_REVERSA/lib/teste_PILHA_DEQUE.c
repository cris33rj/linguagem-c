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
/* int precedence(char operator)
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
    }

    // if the scanned character is '('
    // push it in the stack
    else if (infix[i] == '(')
    {
      printf("fazendo push linha 73\n");
      // stack[++top] = infix[i];
      PILHA_DEQUE_push(p, infix[i]);
    }

    // if the scanned character is ')'
    // pop the stack and add it to the
    // output string until empty or '(' found
    else if (infix[i] == ')')
    {
      while (!PILHA_DEQUE_vazia(p) && PILHA_DEQUE_topo(p) != '(')
        postfix[j++] = PILHA_DEQUE_pop(p);
      if (!PILHA_DEQUE_vazia(p) && PILHA_DEQUE_topo(p) != '(')
        return "Invalid Expression";
      // else
      // top--;
    }

    // If the scanned character is an operator
    // push it in the stack
    else if (isOperator(infix[i]))
    {
      while (!PILHA_DEQUE_vazia(p) && precedence(PILHA_DEQUE_topo(p)) >= precedence(infix[i]))
        postfix[j++] = PILHA_DEQUE_pop(p);
      PILHA_DEQUE_push(p, infix[i]);
    }
  }

  // Pop all remaining elements from the stack
  while (!PILHA_DEQUE_vazia(p))
  {
    printf("entrou na linha 102\n");
    if (PILHA_DEQUE_topo(p) == '(')
    {
      return "Invalid Expression";
    }
    postfix[j++] = PILHA_DEQUE_pop(p);
  }
  postfix[j] = '\0';
  return postfix;
}
 */

int checkIfOperand(char ch)
{
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char ch)
{
  switch (ch)
  {
  case '+':
  case '-':
    return 1;

  case '*':
  case '/':
    return 2;

  case '^':
    return 3;
  }
  return -1;
}

int covertInfixToPostfix(char *expression)
{
  PILHA_DEQUE *p = PILHA_DEQUE_inicializa();
  int i, j;

  for (i = 0, j = -1; expression[i]; ++i)
  {
    if (checkIfOperand(expression[i]))
    {
      expression[++j] = expression[i];
      printf("operando %c sendo reinserido no vetor da posicao %d para a posicao: %d\n ", expression[i], i, j);
    }

    else if (expression[i] == '(')
    {
      PILHA_DEQUE_push(p, expression[i]);
      printf("elemento %c sendo inserido na pilha\n", expression[i]);
    }

    else if (expression[i] == ')')
    {
      while (!PILHA_DEQUE_vazia(p) && PILHA_DEQUE_topo(p) != '(')
        expression[++j] = PILHA_DEQUE_pop(p);
      if (!PILHA_DEQUE_vazia(p) && PILHA_DEQUE_topo(p) != '(')
        return -1;
      else
        PILHA_DEQUE_pop(p);
    }
    else
    {
      printf("\n");
      printf("%c\n", expression[i]);
      // printf("%c\n", PILHA_DEQUE_topo(p));
      while (!PILHA_DEQUE_vazia(p) && precedence(expression[i]) <= precedence(PILHA_DEQUE_topo(p)))
      {
        printf("a precedencia de %c sera comparada com a precedencia de %c\n", expression[i], PILHA_DEQUE_topo(p));
        expression[++j] = PILHA_DEQUE_pop(p);
      }
      PILHA_DEQUE_push(p, expression[i]);
      printf("push de %c foi feito\n", expression[i]);
    }
  }

  while (!PILHA_DEQUE_vazia(p))
    expression[++j] = PILHA_DEQUE_pop(p);

  expression[++j] = '\0';
  printf("%s", expression);
}

/* int main()
{
  char expression[] = "((x+(y*z))-w)";
  covertInfixToPostfix(expression);
  return 0;
} */

// Driver code
/* int main()
{
  char infix[MAX_EXPR_SIZE] = "a+b*(c^d-e)^(f+g*h)-i";

  // Function call
  // char *postfix = covertInfixToPostfix(infix);
  covertInfixToPostfix(infix);
  // printf("%s\n", postfix);
  // free(postfix);
  return 0; */
}
