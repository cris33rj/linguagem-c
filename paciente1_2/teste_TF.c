#include <limits.h>
#include <string.h>
#include "TF.h"


PAC * menor(TF *f){
  if(TF_vazia(f)) exit(1);
  PAC * resp = TF_retira(f);
  PAC * prox;
  TF *aux = TF_inicializa();
  while(!TF_vazia(f)){
     prox =  TF_retira(f);
    if(resp->tempo <= prox->tempo)
        TF_insere(aux, prox);
    else{
      TF_insere(aux, resp);
      resp = prox;
    }
  }
  //f = aux; NUNCA!!!
  while(!TF_vazia(aux)) TF_insere(f, TF_retira(aux));
  TF_libera(aux);
  return resp;
}

void ordena(TF *f){
  if(TF_vazia(f)) return;
  TF *aux = TF_inicializa();
  while(!TF_vazia(f)) TF_insere(aux, TF_retira(f));
  while(!TF_vazia(aux)) TF_insere(f, menor(aux));
  TF_libera(aux);
}

//TF * atendeFilaHospital(TF * f, TP * p){
//ordena(f);
//TP * aux1; TP * aux2;
//while(!TF_vazia(f)) TP_push(aux1,TF_retira(f));
//while(!TF_vazia(aux1)) TP_push(aux2,TF_retira(aux1));
//printf("IMPRIMINDO PILHA NA MESMA ORDEM DA FILA;");
//TP_imprime(aux2);
//TP_libera(aux1);
//TP_libera(aux2);
//return f;
//}

int main(void){
  TF *f1 = TF_inicializa();
  printf("CRIANDO PACIENTES:\n");
  PAC * paciente1 = (PAC * ) malloc(sizeof(PAC));
  strcpy (paciente1->nome,"carlos");
  paciente1->tempo = 70;
  TF_insere(f1, paciente1);

 // printf("INSERIU PACIENTE 1\n");

//  PAC * paciente2 = (PAC * ) malloc(sizeof(PAC));
//  strcpy (paciente2->nome,"beatriz");
//  paciente2->tempo = 80;
//  TF_insere(f1, paciente2);
//  printf("INSERIU PACIENTE 2\n");
//
//  PAC * paciente3 = (PAC * ) malloc(sizeof(PAC));
//  strcpy (paciente3->nome,"chico");
//  paciente3->tempo = 60;
//  TF_insere(f1, paciente3);
//
//  printf("INSERIU PACIENTE 3\n");
//
//  PAC * paciente4 = (PAC * ) malloc(sizeof(PAC));
//  strcpy (paciente4->nome,"beto");
//  paciente4->tempo = 90;
//  TF_insere(f1, paciente4);
//
//  printf("INSERIU PACIENTE 4\n");

TF_imprime(f1);
//ordena(f1);
//TF_imprime(f1);
//printf("IMPRIMIU TUDO");
 // printf("\n");
TF_libera(f1);



  return 0;
}
