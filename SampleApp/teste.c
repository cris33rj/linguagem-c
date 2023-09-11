#include <stdio.h>

int main(){

    char palavra[5];

scanf("%5[^\n]",palavra);


for (int i=0; i<5;i++){
        if (palavra[i]>97 && palavra[i]<122)
            palavra[i]=palavra[i]-33;
        else if (palavra[i] == 65) (palavra[i] = 122);
        else if (palavra[i] == 90) (palavra[i] = 121);
        else if (palavra[i] == 97) (palavra[i] = 90);
        else if (palavra[i] == 122) (palavra[i] = 65);
}

for (int i=0; i<5;i++){
        printf("%c",palavra[i]);

}


}
