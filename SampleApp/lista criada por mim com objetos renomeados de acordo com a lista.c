#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct lista
{
    int info;
    struct lista *prox;
} TSLE;



TSLE * createList()
{
    TSLE * inicio = NULL;
    return inicio;
}


TSLE *inserirNoInicio(TSLE *inicio, int inf)
{
    TSLE *temp = (TSLE*) malloc(sizeof(TSLE));

    temp->info=inf;

    temp->prox = inicio;
    inicio = temp;

    return inicio;
}

void inserirNoFinal(TSLE **inicio, int inf)
{

    TSLE *temp, *p;
    temp = (TSLE*) malloc(sizeof(TSLE));
    temp->info=inf;
    temp->prox=NULL;

    if(*inicio==NULL)
    {
        *inicio=temp;
    }
    else
    {

        p=*inicio;
        while (p->prox!=NULL)
        {
            p=p->prox;
        };


        p->prox = temp;
        temp->prox=NULL;
    }

    //return inicio;

}

void displayList(TSLE *inicio)
{
    TSLE *p;
    p =inicio;

    while(p!=NULL)
    {
        printf("%d",p->info);
        p=p->prox;
        if (p != NULL)
            printf("-");
    }
    //  printf("***********");

}

void inverte(TSLE **inicio)
{
    TSLE *prev,*ptr,*pos;
//printf("entrou");

    prev = NULL;
    ptr=*inicio;

    while(ptr!=NULL)
    {
        pos = ptr->prox;
        ptr->prox=prev;
        prev = ptr;
        ptr=pos;
    }
    *inicio=prev;
//printf("%d",inicio->info);
//displayList(*inicio);

}

TSLE *inverteCriandoCopia(TSLE *start)
{
    TSLE *prev, *ptr, *next, *ptrnew, *newstart;

    newstart  = (TSLE *)malloc(sizeof(TSLE));
    newstart->info = start->info;
    ptrnew = newstart;
    ptr = start;
    ptr = ptr->prox;
    while(ptr!=NULL)
    {
        ptrnew->prox = (TSLE *)malloc(sizeof(TSLE));
        ptrnew = ptrnew->prox;
        ptrnew->info = ptr->info;
        ptr = ptr->prox;
    }
    ptrnew->prox = NULL;

    prev=NULL;
    ptr=newstart;
    while(ptr!=NULL)
    {
        next=ptr->prox;
        ptr->prox=prev;
        prev=ptr;
        ptr=next;
    }
    newstart=prev;
    return newstart;
}

TSLE* desloca (TSLE* l, int n)
{
//   printf("ENTROU NO METODO");

    TSLE * ptr, *temp;
    ptr = l;

    if(n%2==0)
    {
        // printf("par");
        while(ptr->prox!=NULL)
        {
            ptr = ptr->prox;
        }
        temp = l;
        ptr->prox = l;
        l = temp->prox;
        ptr->prox->prox = NULL;

    }
    else
    {
        // printf("IMPAR");
        while(ptr->prox->prox!=NULL)
        {
            ptr = ptr->prox;
        }
        temp = l;
        l = ptr->prox;
        l->prox = temp;
        ptr->prox = NULL;
    }
    return l;

}

TSLE * copia(TSLE * l)
{
    TSLE *prev, *ptr, *next, *ptrnew, *newstart;
    newstart  = (TSLE *)malloc(sizeof(TSLE));
    newstart->info = l->info;
    ptrnew = newstart;
    ptr = l;
    ptr = ptr->prox;
    while(ptr!=NULL)
    {
        ptrnew->prox = (TSLE *)malloc(sizeof(TSLE));
        ptrnew = ptrnew->prox;
        ptrnew->info = ptr->info;
        ptr = ptr->prox;
    }
    ptrnew->prox = NULL;

    return newstart;
}

