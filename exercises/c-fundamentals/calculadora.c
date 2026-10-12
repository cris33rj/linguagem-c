#include <stdio.h>

int main (void){
  float oper1,oper2, resp;
  char op;
  while(1){
    scanf("%f %c%f", &oper1, &op, &oper2);
    if((oper1 == 0) && (oper2 == 0) && ((op == 'q')||(op == 'Q'))) return 0;
    if((op != '+') && (op != '-')&&(op != '*')&&(op != '/')) continue;
    switch (op){
      case '+': resp = oper1 + oper2; break;
      case '-': resp = oper1 - oper2; break;
      case '/': if(oper2 != 0){resp = oper1 / oper2; break;} else continue;
      default:  resp = oper1 * oper2;
    }
    printf ("%f %c %f = %f\n", oper1, op, oper2, resp);
  }
}
