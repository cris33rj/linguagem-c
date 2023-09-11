#include <stdio.h>
#include <stdlib.h>

/*      Aula 171: Dúvida

        |   *
        |  **
        | ***
        |****

        Código escrito por Wagner Gaspar
        Abril de 2021
*/

int main() {
    int i, j, n;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    for(i = 0; i <= n; i++){
        for(j = n - i; j >= 0; j--) // imprime os espaços
            printf(" ");
        for(j = 0; j <= i; j++) // imprime os *
            printf("*");
        printf("\n");
    }

    return 0;
}
