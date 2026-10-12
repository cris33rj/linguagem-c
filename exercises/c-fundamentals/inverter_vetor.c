#include <stdio.h>


int main(void){

int myArray[] = {1,2,3,4,5,6,7,8,9,10};

int length = 10;
int temp = 0;
int i;
for (i=0; i<length/2; i++){
    temp = myArray[i];
    myArray[i] = myArray[length-1-i];
    myArray[length-i-1]= temp;
}

for (i=0; i<length; i++){
    printf("%d",myArray[i]);
}
}
