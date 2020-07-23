#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
#include <cmath>

#define TAM 100

using namespace std;

struct Complexo{
    int real;
    int imaginaria;
};

void imprimir(Complexo numero);
float modulo(Complexo numero);
bool ehIgual(Complexo n1,Complexo n2);
Complexo soma(Complexo n1, Complexo n2);
Complexo conjugado(Complexo num);
Complexo somatorio(Complexo numeros[],int tam);

int main() {
   Complexo numeros[TAM];
   int tam;
   cin >> tam;
   for(int e = 0;e < tam;e++){
     cin >> numeros[e].real;
     cin >> numeros[e].imaginaria;
   }

   for(int e = 0;e < tam;e++){
     imprimir(numeros[e]);
     cout << endl;
   }

   cout << "conjugado = ";
   imprimir(conjugado(numeros[0]));
   cout << endl;
  
  cout << "módulo = " << modulo(numeros[0]) << endl;

   if(ehIgual(numeros[0], numeros[1])){
     imprimir(numeros[0]);
     cout << " é igual a ";
     imprimir(numeros[1]);
     cout << endl;
   }else{
     imprimir(numeros[0]);
     cout << " não é igual a ";
     imprimir(numeros[1]);
     cout << endl;
   }
   
   cout << "a soma dos complexos é ";
   imprimir(somatorio(numeros,tam));
   cout << endl;
   return 0;
}

void imprimir(Complexo numero){
  if(numero.imaginaria >= 0){
    cout << numero.real << " + " << numero.imaginaria << "i";
  }else{
   numero.imaginaria = -1 * numero.imaginaria;
   cout << numero.real << " - " << numero.imaginaria << "i";
  }
}

float modulo(Complexo numero){
  return sqrt((numero.real * numero.real) + (numero.imaginaria * numero.imaginaria));
}

bool ehIgual(Complexo n1,Complexo n2){
  if(n1.real == n2.real && n1.imaginaria == n2.imaginaria){
    return true;
  }else{
    return false;
  }
}

Complexo soma(Complexo n1, Complexo n2){
  Complexo soma;
  soma.real = n1.real + n2.real;
  soma.imaginaria = n1.imaginaria + n2.imaginaria;
  return soma;
}

Complexo conjugado(Complexo num){
  Complexo con;
  con.real = num.real;
  con.imaginaria = -1 * num.imaginaria;
  return con;
}

Complexo somatorio(Complexo numeros[],int tam){
  Complexo som;
  som.real = 0;
  som.imaginaria = 0;
  for(int e = 0;e < tam;e++){
    som = soma(som,numeros[e]);
  }
  return som;
}
