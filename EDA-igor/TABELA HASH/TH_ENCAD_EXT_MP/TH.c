#include <float.h>
#include "TH.h"

int TH_hash(int mat){
  return mat % TAM_VET;
}

void TH_inicializa(TH tab){
  int i;
  for(i = 0; i < TAM_VET; i++)tab[i] = NULL;
}

TA* TH_busca(TH tab, int mat){
  int h = TH_hash(mat);
  TA *p = tab[h];
  while((p) && (p->mat != mat)) p = p->prox;
  return p;
}

TA* TH_aloca(int mat, float cr){
  TA *novo = (TA*) malloc (sizeof (TA));
  novo->mat = mat;
  novo->cr = cr;
  novo->prox = NULL;
  return novo;
}

void TH_insere(TH tab, int mat, float cr){
  int h = TH_hash(mat);
  TA *p = tab[h],*ant = NULL;
  while((p) && (p->mat < mat)){
    ant = p;
    p = p->prox;
  }
  if((p) && (p->mat == mat)){
    p->cr = cr;
    return;
  }
  TA *novo = TH_aloca(mat, cr);
  novo->prox = p;
  if(!ant)tab[h] = novo;
  else ant->prox = novo;
}

void TH_libera(TH tab){
  int i;
  for(i = 0; i < TAM_VET; i++)
    if(tab[i]){
      TA *p = tab[i], *q;
      while(p){
        q = p;
        p = p->prox;
        free(q);
      }
    }
}

float TH_retira(TH tab, int mat){
  int h = TH_hash(mat);
  if(!tab[h]) return FLT_MIN;
  TA *p = tab[h],*ant = NULL;
  float cr = FLT_MIN;
  while((p) && (p->mat < mat)){
    ant = p;
    p = p->prox;
  }
  if((!p) || (p->mat != mat)) return cr;
  if(!ant) tab[h] = p->prox;
  else ant->prox = p->prox;
  cr = p->cr;
  free(p);
  return cr;
}

void TH_imprime(TH tab){
  int i;
  for(i = 0; i < TAM_VET; i++){
    printf("%d: ", i);
    if(tab[i]){
      TA *p = tab[i];
      printf("\n");
      while(p){
        printf("\t%d\t%f\t%p\n", p->mat, p->cr, p->prox);
        p = p->prox;
      }
    }
    else printf("NULL\n");
  }
}
