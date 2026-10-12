
int main(){

    int A, *B, **C, ***D;

    printf("Digite um valor: ");
    scanf("%d", &A);

    B = &A;
    C = &B;
    D = &C;

    printf("O dobro de %d e: %d\n", A, 2 * *B);
    printf("O triplo de %d e: %d\n", A, 3 * **C);
    printf("O quadruplo de %d e: %d\n", A, 4 * ***D);

    return 0;
}
