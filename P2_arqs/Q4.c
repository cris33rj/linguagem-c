#include <string.h>
#include "TAB.h"
#include <limits.h>

TAB *maiOr(TAB *t)
{

    if (!t)
        return NULL;

    TAB *maior_esqu = maiOr(t->esq);
    TAB *maior_dire = maiOr(t->dir);
    TAB *resp = t;

    if (maior_esqu && maior_esqu->info > resp->info)
    {
        resp = maior_esqu;
    }

    if (maior_dire && maior_dire->info > resp->info)
    {
        resp = maior_dire;
    }

    return resp;
}

TAB *menor(TAB *t)
{

    if (!t)
        return NULL;

    TAB *menor_esqu = menor(t->esq);
    TAB *menor_dire = menor(t->dir);
    TAB *resp = t;

    if (menor_esqu && menor_esqu->info < resp->info)
    {
        resp = menor_esqu;
    }

    if (menor_dire && menor_dire->info < resp->info)
    {
        resp = menor_dire;
    }

    return resp;
}


int abeABB (TAB* a)
{
    if (!a)
        return 1;

    if (a->esq)
    {
        TAB *maior_esq = maiOr(a->esq);
        if (maior_esq->info > a->info)
        {
            return 0;
        }
    }
    if (a->dir)
    {
        TAB *menor_dir = menor(a->dir);
        if (menor_dir->info < a->info)
        {
            return 0;
        }
    }

    if (!abeABB(a->esq) || !abeABB(a->dir))
        return 0;

    return 1;
}

int main(void){
  int no, pai;
  printf("Digite a raiz da arvore... ");
  scanf("%d", &no);
  TAB *a = TAB_cria(no, NULL, NULL), *resp;
  char repete;
  do{
    char lado[2];
    printf("Quer continuar inserindo nos na árvore (digite N ou n para parar)? ");
    scanf(" %c", &repete);
    if((repete == 'N') || (repete == 'n')) break;
    printf("Digite o pai (que deve existir), o filho a ser inserido e a posição E(ESQ) ou D(DIR)... ");
    scanf("%d%d%s", &pai, &no, lado);
    resp = TAB_busca(a, pai);
    if(!resp){
      TAB_libera(a);
      return 0;
    }
    if(strcmp(lado, "E") == 0) resp->esq = TAB_cria(no, NULL, NULL);
    else resp->dir = TAB_cria(no, NULL, NULL);
  }while(1);
  TAB_imp_ident(a);
  printf("\n");

  printf("%d\n", abeABB(a));
  TAB_libera(a);
  return 0;
}