TSLE* rto (TSLE* l, int elem)
{
    TSLE * ptr, *prev;
    prev = NULL;
    ptr = l;

    while(1)
    {
        if (l->info == elem)
            l = l->prox;
        else
            break;
    }
    prev=l;
    ptr = prev->prox;

    while (ptr!=NULL)
    {

        if(ptr->info == elem)
        {
            prev->prox = ptr->prox;
            ptr = prev->prox;

        }
        else
        {
            prev = prev->prox;
            ptr = ptr->prox;
        }

    }
    return l;

}

int igual (TSLE *l1, TSLE *l2)
{
    TSLE *p, *p2;
    p =l1;
    p2 = l2;

    while(p!=NULL && p2!=NULL)
    {
        if (p->info != p2->info) return 0;
        p=p->prox;
        p2=p2->prox;

    }

    return 1;

}

TSLE* junta_listas (TSLE* l1, TSLE* l2)
{
    TSLE *p, *p2;
    p =l1;
    p2 = l2;

    while(p2!=NULL)
    {
        inserirNoFinal(&l1, p2->info);
        p2=p2->prox;
        printf("passou aqui");

    }
    return l1;

}


int main()
{
    TSLE * inicio=NULL, *novoinicio=NULL, *listaComElementosExcluidos=NULL, *inicio2=NULL, *concatenada, *invertida;

    inicio = createList();
    inicio2 = createList();
    int num;

    printf("informe os numeros da lista 1:\n");
    for (int i=0; i<4; i++)
    {
        scanf("%d",&num);
        inserirNoFinal(&inicio,num);
    }

    printf("informe os numeros da lista 2:\n");
    for (int i=0; i<4; i++)
    {
        scanf("%d",&num);
        inserirNoFinal(&inicio2,num);
    }


//    printf("Imprimindo lista original:\n");
//    displayList(inicio);
//    printf("\n");
//    printf("-------------\n");
    /* TODO ESSE BLOCO COMENTADO TA FUNCIONANDO
       novoinicio = inverteCriandoCopia(inicio);
       printf("Imprimindo copia da lista original invertida:\n");
       displayList(novoinicio);
       printf("\n");
        printf("-----------\n");
       printf("Imprimindo novamente a lista original pra comprovar que nao alterou:\n");
       displayList(inicio);
        printf("\n");
       printf("-----------\n");
       inverte(&inicio);
       printf("Imprimindo dessa vez a propria lista original invertida:\n");
       displayList(inicio);
       */
//    inicio = desloca(inicio,2);
//    printf("deslocamento para numero PAR 2:\n");
//    displayList(inicio);

    //  novoinicio = copia(inicio);
    //    printf("Imprimindo copia da lista original:\n");
    //   displayList(novoinicio);


    //listaComElementosExcluidos = rto(inicio, 2);
    //displayList(listaComElementosExcluidos);

    //VERIFICAR SE DUAS LISTAS SÃO IGUAIS

//    printf("Imprimindo lista 1:\n");
//    displayList(inicio);
//    printf("\n");
//    printf("-------------\n");
//
//    printf("Imprimindo lista 2:\n");
//    displayList(inicio2);
//    printf("\n");
//    printf("-------------\n");


//    int ehIgual = igual(inicio,inicio2);
//    if (ehIgual ==1) printf("Iguais");
//    else printf("Diferentes");
//

    //CONCATENAR UMA LISTA NA OUTRA
//    printf("Imprimindo lista 1:\n");
//    displayList(inicio);
//    printf("\n");
//    printf("-------------\n");
//
//    printf("Imprimindo lista 2:\n");
//    displayList(inicio2);
//    printf("\n");
//    printf("-------------\n");
//
//    concatenada = junta_listas(inicio,inicio2);
//    printf("Imprimindo lista concatenada:\n");
//    displayList(concatenada);
//    printf("\n");
//    printf("-------------\n");

       invertida = inverteCriandoCopia(inicio);
       printf("Imprimindo copia da lista original invertida:\n");
       displayList(invertida);
       printf("\n");
        printf("-----------\n");

      int ehIgual = igual(invertida, inicio2);
      if (ehIgual ==1) printf("Iguais");
      else printf("Diferentes");








}
