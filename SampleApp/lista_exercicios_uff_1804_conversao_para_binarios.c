#include <stdio.h>

//https://www.scaler.com/topics/decimal-to-binary-in-c/

void decimalToBinary(int num)
{
    if (num == 0)
    {
        printf("0");
        return;
    }

    // Stores binary representation of number.
    int binaryNum[32]; // Assuming 32 bit integer.
    int i=0;

    for ( ; num > 0; )
    {
        // printf("%d\n",i);
        binaryNum[i++] = num % 2;
        num /= 2;
    }
    // Printing array in reverse order.
    for (int j = i-1; j >= 0; j--)
    {
        printf("%d", binaryNum[j]);
    }
    printf("\n");
}

int main()
{
    int num = 0;
    do
    {
        printf("Informe o numero: \n");
        scanf("%d",&num);
        decimalToBinary(num);
    }
    while (num>0);

    return 0;
}
