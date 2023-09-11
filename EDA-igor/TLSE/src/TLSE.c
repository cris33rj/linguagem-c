#include "TLSE.h"

TLSE *TLSE_inicializa()
{
  return NULL;
}

TLSE *TLSE_insere(TLSE *l, int elem)
{
  TLSE *novo = (TLSE *)malloc(sizeof(TLSE));
  novo->prox = l;
  novo->info = elem;
  return novo;
}

TLSE *TLSE_insere_no_fim(TLSE *l, int elem)
{
  TLSE *novo = (TLSE *)malloc(sizeof(TLSE));
  novo->info = elem;
  novo->prox = NULL;

  if (!l)
  {
    l = novo;
    return l;
  }
  // printf("IMPRIMINDO L->INFO %d\n", l->info);
  TLSE *p = l;

  // printf("passou daqui");
  while (p->prox)
  {
    p = p->prox;
  }
  p->prox = novo;

  return l;
}

void TLSE_imprime(TLSE *l)
{
  TLSE *p = l;
  while (p)
  {
    printf("%d ", p->info);
    p = p->prox;
  }
}

void TLSE_imp_rec(TLSE *l)
{
  if (l)
  {
    printf("%d ", l->info);
    TLSE_imp_rec(l->prox);
  }
}

void TLSE_imp_rec_rev(TLSE *l)
{
  if (l)
  {
    TLSE_imp_rec_rev(l->prox);
    printf("%d ", l->info);
  }
}

void TLSE_libera(TLSE *l)
{
  TLSE *p = l, *q;
  while (p)
  {
    q = p;
    p = p->prox;
    free(q);
  }
}

void TLSE_lib_rec(TLSE *l)
{
  if (l)
  {
    TLSE_lib_rec(l->prox);
    printf("liberando o elemento %d...\n", l->info);
    free(l);
  }
}

TLSE *TLSE_retira(TLSE *l, int elem)
{
  TLSE *p = l, *ant = NULL;
  while ((p) && (p->info != elem))
  {
    ant = p;
    p = p->prox;
  }
  if (!p)
    return l;
  if (!ant)
    l = l->prox;
  else
    ant->prox = p->prox;
  free(p);
  return l;
}

TLSE *TLSE_retira_rec(TLSE *l, int elem)
{
  if (!l)
    return l;
  if (l->info == elem)
  {
    TLSE *p = l;
    l = l->prox;
    free(p);
  }
  else
    l->prox = TLSE_retira_rec(l->prox, elem);
  return l;
}

TLSE *TLSE_busca(TLSE *l, int elem)
{
  TLSE *p = l;
  while ((p) && (p->info != elem))
    p = p->prox;
  return p;
}

TLSE *TLSE_busca_rec(TLSE *l, int elem)
{
  if ((!l) || (l->info == elem))
    return l;
  return TLSE_busca_rec(l->prox, elem);
}

void TLSE_inverte(TLSE **l)
{
  TLSE *next, *prev, *pos;
  prev = NULL;
  pos = *l;

  while (pos)
  {
    next = pos->prox;
    pos->prox = prev;
    prev = pos;
    pos = next;
  }
  *l = prev;
  // printf("VALORES %d->%d->%d\n", l->info, l->prox->info, l->prox->prox->info);
  // printf("imprimindo lista invertida dentro do metodo\n");
  // TLSE_imprime(*l);
  printf("\n");

  // printf("%p\n", l);
  // printf("%p\n", &l);
}

TLSE *TLSE_inverte_com_retorno(TLSE *l)
{
  TLSE *next, *prev, *pos;
  prev = NULL;
  pos = l;

  while (pos)
  {
    next = pos->prox;
    pos->prox = prev;
    prev = pos;
    pos = next;
  }
  l = prev;
  return l;
  // printf("VALORES %d->%d->%d\n", l->info, l->prox->info, l->prox->prox->info);
  // printf("imprimindo lista invertida dentro do metodo\n");
  // TLSE_imprime(*l);
  printf("\n");

  // printf("%p\n", l);
  // printf("%p\n", &l);
}

