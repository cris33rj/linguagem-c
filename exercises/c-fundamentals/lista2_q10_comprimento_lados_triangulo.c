#include <stdio.h>

int main (void){
  float nota1, nota2, nota3;
  char tipo_media;
  float media;

  printf("informe as medidas dos lados do triangulo)\n");
  scanf("%f%f%f",&nota1,&nota2,&nota3);
  //printf("%c",tipo_media);

  if (nota1<=0 || nota2<=0 || nota3<=0)
    printf("Medidas invalidas");
  else if (nota1 == nota2 && nota1 == nota3)
    printf("Triangulo equilatero");
  else if (nota1 != nota2 && nota2 != nota3 && nota3 != nota1 )
    printf("Triangulo escaleno");
  else printf("Triangulo isosceles");

  return 0;

}
