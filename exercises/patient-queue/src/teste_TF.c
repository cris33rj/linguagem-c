#include <limits.h>
#include <string.h>
#include "TF.h"
#include "TP.h"

PAC *menor(TF *f)
{
  if (TF_vazia(f))
    exit(1);
  PAC *resp = TF_retira(f);
  PAC *prox;
  TF *aux = TF_inicializa();
  while (!TF_vazia(f))
  {
    prox = TF_retira(f);
    if (resp->tempo <= prox->tempo)
      TF_insere(aux, prox);
    else
    {
      TF_insere(aux, resp);
      resp = prox;
    }
  }
  // f = aux; NUNCA!!!
  while (!TF_vazia(aux))
    TF_insere(f, TF_retira(aux));
  TF_libera(aux);
  return resp;
}

void ordena(TF *f)
{
  if (TF_vazia(f))
    return;
  TF *aux = TF_inicializa();
  while (!TF_vazia(f))
    TF_insere(aux, TF_retira(f));
  while (!TF_vazia(aux))
    TF_insere(f, menor(aux));
  TF_libera(aux);
}

TF *atendeFilaHospital(TF *f, TP *p)
{
  ordena(f);
  TP *aux1 = TP_inicializa();

  while (!TF_vazia(f))
    TP_push(aux1, TF_retira(f));
  while (!TP_vazia(aux1))
    TP_push(p, TP_pop(aux1));

  printf("IMPRIMINDO PILHA NA MESMA ORDEM DA FILA\n");
  TP_imprime(p);

  while (!TP_vazia(p))
    TF_insere(f, TP_pop(p));

  TP_libera(aux1);
  TP_libera(p);
  return f;
}

PAC *menor_tempo(TF *f, int t)
{
  if (TF_vazia(f))
    exit(1);
  PAC *menor_tempo = NULL;
  PAC *prox = NULL;
  TF *aux = TF_inicializa();
  while (!TF_vazia(f))
  {
    prox = TF_retira(f);
    if (prox->tempo <= t)
      menor_tempo = prox;
    TF_insere(aux, prox);
  }
  // f = aux; NUNCA!!!
  while (!TF_vazia(aux))
    TF_insere(f, TF_retira(aux));
  TF_libera(aux);
  if (!menor_tempo)
  {
    return NULL;
  }
  else
    return menor_tempo;
}

int main(void)
{
  TP *p1 = TP_inicializa();
  TF *f1 = TF_inicializa();
  printf("CRIANDO PACIENTES:\n");
  PAC *paciente1 = (PAC *)malloc(sizeof(PAC));
  strcpy(paciente1->nome, "carlos");
  paciente1->tempo = 70;
  TF_insere(f1, paciente1);

  PAC *paciente2 = (PAC *)malloc(sizeof(PAC));
  strcpy(paciente2->nome, "beatriz");
  paciente2->tempo = 80;
  TF_insere(f1, paciente2);

  PAC *paciente3 = (PAC *)malloc(sizeof(PAC));
  strcpy(paciente3->nome, "chico");
  paciente3->tempo = 60;
  TF_insere(f1, paciente3);

  PAC *paciente4 = (PAC *)malloc(sizeof(PAC));
  strcpy(paciente4->nome, "beto");
  paciente4->tempo = 90;
  TF_insere(f1, paciente4);

  printf("IMPRIMINDO LISTA ORIGINAL\n");
  TF_imprime(f1);
  printf("\n");
  atendeFilaHospital(f1, p1);
  printf("\n");
  printf("IMPRIMINDO FILA ORDENADA\n");
  TF_imprime(f1);
  printf("\n");
  // printf("IMPRIMIU TUDO");
  //  printf("\n");
  int tempo = 85;
  PAC *paciente_menor_tempo = menor_tempo(f1, tempo);
  printf("PACIENTE COM MENOR TEMPO:\n");
  if (!paciente_menor_tempo)
    printf("Nao ha paciente com tempo menor que %d", tempo);
  else
    printf("%s --> %d", paciente_menor_tempo->nome, paciente_menor_tempo->tempo);
  free(paciente_menor_tempo);
  TF_libera(f1);
  // TF_libera(f2);

  return 0;
}
