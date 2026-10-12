#include "TLSEV.h"

//IMPLEMENTAR:
//Q3(a)
void TLSEV_insere_ordenado(TLSEV *l, int mat, float nota, char *nome){
}

//Q3(b)
void TLSEV_retira(TLSEV *l, int mat){
}

int main(void){
  int n;
  scanf("%d", &n);
  if(n <= 0) return 0;
  TLSEV *l = TLSEV_inicializa(n);
  int quest, i;
  printf("Digite 0 se a insercao for ordenada... ");
  scanf("%d", &quest);
  int mat;
  float nota;
  char nome[31];
  if(quest){
    for(i = 0; i < n; i++){
      scanf("%d%f", &mat, &nota);
      scanf(" %30[^\n]", nome);
      TLSEV_insere_inicio(l, mat, nota, nome);
    }
  }
  //ÚNICA OPERAÇÃO VÁLIDA => RETIRAR OS COMENTÁRIOS ABAIXO:
  /*
  else{
    for(i = 0; i < n; i++){
      scanf("%d%f", &mat, &nota);
      scanf(" %30[^\n]", nome);
      TLSEV_insere_ordenado(l, mat, nota, nome);
    }
  }
  */
  printf("Lista:\n");
  TLSEV_imprime(l);
  printf("Digite 1 se quiser retirar um elemento... ");
  scanf("%d", &quest);
  //ÚNICA OPERAÇÃO VÁLIDA => RETIRAR OS COMENTÁRIOS ABAIXO:
  /*
  if(quest == 1){
    printf("Digite a matricula do elemento a ser retirado... ");
    scanf("%d", &mat);
    TLSEV_retira(l, mat);
  }
  printf("Depois da retirada de %d...\n", mat);
  TLSEV_imprime(l);
  */
  TLSEV_libera(l);
  return 0;  
}
