/*
            Aula 260: Tabela Hash linear com vetor

            Código escrito por Wagner Gaspar
            Setembro de 2021
*/

// 2 * 15 = 31
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

int funcaoHash(int chave)
{
    return chave % TAM;
}

void inserir(int tab[], int valor)
{
    if (count == TAM)
    {
        printf("Erro.\nTabela esta CHEIA\n");
        exit(EXIT_FAILURE);
    }
    int id = funcaoHash(valor);
    int i = 0;
    while (tab[id] != -1 && tab[id] != -2 && tab[id] != valor)
    {
        // printf("id que sera usado pela funcao hash=%d\n", i);
        id = funcaoHash(id + 1);
        // printf("id calculado pela função hash=%d\n", id);
        // i++;
        // printf("valor de i+1 = %d\n", i);
    }
    // printf("Saiu do while\n");
    //  TEM DE VERIFICAR TAMBÉM SE A TABELA ESTÁ CHEIA
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
    int id = funcaoHash(chave);
    // printf("\nIndice gerada: %d\n", id);
    int i = 0;
    while (tab[id] != -1)
    {
        if (tab[id] == chave)
            return id;
        else
        {
            id = funcaoHash(id + 1);
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
        printf("Erro.\nTabela esta vazia\n");
        exit(EXIT_FAILURE);
    }
    int loc = busca(tab, valor);
    if (tab[loc] != -1 && tab[loc] == valor)
    {
        // printf("valor pra ser deletado %d\n", tab[loc]);
        printf("vai deletar\n");
        tab[loc] = -2;
        count--;
    }
    else
    {
        printf("valor %d nao existe\n", valor);
    }
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