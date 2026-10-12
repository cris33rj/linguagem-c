#include <stdio.h>
#include <stdlib.h>
#include "TF.h"

typedef struct pilha TP;

void TP_push(TP *p, int elem);
int TP_pop(TP *p);
int TP_vazia(TP *p);
TP *TP_inicializa(void);
void TP_libera(TP *p);
void TP_imprime(TP *p);
int TP_topo(TP *p);
void TP_concatena(TP *p1, TP *p2);
TP *TP_copia_com_pilha_auxiliar(TP *p);
TP *TP_copia_com_recursao(TP *p);
TP *f2p(TF *f);
void TP_retira_pares(TP *p);
TF *TF_p2f(TP *p);