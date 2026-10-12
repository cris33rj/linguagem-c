

void imprimir(int *num){
    printf("%d\n", *num);
    *num = 80;
}

int main(){
    int idade = 35;
    int *ponteiro = &idade;



    imprimir(ponteiro);
    printf("No main: %d\n", idade);

    return 0;
}
