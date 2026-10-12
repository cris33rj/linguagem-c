#include <stdio.h>

int main (void){
  int num;

  do{
      printf("Informe a senha");
      scanf("%d",&senha);

  }while(senha != 123456);

  printf("Acesso permitido");

  return 0;

}
