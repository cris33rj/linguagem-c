#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    int y;
}TPTO2D;


int dentroRet (TPTO2D *inf, TPTO2D *sup, TPTO2D *p){

    if((p->x>=inf->x && p->x<=sup->x) && (p->y>=inf->y && p->y<=sup->y))
        return 1;
    else return 0;

}


int main (){

    TPTO2D *pontoInferior = (TPTO2D *) malloc(sizeof(TPTO2D));
    TPTO2D *pontoSuperior = (TPTO2D *) malloc(sizeof(TPTO2D));
    TPTO2D *ponto = (TPTO2D *) malloc(sizeof(TPTO2D));

    pontoInferior->x=2;
    pontoInferior->y=1;

    pontoSuperior->x=5;
    pontoSuperior->y=4;

    ponto->x=10;
    ponto->y=10;

    int dentro = dentroRet(pontoInferior,pontoSuperior,ponto);
    printf("%d",dentro);

}












