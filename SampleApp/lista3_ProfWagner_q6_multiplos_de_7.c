#include <stdio.h>

int main (void){

    float nota, media, soma_notas;
    int quant_notas = 2;

    do
    {
        printf("Informe sua nota");

    } while(quant_notas<=12){
       scanf("%f",&nota);
        if (nota < 0 || nota > 10){
            printf("nota invalida");
            continue;
        }
        else {
        soma_notas +=nota;
        quant_notas++;
        }
    }

        printf("Media semestral %f: ",soma_notas/12);

}
