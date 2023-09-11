#include <stdio.h>

int main (void){
  int num, div2, div3, div5;

  div2 = 0;
  div3 = 0;
  div5 = 0;

  printf("informe seu peso e altura");
  scanf("%d",&num);

  if (num%2 == 0)
    div2 = 2;
  if (num%3 == 0)
    div3 = ;
  if (num%5 == 0)
    div5 = 1;

  switch(num)
  if (div2)
    printf("o numero %d e divisivel por %d",num,2);
  if (div3)
    printf("o numero %d e divisivel por %d",num,3);
  if (div5)
    printf("o numero %d e divisivel por %d",num,3);
  if (div2 && div3)
    printf("o numero %d e divisivel por %d e %d",num,2,3);
  if (div2 && div5)
    printf("o numero %d e divisivel por %d e %d",num,2,5);
  if (div3 && div5)
    printf("o numero %d e divisivel por %d e %d",num,3,5);
  if (div3 && div5 && div2)
    printf("o numero %d e divisivel por %d e %d e %d",num,2,3,5);





  return 0;

}
