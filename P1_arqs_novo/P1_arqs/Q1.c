#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa{
  int mat;
  char data_nasc[9];
  char nome[31];
}TP;

//TP* retira_k(TP **vet, int* n, int k);

int main(void){
  int n;
  printf("Digite o tamanho do vetor... ");
  scanf("%d", &n);
  if(n <= 0) return 0;
  TP* elem, *vet[n];
  int i = 0;
  while(i < n){
    elem = (TP *) malloc(sizeof(TP));
    printf("Digite os dados (insc, nota, data e nome) do candidato...\n");
    scanf("%d", &elem->mat);
    scanf(" %10[^\n]", elem->data_nasc);
    scanf(" %30[^\n]", elem->nome);
    vet[i++] = elem;
  }
  printf("Digite a posicao do elemento a ser retirado... ");
  int k;
  scanf("%d", &k);
  elem = NULL;
  //elem = retira_k(vet, &n, k);
  free(elem);
  printf("Depois de retira_k:\n");
  for(i = 0; i < n; i++) 
    if(vet[i]) printf("%d %s %s\n", vet[i]->mat, vet[i]->data_nasc, vet[i]->nome);
  for(i = 0; i < n; i++) 
    free(vet[i]);
  return 0; 
}
