/*
    Uma posição no vetor pode ter estar preenchida por:
    -Um número inteiro que foi inserido;
    -Pela informação -1 indicando que a posicao ainda não foi preenchida;
    -Pela informação -2 indicando que o valor da posição foi deletado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define TAM 100
#define ll long long
int count = 0;

int funcao_hash1(char str[])
{
    ll int hash_value = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        hash_value = (hash_value + ((int)str[i]));
        hash_value = hash_value % TAM;
    }
    return hash_value;
}

int funcao_hash2(char str[])
{
    ll int hash_value = 1;
    for (int i = 0; i < strlen(str); i++)
    {
        hash_value = (hash_value + pow(19, i) * ((int)str[i]));
        hash_value = hash_value % TAM;
    }
    return hash_value % TAM;
}

int funcao_hash3(char str[])
{
    ll int hash_value = 7;
    for (int i = 0; i < strlen(str); i++)
    {
        hash_value = (hash_value * 31 + ((int)str[i])) % TAM;
    }
    return hash_value % TAM;
}

// lookup operation
int procurar(int *vetor_bits, char s[])
{
    int a = funcao_hash1(s);
    int b = funcao_hash2(s);
    int c = funcao_hash3(s);

    if (vetor_bits[a] && vetor_bits[b] && vetor_bits[c])
        return 1;
    else
        return 0;
}
void inserir(int *vetor_bits, char str[])
{
    // printf("entrou no metodo inserir\n");
    //  check if the element in already present or not
    // printf("Vai procurar %s\n", str);
    if (procurar(vetor_bits, str))
        printf("%s provavelmente já está presente\n", str);
    else
    {
        int a = funcao_hash1(str);
        int b = funcao_hash2(str);
        int c = funcao_hash3(str);

        vetor_bits[a] = 1;
        vetor_bits[b] = 1;
        vetor_bits[c] = 1;

        printf("%s foi inserida.\n", str);
    }
}

void imprimir(int tab[])
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        printf("%d = %d\n", i, tab[i]);
    }
}

int main()
{

    int opcao, valor, resp, tabela[TAM];
    int vetor_bits[100] = {0};
    char words[30][15];

    strcpy(words[0], "mariajose");
    strcpy(words[1], "claudiosantos");
    strcpy(words[2], "fabiofaria");
    strcpy(words[3], "mariojose");
    strcpy(words[4], "franciscolima");
    strcpy(words[5], "alfredojose");
    strcpy(words[6], "francismota");
    strcpy(words[7], "antoniocarlos");
    strcpy(words[8], "brunomatoso");
    strcpy(words[9], "mariliasilva");
    strcpy(words[10], "raimundosantos");
    strcpy(words[11], "claudiasouza");
    strcpy(words[12], "patriciasantos");
    strcpy(words[13], "guilhermejose");
    strcpy(words[14], "mariolago");
    strcpy(words[15], "viniciuspedro");
    strcpy(words[16], "mariacosta");
    strcpy(words[17], "josesantos");
    strcpy(words[18], "brunomatos");
    strcpy(words[19], "liviagomes");
    strcpy(words[20], "claudiasantos");
    strcpy(words[21], "mariajosue");
    strcpy(words[22], "severinocosta");
    strcpy(words[23], "mateussantos");
    strcpy(words[24], "mariosouza");
    strcpy(words[25], "josesouza");
    strcpy(words[26], "marasantos");
    strcpy(words[27], "miguelfaria");
    strcpy(words[28], "josuedasilva");
    strcpy(words[29], "franciscosilva");

    for (int i = 0; i < 30; i++)
    {
        // printf("indice %d\n", i);
        // printf("Vai tentar inserir %s\n", words[i]);
        inserir(vetor_bits, words[i]);
    }
    return 0;
}