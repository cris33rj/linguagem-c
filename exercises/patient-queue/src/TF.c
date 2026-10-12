#include "TF.h"

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

void TF_insere(TF *f1, PAC *pac)
{
	// printf("INSERIU\n");
	TLSE *novo = (TLSE *)malloc(sizeof(TLSE));
	novo->info = pac;
	// INSERÇÃO NO FIM
	if (!TF_vazia(f1))
		f1->fim->prox = novo;
	else
		f1->ini = novo;
	f1->fim = novo;
}

PAC *TF_retira(TF *f)
{
	if (TF_vazia(f))
		exit(1);

	PAC *resp = f->ini->info;

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

void TF_imprime(TF *f1)
{
	TF *auxiliar = TF_inicializa();
	while (!TF_vazia(f1))
	{
		PAC *pac = TF_retira(f1);
		printf("%s--> %d\n", pac->nome, pac->tempo);
		TF_insere(auxiliar, pac);
	}
	while (!TF_vazia(auxiliar))
		TF_insere(f1, TF_retira(auxiliar));
	TF_libera(auxiliar);
}
