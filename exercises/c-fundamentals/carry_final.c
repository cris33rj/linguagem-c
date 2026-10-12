#include <stdio.h>


int main()
{

    int n1, n2,carry = 0, number_of_carries=0;

    scanf("%d",&n1);
    scanf("%d",&n2);

    while ((n1+n2+carry)>9 )
    {
        if((n1%10 + n2%10 + carry)>9)
        {
            n1 = n1/10;
            n2 = n2/10;
            carry=1;
            number_of_carries++;
        }
        else
        {
            n1 = (n1/10);
            n2 = n2/10;
            carry=0;
        }
    }

    printf("%d",number_of_carries);
}
