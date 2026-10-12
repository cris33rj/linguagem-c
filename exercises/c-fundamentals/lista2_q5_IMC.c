#include <stdio.h>

int main (void){
  float peso;
  float altura;
  float IMC;




  printf("informe seu peso e altura");
  scanf("%f%f",&peso,&altura);

  IMC = peso/(altura*altura);
  printf("%f",IMC);

  if (IMC < 18.5)
    printf("IMC: %f\tAbaixo do peso\n",IMC);
  if (IMC >= 18.5 && IMC < 25)
    printf("IMC: %f\tPeso normal\n",IMC);
  if (IMC >= 25 && IMC < 30)
    printf("IMC: %f\tSobrepeso\n",IMC);
  if (IMC >= 30 && IMC < 35)
    printf("IMC: %f\tObesidade grau 1\n",IMC);
  if (IMC >= 35 && IMC < 40)
    printf("IMC: %f\tObesidade grau 2\n",IMC);
  if (IMC >=40){
    printf("IMC: %f\tObesidade grau 3\n",IMC);

  }

//  if (IMC < 18.5)
//    printf("IMC: %f\tAbaixo do peso\n",IMC);
//  else if (IMC >= 18.5 && IMC < 25)
//    printf("IMC: %f\tPeso normal\n",IMC);
//  else if (IMC >= 25 && IMC < 30)
//    printf("IMC: %f\tSobrepeso\n",IMC);
//  else if (IMC >= 30 && IMC < 35)
//    printf("IMC: %f\tObesidade grau 1\n",IMC);
//  else if (IMC >= 35 && IMC < 40)
//    printf("IMC: %f\tObesidade grau 2\n",IMC);
//  else if (IMC >=40){
//    printf("IMC: %f\tObesidade grau 3\n",IMC);
//
//  }

//  if (IMC < 18.5){
//        printf("IMC: %f\tAbaixo do peso\n",IMC);
//  }else{ if (IMC >= 18.5 && IMC < 25)
//    {printf("IMC: %f\tPeso normal\n",IMC);}}
//  else{ if (IMC >= 25 && IMC < 30)
//    {printf("IMC: %f\tSobrepeso\n",IMC);}}
//  else{ if (IMC >= 30 && IMC < 35)
//    {printf("IMC: %f\tObesidade grau 1\n",IMC);}}
//  else { if (IMC >= 35 && IMC < 40)
//    {printf("IMC: %f\tObesidade grau 2\n",IMC);}}
//  else{ if (IMC >=40)
//    {printf("IMC: %f\tObesidade grau 3\n",IMC);}}

//  }


//  if (IMC < 18.5){
//    printf("IMC: %f\tAbaixo do peso\n",IMC);}
//  else{if (IMC >= 18.5 && IMC < 25) {
//    printf("IMC: %f\tPeso normal\n",IMC);}}
//  else if (IMC >= 25 && IMC < 30)
//    printf("IMC: %f\tSobrepeso\n",IMC);
//  else if (IMC >= 30 && IMC < 35)
//    printf("IMC: %f\tObesidade grau 1\n",IMC);
//  else if (IMC >= 35 && IMC < 40)
//    printf("IMC: %f\tObesidade grau 2\n",IMC);
//  else if (IMC >=40){
//    printf("IMC: %f\tObesidade grau 3\n",IMC);








  return 0;

}
