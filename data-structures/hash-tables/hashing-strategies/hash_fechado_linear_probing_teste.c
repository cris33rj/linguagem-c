/* /*
            Aula 260: Tabela Hash linear com vetor

            Código escrito por Wagner Gaspar
            Setembro de 2021
*/

// 2 * 15 = 31
#include <stdio.h>
#include <stdlib.h>
#define TAM 31
int count = 0;
int t[TAM] = {};

int funcaoHash(int chave)
{
    return chave % TAM;
}

void inserir(int valor)
{
    if (count == TAM)
    {
        printf("Error.\nTable if FULL\n");
        exit(EXIT_FAILURE);
    }
    int id = funcaoHash(valor);
    int i = 0;
    while (t[id] != NULL && t[id] != -1)
    {
        printf("%d", t[id]);
        id = funcaoHash(id + i);
        i++;
    }
    // TEM DE VERIFICAR TAMBÉM SE A TABELA ESTÁ CHEIA
    t[id] = valor;
    count++;
}

int busca(int chave)
{
    if (count == 0)
    {
        printf("Error.\nTable if EMPTY\n");
        exit(EXIT_FAILURE);
    }
    int id = funcaoHash(chave);
    // printf("\nIndice gerada: %d\n", id);
    int i = 0;
    while (t[id] != -1 && t[id] != -2)
    {
        if (t[id] == chave)
            return id;
        else
        {
            i++;
            id = funcaoHash(id + i);
        }
    }
    return 0;
}

void imprimir()
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        printf("%d = %d\n", i, t[i]);
    }
}

void deletar(int valor)
{
    if (count == 0)
    {
        printf("Error.\nTable if EMPTY\n");
        exit(EXIT_FAILURE);
    }
    int loc = busca(valor);
    if (loc != -1)
    {
        printf("vai deletar\n");
        t[loc] = -1;
        count--;
    }
}

int main()
{

    int opcao, valor, retorno;

    do
    {
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 -Deletar\n\t4 -Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\tQual valor desseja inserir? ");
            scanf("%d", &valor);
            inserir(valor);
            break;
        case 2:
            printf("\tQual valor desseja buscar? ");
            scanf("%d", &valor);
            retorno = busca(valor);
            if (retorno != 0)
                printf("\tValor %d foi encontrado no indice %d", t[retorno], retorno);
            else
                printf("\tValor nao encontrado!\n");
            break;
        case 3:
            printf("\tQual valor desseja deletar? ");
            scanf("%d", &valor);
            deletar(valor);
            break;
        case 4:
            imprimir();
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
