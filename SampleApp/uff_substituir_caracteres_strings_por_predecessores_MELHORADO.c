#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int min_start = 97, min_end = 122, mai_start = 65, mai_end = 90;

void shift_troca_string (char *str) {
  for(int i = 0; i < strlen(str); i++){
    if(str[i] == 'a') str[i] = 'Z';
    else if(str[i] == 'A') str[i] = 'z';
    else if(min_start < str[i] && str[i] <= min_end) str[i] -= 33;
    else if(mai_start < str[i] && str[i] <= mai_end) str[i] += 31;
    else str[i] = '!';
  }
}

int main(void){
  char p[50];
    scanf("%s", p);

    shift_troca_string(p);
    printf("%s\n", p);


  return 0;
}
