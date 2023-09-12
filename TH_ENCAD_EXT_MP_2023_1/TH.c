#include <float.h>
#include "TH.h"

int TH_hash(int mat){
    printf("\n\n");
    printf("HASH calculado %d\n",mat % TAM_VET);
  return mat % TAM_VET;
}

void TH_inicializa(TH tab){
  int i;
  for(i = 0; i < TAM_VET; i++)tab[i] = NULL;
}

TA* TH_busca(TH tab, int mat){
  int h = TH_hash(mat);
  TA *p = tab[h];
  while((p) && (p->mat != mat)){
        printf("buscando matricula\n");
        printf("MATRICULA ainda nao eh a buscada %d\n",p->mat);
        p = p->prox;
  }
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
    printf("ANT em insere %d\n",ant->mat);
    p = p->prox;
    if (p) printf("PROX em insere %d\n",p->mat );

  }
  if((p) && (p->mat == mat)){
    printf("MATRICULA %d ja existe\n",p->mat);
    p->cr = cr;
    return;
  }
  printf("MATRICULA %d NAO EXISTE. vai ser criada nova\n",mat);
  TA *novo = TH_aloca(mat, cr);
  //P SEMPRE SERAH NULO POIS O WHILE VAI ATE O FINAL DA LISTA ENCADEADA
  novo->prox = p;
  if(p){
  printf("PROXIMA matricula apos essa nova sera %d",p->mat);
    }

  if (!ant){
        printf("INSERCAO, NAO existe ANT, Posicao do vetor preenchida pela primeira vez\n");
        printf("NOVO que ta entrando %d\n",novo->mat);
        tab[h] = novo;
  } else {
      //O PROXIMO DO ANT EH NULO, POR ISSO ELE PODE RECEBER O NOVO NO
      printf("INSERCAO, JAH existe ANT que eh %d\n",ant->mat);
      ant->prox = novo;
  }
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
  //se o p esta na primeira posicao coloca o no depois dele na posicao
  if(!ant) tab[h] = p->prox;
  //se o p nao ta na primeira posicao e tem uma anterior depois dele, entao liga o no anterior ao
  //no depois de p para eliminar depois p
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
