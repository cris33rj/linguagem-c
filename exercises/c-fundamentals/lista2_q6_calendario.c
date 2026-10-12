#include <stdio.h>

int main (void){
  float nota1, nota2, nota3;
  char tipo_media;
  float media;

  printf("informe as notas e media selecionada (a-Aritmetica, p-ponderada)\n");
  scanf("%f%f%f %c",&nota1,&nota2,&nota3,&tipo_media);
  //printf("%c",tipo_media);

  if (tipo_media == 'a')
    printf("Media aritmetica = %f\n",(nota1+nota2+nota3)/3);
  else if (tipo_media== 'p')
        printf("Media ponderada = %f\n",(nota1*3+nota2*3+nota3*4)/10);
  else printf("Opcao invalida");



  return 0;

}
