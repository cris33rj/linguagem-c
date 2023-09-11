#include <stdio.h>
#include <stdlib.h>

typedef struct fila TF;

void TF_insere(TF *f, int elem);
int TF_vazia(TF *f);
void TF_libera(TF *f);
TF *TF_inicializa(void);
int TF_retira(TF *f);
void TF_imprime(TF *f);
TF *TF_cria();
TF *TF_inv_fila(TF *f);
TF *TF_junta_filas(TF *f1, TF *f2);
