#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa
{
    int mat;
    char data_nasc[9];
    char nome[31];
} TP;

TP *retira_k(TP **vet, int *n, int k);

int qSortCompara(const void *void_x, const void *void_y)
{
    TP *x = *(TP **)void_x;
    TP *y = *(TP **)void_y;

    int cmp_ano = strncmp(x->data_nasc, y->data_nasc, 4);
    if (cmp_ano != 0)
        return cmp_ano;
    int cmp_mes = strncmp(x->data_nasc + 4, y->data_nasc + 4, 2);
    if (cmp_mes != 0)
        return cmp_mes;
    int cmp_dia = strncmp(x->data_nasc + 6, y->data_nasc + 6, 2);
    if (cmp_dia != 0)
        return cmp_dia;
    int cmp_nome = strcmp(x->nome, y->nome);
    if (cmp_nome != 0)
        return cmp_nome;
    if (x->mat < y->mat)
        return -1;
    if (x->mat > y->mat)
        return 1;
}

void ordena(TP **vet, int n)
{
    qsort(vet, n, sizeof(TP *), qSortCompara);
}

TP *ler_pessoa()
{
    TP *pessoa = malloc(sizeof(TP));
    printf("digite os dados(mat, data nasc e nome\n");
    scanf("%d", &pessoa->mat);
    scanf(" %9[^\n]", pessoa->data_nasc);
    scanf(" %31[^\n]", pessoa->nome);
    // printf("comparando ano: frase toda --> %s\n", pessoa->data_nasc);
    // printf("comparando mes a partir do indice 4 %s\n", pessoa->data_nasc + 4);
    // printf("comparando dia a partir do indice 6--> %s\n", pessoa->data_nasc + 6);
    //&employeesArr[i].name
    return pessoa;
}

int main(void)
{
    int n;
    printf("Digite o tamanho do vetor... ");
    scanf("%d", &n);
    if (n <= 0)
        return 0;
    TP **pessoas = (TP **)malloc(sizeof(TP *) * n);
    for (int i = 0; i < n; i++)
    {
        pessoas[i] = ler_pessoa();
    }

    printf("IMPRIMINDO ANTES DE ORDENAR\n");
    for (int i = 0; i < n; i++)
    {
        printf("matricula: %d -->nome: %s --> nasc: %s\n", pessoas[i]->mat, pessoas[i]->nome, pessoas[i]->data_nasc);
    }

    ordena(pessoas, n);
    printf("IMPRIMINDO DEPOIS DE ORDENAR\n");
    for (int i = 0; i < n; i++)
    {
        printf("matricula: %d -->nome: %s --> nasc: %s\n", pessoas[i]->mat, pessoas[i]->nome, pessoas[i]->data_nasc);
    }

    int k = 0;
    printf("Digite a posicao do elemento a ser retirado... ");
    scanf(" %d", &k);
    printf("imprimindo posicao do numero-->%d\n", k);
    printf("passou na lista 80\n");
    TP *elem = NULL;
    printf("passou aqui\n");
    elem = retira_k(pessoas, &n, k);
    printf("Depois de retira_k:\n");
    for (int i = 0; i < n; i++)
    {
        printf("matricula: %d -->nome: %s --> nasc: %s\n", pessoas[i]->mat, pessoas[i]->nome, pessoas[i]->data_nasc);
    }
    /*
    free(elem);
    for (int i = 0; i < n; i++)
        free(pessoas[i]); */

    return 0;
}
TP *retira_k(TP **vet, int *n, int k)
{
    printf("entreu em retira_k\n");
    TP *temp = vet[k];
    // printf("Imprimindo dados de vet[k]-->", *(vet[k]->nome));

    for (int i = k - 1; i < *n; i++)
    {
        vet[i] = vet[i + 1];
    }
    *n = *n - 1;
}
