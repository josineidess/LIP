#include <iostream>
#include <string>
#include <iomanip>

#define TAM 100

using namespace std;

struct Produto{
  string nome;
  int codigo;
  double preco;
  int tipo;
  
};

string tipo(int t);
void imprimir(Produto p);
void mais_caro(Produto vetor[],int tam);
bool temIpad(Produto vetor[],int tam);
double lucro(Produto vetor[],int tam);

int main() {
  Produto produtos[30];
  int quant;
  
  cin >> quant;

  for(int e = 0; e < quant;e++){
     cin.ignore();
     getline(cin,produtos[e].nome);
     cin >> produtos[e].codigo;
     cin >> produtos[e].preco;
     cin >> produtos[e].tipo;
  }

  for(int e = 0;e < quant;e++){
    imprimir(produtos[e]);
  }

  cout << "Mais caro" << endl;
  mais_caro(produtos, quant);
  
  if(temIpad(produtos, quant)){
    cout << "Tem iPad" << endl;
  }else{
    cout << "Não tem iPad" << endl;
  }

  cout << "Lucro: " << fixed << setprecision(2) << lucro(produtos, quant) << endl;
  return 0;
}

string tipo(int t){
    switch(t){
      case 0:
        return "Eletrodoméstico";
        break;
      case 1:
         return "Moda";
         break;
      case 2:
         return "Outro";
         break;
      default:
         return "Tipo inválido";
         break;
    }
}

void imprimir(Produto p){
    cout << "{ "; 
    cout << "código: " << p.codigo << " , nome: "<< p.nome << " , preço: " << p.preco << " , tipo = " << tipo(p.tipo) << " }"<< endl;
}

void mais_caro(Produto vetor[],int tam){
  double maior;
  Produto prod_mais_caro;
  for(int e = 0;e < tam;e++){
    if(e == 0){
      maior = vetor[e].preco;
      prod_mais_caro = vetor[e];
    }else{
      if(vetor[e].preco > maior){
        maior = vetor[e].preco;
        prod_mais_caro = vetor[e];
      }
    }
  }
  imprimir(prod_mais_caro);
}

bool temIpad(Produto vetor[],int tam){
  for(int e = 0;e < tam;e++){
    if(vetor[e].nome == "iPad"){
      return true;
    }
  }
  return false;
}

double lucro(Produto vetor[],int tam){
  double soma=0;
  for(int e = 0;e < tam;e++){
     if(vetor[e].tipo == 0){
         soma += vetor[e].preco;
     }
  }
  return soma;
}

