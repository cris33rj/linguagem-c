#define FALSE (1==0)
#define TRUE  (1==1)
#include <stdio.h>

int hasSameDigits (long num1, long num2) {
    int digits[10]={0};
    int i;

  //  for (i = 0; i < 10; i++)      // Init all counts to zero.
    //    digits[i] = 0;

    while (num1 != 0) {           // Process all digits.
        digits[num1%10]++;        // Increment for least significant digit.
        num1 /= 10;               // Get next digit in sequence.
    }

    while (num2 != 0) {           // Same for num2 except decrement.
        digits[num2%10]--;
        num2 /= 10;
    }

    for (i = 0; i < 10; i++)
        if (digits[i] != 0)       // Any count different, not a permutation.
            return FALSE;

    return TRUE;                  // All count identical, was a permutation.
}

int main(){
int numero1 = 5412434;
int numero2 = 4321445;

int resultado = hasSameDigits(numero1,numero2);

if (resultado == 1)
    printf("TRUE");
    else printf("FALSE");


}




