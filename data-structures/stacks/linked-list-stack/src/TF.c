#include "TLSE.h"
#include "TF.h"
#include "TP.h"

struct fila
{
	TLSE *ini;
	TLSE *fim;
};

TF *TF_inicializa(void)
{
	TF *f = (TF *)malloc(sizeof(TF));
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

int TF_vazia(TF *f)
{
	return !(f->ini); // 1 se vazia , 0 caso contrário
}

void TF_insere(TF *f, int elem)
{
	TLSE *novo = (TLSE *)malloc(sizeof(TLSE));
	novo->info = elem;
	novo->prox = NULL; // INSERÇÃO NO FIM
	if (!TF_vazia(f))
		f->fim->prox = novo;
	else
		f->ini = novo;
	f->fim = novo;
}

int TF_retira(TF *f)
{
	if (TF_vazia(f))
		exit(1);

	int resp = f->ini->info;

	TLSE *q = f->ini;
	f->ini = f->ini->prox;
	if (!f->ini) // esvaziou a fila
		f->fim = NULL;
	free(q);
	return resp;
}

void TF_libera(TF *f)
{
	TLSE *q, *p = f->ini;
	while (p)
	{
		q = p;
		p = p->prox;
		free(q);
	}
	free(f);
}

void TF_imprime(TF *f)
{
	TF *aux = TF_inicializa();
	while (!TF_vazia(f))
	{
		int x = TF_retira(f);
		printf("%d ", x);
		TF_insere(aux, x);
	}
	while (!TF_vazia(aux))
		TF_insere(f, TF_retira(aux));
	TF_libera(aux);
}

TF *TF_cria()
{
	TF *f = (TF *)malloc(sizeof(TF));
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

TF *TF_inv_fila(TF *f)
{

	TP *aux = TP_inicializa();
	TF *fila = TF_inicializa();
	TP *aux2 = TP_inicializa();
	while (!TF_vazia(f))
	{
		TP_push(aux, TF_retira(f));
	}

	while (!TP_vazia(aux))
	{
		int val = TP_pop(aux);
		TF_insere(fila, val);
		TP_push(aux2, val);
	}
	while (!TP_vazia(aux2))
	{
		TF_insere(f, TP_pop(aux2));
	}

	return fila;
}

TF *TF_junta_filas(TF *f1, TF *f2)
{
	TF *f1_temp = TF_inicializa();
	TF *f2_temp = TF_inicializa();
	TF *filas_juntas = TF_inicializa();

	while (!TF_vazia(f1))
	{
		TF_insere(f1_temp, TF_retira(f1));
	}
	while (!TF_vazia(f2))
	{
		TF_insere(f2_temp, TF_retira(f2));
	}

	while (!TF_vazia(f1_temp))
	{
		int val = TF_retira(f1_temp);
		TF_insere(filas_juntas, val);
		TF_insere(f1, val);
	}
	while (!TF_vazia(f2_temp))
	{
		int val = TF_retira(f2_temp);
		TF_insere(filas_juntas, val);
		TF_insere(f2, val);
	}

	return filas_juntas;
}
