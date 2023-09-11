#include "stdio.h"


int main()
{
  int x, y, z;
  int teste;
  x = 5;
  y = x++;
  z = x--;

  printf("imprimindo %d%d%d\n",x,y,z);

  printf("%d\n",!y == !x);
  printf("%d\n",(x++ > y) || (--z <= y));
  printf("%d\n",(!x) || (!(!z)));
  printf("%d\n",((x + y) > z) && (x++));
  printf("%d\n",x && y + !3 || 4);
  printf("%d\n",x && y);
  printf("%d\n",!3 || 4);
  printf("%d\n",1 + 1);

    return 0;
}
