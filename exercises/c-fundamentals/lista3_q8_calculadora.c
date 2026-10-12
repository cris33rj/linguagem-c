#include <stdio.h>

int main (void){
  int num1, num2, op;

  do {
    printf("Informe dois numeros e escolha a operacao.\n1-Somar\t2-Subtrair\t3-Multiplicar\t4-Dividir\t0-Sair\n\n");
    printf("Informe a operacao:\n");
    scanf("%d",&op);

    if(op > 0 && op < 5){
        printf("Digite dois valores: \n");
        scanf("%d%d",&num1,&num2);
    }


    switch(op){
    case 1: printf("Resultado da soma: %d\n\n ",num1+num2); break;
    case 2: printf("Resultado da subtração: %d\n\n ",num1-num2); break;
    case 3: printf("Resultado da soma: %d \n\n",num1*num2); break;
    case 4: if (num2==0){
            printf("Nao pode haver soma por zero\n\n"); continue; }
            else printf("Resultado da divisao: %d \n\n",num1/num2); break;
    case 0: printf("Saindo..."); break;
    default: printf("Operacao invalida. Digite outra opcao\n\n");
    }

  } while(op!=0);





  return 0;

}
