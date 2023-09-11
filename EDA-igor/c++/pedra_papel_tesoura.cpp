#include <iostream>
#include <string>
#include <tuple>  // para exercícios com tupla
// favor não remover exemplos
#include <sstream>
#include <vector>


// dica: retorna uma tupla com 4 elementos (veja slides com std::make_tuple)
// NAO APAGUE OU MODIFIQUE O CABEÇALHO DA FUNÇÃO ABAIXO
char exercicio7(std::string entrada) {
  // Edite aqui dentro, somente. Leia todos os dados da string 'entrada'
  std::istringstream meu_cin{entrada};
  int n = 0;
  meu_cin >> n;

  int J {0};
  int M {0};  
  std::string elem_1;
  std::string elem_2;
  
  while (n--) {    
    meu_cin >> elem_1;
    meu_cin >> elem_2;

    if (elem_1 == "t" && elem_2=="p") M++;     
    else if (elem_1 == "p" && elem_2=="d") M++;
    else if (elem_1 == "d" && elem_2=="t") M++;
    else if((elem_1 == "p" && elem_2=="p") || (elem_1 == "t" && elem_2=="d") || (elem_1 == "t" && elem_2=="t"))
    { M++; 
    J++;
    } else J++;    
  }
  std::cout <<"J eh "<<J <<std::endl;
  std::cout <<"M eh "<<J <<std::endl;

  if (J>M) return 'J';
  else if (J<M) return 'M';

  return 'X';  
}

main(){
    char vencedor = exercicio7("3 t p d p d t");
    std::cout <<"Vencedor eh "<<vencedor <<std::endl;
}