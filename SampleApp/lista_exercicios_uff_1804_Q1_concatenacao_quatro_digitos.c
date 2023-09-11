#include <stdio.h>
#include <stdlib.h>

int testarQuadradoDasSomas(int digitosIniciais, int DigitosFinais, int numeroOriginal){
int quadradoDaSoma = pow(digitosIniciais+DigitosFinais,2);

printf("Potencia do quadrado da soma %d\n",quadradoDaSoma);
printf("numero original %d\n",numeroOriginal);

if(quadradoDaSoma == numeroOriginal){
    return 1;
} else {
     return 0;
}

}

int concatenarNumeros(int x, int y){
    int pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;
}

int getDoisDigitosIniciais(int numero)
{
    while (numero >= 100)
    {
        numero /= 10;
    }
    return numero;
}

int main()
{
    int num;

   printf("Informe o numero\n");
   scanf("%d",&num);

   //int nDigits = floor(log10(abs(num))) + 1;
   //int potenciaDe10 =  pow(10,nDigits-2);

   int doisDigitosIniciais =  getDoisDigitosIniciais(num);

   int ultimoDigito = num%10;
   int penultimoDigito = (num/10) %10;
   int doisDigitosFinais = (penultimoDigito*10)+ultimoDigito;

   printf("%d\n",doisDigitosIniciais);
   printf("%d\n",doisDigitosFinais);

   int DigitosIniciaisFinaisConcatenados = concatenarNumeros(doisDigitosIniciais,doisDigitosFinais);


   int teste = testarQuadradoDasSomas(doisDigitosIniciais,doisDigitosFinais,DigitosIniciaisFinaisConcatenados);

   printf("Resultado do teste da potencia da soma dos quadrados %d: ",teste);

}



