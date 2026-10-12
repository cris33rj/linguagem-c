#include <stdio.h>

int contar(int num, int digito){

int contagem=0;

//printf("ENTROU");

while (num != 0 ){
   //  printf("digito = %d, numero = %d",digito,num);

     int resto = num%10;

    //printf("digito = %d, numero = %d",digito,num);
    if (digito == resto){
        contagem++;
    }
    num = num/10;
}
//printf("conta++ %d:",contagem);
return contagem;

}



int main(){

int num1;
int num2;

printf("Informe o primeiro numero");
scanf("%d", &num1);

printf("Informe o segundo numero");
scanf("%d", &num2);

int resto1;
int resto2;
while(num1!=0 && num2!=0){

int digito1 = num1%10;
int digito2 = num2%10;

int numerooriginal = num1;
num1 = num1/10;
num2 = num2/10;

int countNum1 = contar(num1,digito1);
int countNum2 = contar(num2,digito1);

printf("countNum1 %d :",countNum1);
printf("countNum2 %d :",countNum2);

if (countNum1!=countNum2){
printf("Nao e permutacao");
    break;
}


}







}
