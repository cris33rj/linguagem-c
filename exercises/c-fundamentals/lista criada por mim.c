#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct Node
{
    int val;
    struct Node *proximo;
} Node;



createList()
{
    Node * inicio = NULL;
    return inicio;
}


Node *inserirNoInicio(Node *inicio, int valor)
{
    Node *temp = (Node*) malloc(sizeof(Node));

    temp->val=valor;

    temp->proximo = inicio;
    inicio = temp;

    return inicio;
}

inserirNoFinal(Node **inicio, int valor){

    Node *temp, *p;
    temp = (Node*) malloc(sizeof(Node));
    temp->val=valor;
    temp->proximo=NULL;

    if(*inicio==NULL){
        *inicio=temp;
    } else {

    p=*inicio;
    while (p->proximo!=NULL)
    {
        p=p->proximo;
    };


    p->proximo = temp;
    temp->proximo=NULL;
    }

    //return inicio;

}

void displayList(Node *inicio)
{
    Node *p;
    p =inicio;

    while(p!=NULL)
    {
        printf("%d",p->val);
        p=p->proximo;
        if (p != NULL)
            printf("-");
    }
  //  printf("***********");

}

void inverte(Node **inicio){
Node *prev,*ptr,*pos;
//printf("entrou");

prev = NULL;
ptr=*inicio;

while(ptr!=NULL){
    pos = ptr->proximo;
    ptr->proximo=prev;
    prev = ptr;
    ptr=pos;
}
*inicio=prev;
//printf("%d",inicio->val);
//displayList(*inicio);

}

struct Node *inverteCriandoCopia(struct Node *start)
{ struct Node *prev, *ptr, *next, *ptrnew, *newstart;

    newstart  = (struct Node *)malloc(sizeof(struct Node));
    newstart->val = start->val;
    ptrnew = newstart;
    ptr = start;
    ptr = ptr->proximo;
    while(ptr!=NULL){
        ptrnew->proximo = (struct Node *)malloc(sizeof(struct Node));
        ptrnew = ptrnew->proximo;
        ptrnew->val = ptr->val;
        ptr = ptr->proximo;
    }
    ptrnew->proximo = NULL;

prev=NULL;
    ptr=newstart;
while(ptr!=NULL)
{
next=ptr->proximo;
ptr->proximo=prev;
prev=ptr;
ptr=next;
}
newstart=prev;
return newstart;
}

TLSE* desloca (TLSE* l, int n).


int main()
{
    Node * inicio=NULL, *novoinicio=NULL;

    inicio = createList();
    int num;

    printf("valrme o numero");
    for (int i=0; i<4; i++)
    {
        scanf("%d",&num);
        inserirNoFinal(&inicio,num);
    }

    printf("Imprimindo lista original:\n");
    displayList(inicio);
    printf("\n");
 printf("-------------\n");
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
   //novoinicio = inverteCriandoCopia(inicio);
  // displayList(novoinicio);
  // printf("-------------\n");
   //displayList(inicio);
}
