#include <stdio.h>

int main (void){
  int a;
  int b;
  int temp;

  scanf("%d%d",&a,&b);
  printf("%d %d antes da troca\n",a,b);

  temp = a;
  a = b;
  b = temp;

  printf("%d %d depois da troca",a,b);
  return 0;
}