TLSE *TLSE_copia(TLSE *l)
{
  TLSE *l_c = (TLSE *)malloc(sizeof(TLSE));
  l_c->info = l->info;
  TLSE *pnew = l_c;
  TLSE *p = l;
  p = p->prox;

  while (p)
  {
    pnew->prox = (TLSE *)malloc(sizeof(TLSE));
    pnew = pnew->prox;
    pnew->info = p->info;
    // printf("imprimindo l_c %d\n", pnew->info);
    // printf("imprimindo p->info %d\n", p->info);
    p = p->prox;
  }
  // printf("IMPRIMINDO PNEW-PROXIMO %d", pnew->prox->info);
  printf("\n");
  pnew->prox = NULL;
  // printf("imprimindo l_c dentro do metodo:");
  // TLSE_imprime(l_c);
  // printf("\n");
  return l_c;
}

TLSE *TLSE_copia_inverte_retorna(TLSE *l)
{
  TLSE *copia = TLSE_copia(l);

  TLSE *invertido = TLSE_inverte_com_retorno(copia);
  return invertido;
}

TLSE *TLSE_desloca(TLSE *l, int n)
{
  TLSE *ant, *pos;
  ant = NULL;
  pos = l;

  printf("IMPRIMINDO N ---> %d\n", n);

  if (n % 2 != 0)
  {
    while (pos->prox)
    {
      ant = pos;
      pos = pos->prox;
    }
    pos->prox = l;
    l = pos;
    ant->prox = NULL;
  }

  if (n % 2 == 0)
  {
    while (pos->prox)
    {
      ant = pos;
      pos = pos->prox;
    }
    pos->prox = l;
    l = l->prox;
    pos->prox->prox = NULL;
  }
  return l;
}

TLSE *TLSE_rto(TLSE *l, int elem)
{
  if (!l)
    return NULL;

  while (l->info == elem)
  {
    l = l->prox;
  }

  TLSE *p, *ant;
  ant = l;
  p = l->prox;

  while (p)
  {
    if (p->info == elem)
    {
      ant->prox = p->prox;
      p = ant->prox;
    }
    else
    {
      ant = ant->prox;
      p = p->prox;
    }
  }
  return l;
}

TLSE *TLSE_i_p(TLSE *l)
{
  TLSE *i_p = TLSE_inicializa();
  TLSE *p = l;

  printf("IMPRIMINDO PRA PRIMEIRA PASSADA %d -->", p->info);
  while (p)
  {
    if (p->info % 2 != 0)
    {
      i_p = TLSE_insere_no_fim(i_p, p->info);
    }
    p = p->prox;
  }

  p = l;
  printf("IMPRIMINDO P REINICIALIZADO %d -->", p->info);

  while (p)
  {
    if (p->info % 2 == 0)
    {
      i_p = TLSE_insere_no_fim(i_p, p->info);
    }
    p = p->prox;
  }

  return i_p;
}

int TLSE_igual(TLSE *l1, TLSE *l2)
{
  TLSE *p1 = l1;
  TLSE *p2 = l2;

  while (p1 && p2)
  {
    if (p1->info != p2->info)
    {
      return 0;
    }
    p1 = p1->prox;
    p2 = p2->prox;
  }
  return 1;
}

TLSE *TLSE_junta_listas(TLSE *l1, TLSE *l2)
{
  TLSE *p1 = l1;
  TLSE *p2 = l2;

  while (p2)
  {
    p1 = TLSE_insere_no_fim(p1, p2->info);
    p2 = p2->prox;
  }

  return p1;
}

int TLSE_contrario(TLSE *l1, TLSE *l2)
{

  TLSE *l2_invertida = TLSE_copia_inverte_retorna(l2);
  int sao_iguais = TLSE_igual(l1, l2_invertida);
  printf("imprindo variavel SAO_IGUAIS %d\n", sao_iguais);

  return sao_iguais;
}

