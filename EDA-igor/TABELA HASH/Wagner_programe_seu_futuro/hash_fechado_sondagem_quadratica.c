/*
            Aula 260: Tabela Hash linear com vetor

            Código escrito por Wagner Gaspar
            Setembro de 2021
*/

// 2 * 15 = 31
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
    int id_original = id;
    int i = 0;
    while (tab[id] != -1 && tab[id] != -2 && tab[id] != valor)
    {
        printf("imprimindo id original=%d\n", id);
        printf("imprimindo i no comeco = %d\n", i);
        printf("a potencia de i eh %d\n", pow(i, 2));
        id = funcaoHash(id_original + pow(i, 2));
        printf("o id serah %d\n", id);
        i = i + 1;
        printf("o valor de i++ eh %d\n", i);
        // i = pow(i, 2);
    }
    // TEM DE VERIFICAR TAMBÉM SE A TABELA ESTÁ CHEIA
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
    printf("id calculado eh %d\n", id);
    int id_original = id;
    // printf("\nIndice gerada: %d\n", id);
    int i = 0;
    while (tab[id] != -1)
    {
        if (tab[id] == chave)
        {
            printf("achou. vai retornar o valor %d no indice %d\n", chave, id);
            return id;
        }
        else
        {
            i++;
            printf("Vai tentar achar em indice %d\n", id_original + pow(i, 2));
            id = funcaoHash(id_original + pow(i, 2));
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
        printf("vai deletar %d\n", tab[loc]);
        tab[loc] = -2;
        count--;
    }
    else
        printf("valor %d nao existe\n", valor);
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