#include <stdio.h>
#include <stdlib.h>

typedef struct fila TF;

void TF_insere(TF *f, char elem);
char TF_retira(TF *f);
int TF_vazia(TF *f);
TF *TF_inicializa(void);
void TF_libera(TF *f);
void TF_imprime(TF *f);
char TF_fim(TF *f);
char TF_inicio(TF *f);
/* void TP_concatena(TP *p1, TP *p2);
TP *TP_copia_com_pilha_auxiliar(TP *p);
TP *TP_copia_com_recursao(TP *p);
TP *f2p(TF *f);
void TP_retira_pares(TP *p);
TF *TF_p2f(TP *p); */