int TLSE_comprimento(TLSE *l)
{

  TLSE *p = l;
  int comprimento = 0;

  while (p)
  {
    comprimento++;
    p = p->prox;
  }
  return comprimento;
}

TLSE *TLSE_ultimo(TLSE *l)
{

  TLSE *p = l;

  while (p->prox)
  {
    p = p->prox;
  }

  return p;
}

TLSE *TLSE_separa(TLSE *l, int x)
{

  TLSE *p = l;
  TLSE *p_nova_lista, *p_novo_fim;

  TLSE *nova_lista = TLSE_inicializa();

  while (p)
  {
    if (p->info == x)
    {
      p_nova_lista = p->prox;
      p_novo_fim = p;
      break;
    }
    p = p->prox;
  }

  while (p_nova_lista)
  {
    nova_lista = TLSE_insere_no_fim(nova_lista, p_nova_lista->info);
    p_nova_lista = p_nova_lista->prox;
  }

  p_novo_fim->prox = NULL;

  return nova_lista;
}

TLSE *TLSE_merge_intercala(TLSE *l1, TLSE *l2)
{
  TLSE *p1 = l1;
  TLSE *p2 = l2;
  TLSE *nova_lista = TLSE_inicializa();

  while (p1 && p2)
  {
    nova_lista = TLSE_insere_no_fim(nova_lista, p1->info);
    nova_lista = TLSE_insere_no_fim(nova_lista, p2->info);
    p1 = p1->prox;
    p2 = p2->prox;
  }

  if (p1)
  {
    while (p1)
    {
      nova_lista = TLSE_insere_no_fim(nova_lista, p1->info);
      p1 = p1->prox;
    }
  }

  if (p2)
  {
    while (p2)
    {
      nova_lista = TLSE_insere_no_fim(nova_lista, p2->info);
      p2 = p2->prox;
    }
  }

  return nova_lista;
}

void TLSE_insereDepois(TLSE *l, int data, int x)
{

  TLSE *p = l;

  while (p)
  {
    if (p->info == x)
      break;
    p = p->prox;
  }

  if (!p)
  {
    printf("Elemento %d nao foi encontrado na lista", x);
  }
  else
  {
    TLSE *novo = malloc(sizeof(TLSE));
    novo->info = data;
    novo->prox = p->prox;
    p->prox = novo;
  }
}

TLSE *TLSE_insereAntes(TLSE *l, int data, int x)
{

  TLSE *p = l;

  if (l->info == x)
  {
    TLSE *novo = malloc(sizeof(TLSE));
    novo->info = data;
    novo->prox = l;
    l = novo;
    return l;
  }

  while (p->prox)
  {
    if (p->prox->info == x)
      break;
    p = p->prox;
  }

  if (!p->prox)
  {
    printf("Nao foi encontrado\n");
  }
  else
  {
    TLSE *novo = malloc(sizeof(TLSE));
    novo->info = data;
    novo->prox = p->prox;
    p->prox = novo;
  }
  return l;
}

void TLSE_misc(TLSE *l, int x)
{
  TLSE *ant, *meio, *depois;
  TLSE *temp;
  printf("l->info=%d\n", l->info);
  printf("x=%d\n", x);
  if (l->info % x == 0)
  {
    temp = l->prox;
    l->prox = temp->prox;
    free(temp);
    printf("l->prox=%d\n", l->prox->info);
  }

  ant = l;
  meio = ant->prox;
  depois = meio->prox;

  while (depois->prox)
  {
    if (depois->info % x == 0)
    {
      depois = depois->prox->prox;
    }
    else
    {
      ant->prox = depois;
      meio = depois;
      depois = meio->prox;
    }
    ant = ant->prox;
    meio = meio->prox;
    depois = depois->prox;
  }
  printf("chegou na linha 539\n");

  printf("l->info=%d\n", l->info);
  printf("depois->info=%d\n", depois->info);
  if (depois->info % x != 0)
  {
    ant->prox = depois;
  }
}
