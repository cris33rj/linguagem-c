#include <stdio.h>

int main (void){
  int num, i;
  num = 0;

  for(i=1; i<=1000; i+=2){
    num +=i;
  }

  printf("Soma total: %d",num);


  return 0;

}
