#include <stdio.h>
#include <stdlib.h>
#include "TLSE.h"



typedef struct fila TF;


void TF_insere(TF *f, PAC * paci);
int TF_vazia(TF *f);
void TF_libera(TF *f);
TF *TF_inicializa(void);
PAC * TF_retira(TF *f);
void TF_imprime(TF *f);
