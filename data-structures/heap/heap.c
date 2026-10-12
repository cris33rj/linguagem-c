#include <stdio.h>
#include <stdlib.h>

int esq(int ind){
  return (ind * 2 + 1);
}

int dir(int ind){
  return (ind * 2 + 2);
}

int pai(int ind){
  if(ind > 0) return (ind - 1)/2;
  return -1;
}

void max_heapfy(int *vet, int n, int ind){
  printf("\n");
  printf("==>dentro do metodo max_heapfy\n");
  int e = esq(ind), d = dir(ind), maior = ind;
  printf("indice pai: %d -- ind filho esq: %d -- ind filho dir: %d\n" ,ind, esq(ind), dir(ind));
  printf("numero pai: %d -- numero filho esq: %d -- numero filho dir: %d\n" ,vet[ind], vet[e], vet[d]);
  if(e < n && vet[e] > vet[ind]) maior = e;
  if(d < n && vet[d] > vet[maior]) maior = d;
  printf("indice maior eh: %d\n" ,maior);
  printf("numero maior eh: %d\n" ,vet[maior]);
  if(maior != ind){
    printf("indice - troca %d por %d\n ",maior,ind);
    printf("numero - troca %d por %d\n ",vet[maior],vet[ind]);
    int temp = vet[ind];
    vet[ind] = vet[maior];
    vet[maior] = temp;
    printf("depois faz heapfy de novo no indice do filho %d maior e descendo",maior);
    max_heapfy(vet, n, maior);
  } else {
    printf("maior eh %d mesmo. Nao houve nenhuma troca",vet[maior]);
  }

  printf("\n");
}

void build_max_heap(int *v, int n){
  printf("\n");
  printf("===>dentro do metodo build_max_heap\n");
  int i, ultimo_pai = pai(n - 1);
  printf("i:%d -- n:%d -- ultimo pai:%d",pai(n-1),n,pai(n-1));
  for(i = ultimo_pai; i >= 0; i--)
    max_heapfy(v, n, i);
}

void heapsort(int *v, int n){
  printf("\n");
  printf("===>dentro heapsort\n");
  int i;
  printf("vai aplicar build_max_heap no heap\n");
  build_max_heap(v, n);
  for(i = n - 1; i >= 1; i--){
    printf("trocando o ultimo elemento %d pelo primeiro elemento %d\n",v[i],v[0]);
    int temp = v[i];
    v[i] = v[0];
    v[0] = temp;
    printf("vai aplicar o max_heapfy no 0 passando n como:%d\n",i);
    //COMECA NO N IGUAL 3 E DEPOIS VAI APLICAR O HEAPSORT NO N = 2 ATE CHEGAR A 1
    max_heapfy(v, i, 0);
  }
}

int main(void){
  int *vet, n, i = 0;
  printf("Digite o tamanho do vetor de elementos a serem ordenados... ");
  scanf("%d",&n);
  if(n <= 0) return 0;
  vet = (int *) malloc(sizeof(int) * n);

  for(i = 0; i < n; i++) vet[i] = rand() % n;

  printf("Antes de ordenar com heapsort...\n");
  for(i = 0; i < n; i++) printf("%d ", vet[i]);
  printf("\n");

  heapsort(vet, n);

  printf("Depois de ordenar com heapsort...\n");
  for(i = 0; i < n; i++) printf("%d ", vet[i]);
  printf("\n");

  free(vet);
  return 0;
}
