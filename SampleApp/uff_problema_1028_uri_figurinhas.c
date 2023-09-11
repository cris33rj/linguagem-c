#include <stdio.h>
#include <math.h>

//http://muitomaiscodigoss.blogspot.com/2018/04/uri-problema-1028-figurinhas-solucao.html


int euclides_mdc(int n1, int n2) {
    int res = n1 % n2;

   if (res == 0) {
       return abs(n2);
  }

  return euclides_mdc(n2, res);\\
}

void run_test() {
 int a, b;
 scanf("%d %d", &a, &b);
 printf("%d\n", euclides_mdc(a, b));
}

int main(int argc, char const *argv[])
{
 int number_of_tests;
 scanf("%d", &number_of_tests);

 int i;
 for (i = 0; i < number_of_tests; ++i)
 {
  run_test();
 }

 return 0;
}
