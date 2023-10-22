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

void inicializarTabela(int t[])
{
    int i;

    for (i = 0; i < TAM; i++)
        t[i] = -1;
}

int funcaoHash(int chave)
{
    return chave % TAM;
}

void inserir(int t[], int valor)
{
    if (count == TAM)
    {
        printf("Error.\nTable if FULL\n");
        exit(EXIT_FAILURE);
    }
    int id = funcaoHash(valor);
    int id_original = id;
    int i = 0;
    while (t[id] != -1)
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
    t[id] = valor;
    count++;
}

int busca(int t[], int chave)
{
    if (count == 0)
    {
        printf("Error.\nTable if EMPTY\n");
        exit(EXIT_FAILURE);
    }
    int id = funcaoHash(chave);
    int id_original = id;
    // printf("\nIndice gerada: %d\n", id);
    int i = 0;
    while (t[id] != -1)
    {
        if (t[id] == chave)
            return id;
        else
        {
            i++;
            id = funcaoHash(id_original + pow(i, 2));
        }
    }
    return 0;
}

void imprimir(int t[])
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        printf("%d = %d\n", i, t[i]);
    }
}

void deletar(int t[], int valor)
{
    if (count == 0)
    {
        printf("Error.\nTable if EMPTY\n");
        exit(EXIT_FAILURE);
    }
    int loc = busca(t, valor);
    if (loc != -1)
    {
        printf("vai deletar\n");
        t[loc] = -1;
        count--;
    }
}

int main()
{

    int opcao, valor, retorno, tabela[TAM];

    inicializarTabela(tabela);

    do
    {
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 -Deletar\n\t4 -Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\tQual valor desseja inserir? ");
            scanf("%d", &valor);
            inserir(tabela, valor);
            break;
        case 2:
            printf("\tQual valor desseja buscar? ");
            scanf("%d", &valor);
            retorno = busca(tabela, valor);
            if (retorno != 0)
                printf("\tValor %d foi encontrado no indice %d", tabela[retorno], retorno);
            else
                printf("\tValor nao encontrado!\n");
            break;
        case 3:
            printf("\tQual valor desseja deletar? ");
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