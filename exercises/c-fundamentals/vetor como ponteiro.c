
int *teste(int *vet, int tam){
    int i;

    int *resp = (int *) malloc(sizeof (int)*tam);
    for(i = 0; i < tam; i++)
        resp[i] = vet[i] * 2;
    return resp;
}

void imprimir(int *vet, int tam){
    int i;
    for(i = 0; i < tam; i++)
        printf("%d ", vet[i]);
    printf("\n");
}

int main(){

    int vet[10] = {45,89,68,25,17,76,34,29,57,44};

    imprimir(vet, 10); // vetor original
    int *resposta = teste(vet, 10);
    imprimir(resposta, 10); // vetor alterado

    return 0;
}
