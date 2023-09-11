#include <stdio.h>

int main()
{
    int quantPessoas;
    int quantTickets;

    while(quantPessoas!=0 && quantTickets !=0){
    //printf("Informe a quantidade de tickes e de pessoas presentes para a festa\n");
        scanf("%d%d",&quantPessoas,&quantTickets);

        if (quantPessoas==0 && quantTickets ==0)
            return 0;

        int tickets[quantTickets];
        int ticketsFalsos[10]={0};
        int conta=0;

     //   printf("Informe a quantidade os numeros dos tickets\n");

        for (int i=0; i<quantTickets; i++){
            scanf("%d",&tickets[i]);
        }

        for (int i=0; i<quantTickets; i++)
        {
            for (int j=(i+1); j<quantTickets; j++)
            {
                if (tickets[i]==tickets[j])
                     ticketsFalsos[tickets[i]]=1;

            }
        }
      for (int i=0; i<10; i++){
       //     printf("%d ",ticketsFalsos[i]);
            if (ticketsFalsos[i]==1){
                conta++;
            }
        }
        printf("%d ",conta);
    }
}
