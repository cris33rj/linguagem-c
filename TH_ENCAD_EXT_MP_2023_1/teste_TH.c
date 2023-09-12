#include "TH.h"

int main(void){
  int n;
  printf("Digite n (quantidade de matriculas)... ");
  scanf("%d", &n);

  if((n <= 1) || (n > TAM_VET)) return 0;

  TH tab;
  TH_inicializa(tab);

  int i, mat;
  float cr;
  for(i = 0; i < n; i++){
    printf("Digite a matricula e o cr...\n");
    scanf("%d", &mat);
    scanf("%f", &cr);
    TH_insere(tab, mat, cr);
  }
  TH_imprime(tab);

  char resp;
  do{
    printf("Digite a matricula a ser removida... ");
    scanf("%d", &mat);
    cr = TH_retira(tab, mat);
    if(cr != -1) printf("%d\t%f saiu\n", mat, cr);
    printf("Quer continuar? ");
    scanf(" %c", &resp);
  }while((resp != 'N') && (resp != 'n'));
  TH_imprime(tab);

  do{
    printf("\n\n");
    printf("Digite a matricula a ser procurada... ");
    scanf("%d", &mat);
    TA *p = TH_busca(tab, mat);
    if(!p) printf("Elemento nao encontrado!\n");
    else printf("%d\t%f\n", p->mat, p->cr);
    printf("Quer continuar? ");
    scanf(" %c", &resp);
  }while((resp != 'N') && (resp != 'n'));
  TH_imprime(tab);

  TH_libera(tab);
  return 0;
}
