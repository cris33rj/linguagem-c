#include <iostream>
#include <string>
#include <tuple>  // para exercícios com tupla
// favor não remover exemplos
#include <vector>
#include <sstream>
#include <algorithm>


// dica: retorna uma tupla com 2 elementos (veja slides com std::make_tuple)
// NAO APAGUE OU MODIFIQUE O CABEÇALHO DA FUNÇÃO ABAIXO
float exercicio9(std::string entrada) {  
  // Edite aqui dentro, somente. Leia todos os dados da string 'entrada'
   // Edite aqui dentro, somente. Leia todos os dados da string 'entrada'
  int n = 0;
  float mediana {0.0};  
  // requer #include<sstream>
  std::istringstream meu_cin{entrada};
  meu_cin >> n;
  int n2 = n; 
  //std::cout << "n eh" << n << std::endl;
  
  int num[n] {0};  
  while (n--) {
    int v = 0;
    //std::cout << "n eh" << n << std::endl;
    meu_cin >> v;
    //std::cout << "v eh" << v << std::endl;
    num[n]=v;     
  }

std::sort(num, num+n2);
for (int i=0;i<n2;i++){
    //std::cout << "imprimindo na posicao" << i << "o numero " << num[i] <<std::endl;
}

if (n2%2==0){
    //std::cout << "num[n2/2] eh" << num[n2/2] << "e num[(n2/2)+1] eh " << num[(n2/2)+1] <<std::endl;
    mediana = ((float) (num[n2/2]+num[(n2/2)+1])/2);
} else {
    //std::cout << "entrou" << std::endl;
    mediana = (float)num[n2/2];
}
//std::cout << "mediana eh" << mediana << std::endl;

return mediana;
}

int main(){
    float mediana = exercicio9("6 8 3 6 1 7 9");
    std::cout << "mediana eh" << mediana << std::endl;
}