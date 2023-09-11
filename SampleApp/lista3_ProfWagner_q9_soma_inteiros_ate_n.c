#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n, A = 0;

//    do{
//        printf("Digite o valor de n: ");
//        scanf("%d", &n);
//    }while(n < 1);

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    while(n < 1){
        printf("N nao pode ser zero ou negativo. Digite novamente\n");
        scanf("%d", &n);

    }

    for(i = 1; i <= n; i++)
        A = A + i;

    printf("Soma de 1 ate %d: %d\n\n", n, A);
}
