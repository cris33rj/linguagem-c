#include "TLSE.h"

int main(void)
{
  TLSE *l = TLSE_inicializa();
  // TLSE *l2 = TLSE_inicializa();
  int x, n;
  do
  {
    scanf("%d", &x);
    if (x < 0)
      break;
    l = TLSE_insere(l, x);
    n++;
  } while (1);
  printf("vai imprimir lista normal\n");
  TLSE_imprime(l);
  printf("\n");

  /* n = 0;
  do
  {
    scanf("%d", &x);
    if (x < 0)
      break;
    l2 = TLSE_insere(l2, x);
    n++;
  } while (1);
  printf("vai imprimir lista 2 normal\n");
  TLSE_imprime(l2);
  printf("\n");
 */
  /* printf("VAI INICIAR A COPIA\n");
  TLSE *copia = TLSE_copia(l);
  printf("IMPRIMINDO COPIA\n");
  TLSE_imprime(copia);
  printf("\n");

  printf("vai inverter sem retorno\n");
  TLSE_inverte(&l);
  printf("imprimindo em TESTE apos inversao sem retorno\n");
  // printf("%p\n", l);
  // printf("%p\n", &l);
  TLSE_imprime(l);
  printf("\n");

  printf("vai inverter com retorno\n");
  l = TLSE_inverte_com_retorno(l);
  printf("imprimindo em TESTE apos inversao com retorno\n");
  // printf("%p\n", l);
  // printf("%p\n", &l);
  TLSE_imprime(l);
  printf("\n");

  printf("VAI COPIAR, INVERTER E RETORNAR\n");
  TLSE *copia_invertida = TLSE_copia_inverte_retorna(l);
  printf("IMPRIMINDO COPIA INVERTIDA COM RETORNO\n");
  TLSE_imprime(copia_invertida);
  printf("\n");

  printf("TESTE DE DESLOCAMENTO\n");
  printf("LISTA ANTES DE DESLOCAR\n");
  TLSE_imprime(l);
  printf("VAI DESLOCAR\n");

  TLSE *deslocado = TLSE_desloca(l, n);
  printf("IMPRIMINDO LISTA DESLOCADA\n");
  TLSE_imprime(deslocado);
  printf("\n");

  TLSE *ocorrencias_removidas = TLSE_rto(l, 2);
  printf("IMPRIMINDO LISTA COM ELEMENTOS REMOVIDOS\n");
  TLSE_imprime(ocorrencias_removidas);
  printf("\n");
  printf("VAI EXECUTAR IMPAR PAR\n");
  TLSE *impar_par = TLSE_i_p(l);
  printf("IMPRIMINDO LISTA COM IMPAR PAR\n");
  TLSE_imprime(impar_par);
  printf("\n");

  printf("vai imprimir lista normal\n");
  TLSE_imprime(l);
  printf("\n");*/

  // TESTANDO SE SUAS LISTAS SAO IGUAIS
  /* printf("VAI INICIAR A INVERSAO DA COPIA\n");
  TLSE *invertida = TLSE_copia_inverte_retorna(l);
  printf("IMPRIMINDO COPIA INVERTIDA\n");
  TLSE_imprime(invertida);
  printf("\n");

  int iguais = TLSE_igual(l, invertida);
  if (iguais == 1)
    printf("Sao iguais");
  else
    printf("Sao diferentes"); */

  // TESTANDO CONCATENACAO DE LISTAS
  /* printf("VAI INICIAR A CONCATENACAO\n");
  TLSE *invertida = TLSE_copia_inverte_retorna(l);

  printf("IMPRIMINDO COPIA INVERTIDA\n");
  TLSE_imprime(invertida);
  printf("\n");

  TLSE *concatenada = TLSE_junta_listas(l, invertida);

  printf("IMPRIMINDO LISTAS CONCATENADAS\n");
  TLSE_imprime(concatenada);

  // TESTANDO SE UMA LISTA EH O CONTRARIO DA OUTRA
  printf("VAI INICIAR O TESTE PRA VER SE UMA LISTA E CONTRARIO DA OUTRA\n");
  // TLSE *invertida = TLSE_copia_inverte_retorna(l);
  TLSE *copia = TLSE_copia(l);
  // int contrario = TLSE_contrario(l, invertida);
  int contrario = TLSE_contrario(l, copia);
  TLSE_imprime(l);
  printf("\n");

  // TLSE_imprime(invertida);
  TLSE_imprime(copia);
  printf("\n");

  if (contrario == 1)
    printf("Sao contrarias");
  else
    printf("Nao sao contrarias");


  int comprimento = TLSE_comprimento(l);
  printf("Comprimento eh--> %d", comprimento);


  TLSE *ultimo = TLSE_ultimo(l);
  printf("Imprimindo valor do ultimo --> %d", ultimo->info);


  TLSE *lista_separada = TLSE_separa(l, 5);

  printf("IMPRIMINDO PARTE QUE RESTOU DA PRIMEIRA LISTA\n");
  TLSE_imprime(l);

  printf("\n");
  printf("IMPRIMINDO LISTA SEPARADA\n");
  TLSE_imprime(lista_separada);


  TLSE *lista_intercalada = TLSE_merge_intercala(l2, l);
  printf("INTERCALOU\n");

  printf("IMPRIMINDO NOVA LISTA INTERCALADA\n");
  TLSE_imprime(lista_intercalada);

  l = TLSE_insereDepois(l, 7, 3);
  TLSE_imprime(l);


  l = TLSE_insereAntes(l, 7, 3);
  printf("\n");
  TLSE_imprime(l);

*/

  TLSE_misc(l, 2);

  TLSE_imprime(l);

  return 0;
}
