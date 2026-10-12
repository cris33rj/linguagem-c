#include<stdio.h>

int main (){


int x, y, z;
int teste;
x = 5;
y = x++;
z = x--;

//teste = !y == !x; // false
//printf("%d",teste);
//teste = ((x++ > y) || (--z <= y));
//teste = --z <= y;
//printf("%d",teste);
//teste = ((!x) || (!(!z)));
//printf("%d",teste);
//teste = (((x + y) > z) && (x++));
//printf("%d",teste);
teste = x && y + !3 || 4;
printf("%d",teste);
}
