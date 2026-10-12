#include <stdio.h>
#include <stdlib.h>

int main()
{
   int num=10;
   int i;

   for (i=10; i>1;i--){
    num = num*(i-1);
    printf("Num e %d:\n",num);
   }
   printf("o numero e:%d \n",num);




}
