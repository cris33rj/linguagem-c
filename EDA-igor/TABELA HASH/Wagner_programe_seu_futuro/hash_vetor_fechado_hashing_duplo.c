/*
    Uma posição no vetor pode ter estar preenchida por:
    -Um número inteiro que foi inserido;
    -Pela informação -1 indicando que a posicao ainda não foi preenchida;
    -Pela informação -2 indicando que o valor da posição foi deletado.
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 29
int count = 0;

void inicializarTabela(int tab[])
{
    int i;

    for (i = 0; i < TAM; i++)
        tab[i] = -1;
}

int funcaoHash1(int chave)
{
    return chave % TAM;
}

int funcaoHash2(int chave)
{
    return 7 - (chave % 7);
}

int funcao_double_hash(int chave, int i)
{
    return (funcaoHash1(chave) + i * funcaoHash2(chave)) % TAM;
}

void inserir(int tab[], int valor)
{
    if (count == TAM)
    {
        printf("Erro.\nTabela esta CHEIA. \n");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    int id = funcao_double_hash(valor, i);

    while (tab[id] != -1 && tab[id] != -2 && tab[id] != valor && i < TAM)
    {
        id = funcao_double_hash(valor, i);
        i++;
    }
    if (tab[id] != valor)
        count++;
    tab[id] = valor;
}

int busca(int tab[], int chave)
{
    if (count == 0)
    {
        printf("Erro.\nTabela esta VAZIA\n");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    int id = funcao_double_hash(chave, i);
    while (tab[id] != -1)
    {
        if (tab[id] == chave)
            return id;
        else
        {
            i++;
            id = funcao_double_hash(chave, i);
        }
    }
    return 0;
}

void imprimir(int tab[])
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        printf("%d = %d\n", i, tab[i]);
    }
}

void deletar(int tab[], int valor)
{
    if (count == 0)
    {
        printf("Erro.\nTabela esta VAZIA\n");
        exit(EXIT_FAILURE);
    }
    int loc = busca(tab, valor);
    if (tab[loc] != -1 && tab[loc] == valor)
    {
        tab[loc] = -2;
        count--;
    }
    else
        printf("valor %d não encontrado\n", valor);
}

int main()
{

    int opcao, valor, resp, tabela[TAM];

    inicializarTabela(tabela);

    do
    {
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 -Deletar\n\t4 -Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\tQual valor quer inserir? ");
            scanf("%d", &valor);
            inserir(tabela, valor);
            break;
        case 2:
            printf("\tQual valor quer buscar? ");
            scanf("%d", &valor);
            resp = busca(tabela, valor);
            if (resp != 0)
                printf("\tValor %d foi encontrado no indice %d", tabela[resp], resp);
            else
                printf("\tValor nao encontrado!\n");
            break;
        case 3:
            printf("\tQual valor quer deletar? ");
            scanf("%d", &valor);
            deletar(tabela, valor);
            break;
        case 4:
            imprimir(tabela);
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}