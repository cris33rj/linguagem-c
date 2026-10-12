#include "TG.h"

//int teste(TG *g, int origem, int destino, int k);

int main(void){
  TG *g = TG_inicializa();
  int n;
  do{
    scanf("%d", &n);
    if(n <= 0) break;
    g = TG_ins_no(g, n);
  }while(1);
  
  int m;
  do{
    scanf("%d%d", &n, &m);
    if((n <= 0) || (m <= 0)) break;
    TG_ins_aresta(g, n, m);
  }while(1);
  TG_imprime(g);

  int k;
  printf("Digite origem, destino e k... ");
  scanf("%d%d%d", &n, &m, &k);
  //printf("no %d alcanca o no %d em %d arestas? %d\n", n, m, k, teste(g, n, m, k));
  TG_libera(g);
  return 0;
}

