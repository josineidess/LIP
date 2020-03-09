#include <iostream>

#include <string>

#include <string.h>

#include <stdio.h>

#include <stdlib.h>

using namespace std;
string n;

int digitos;
int soma = 0;
string dg;
int maior;
int v_soma;
int q_numeros;
int vezes;

int main() {
  cin >> q_numeros;
  vezes = q_numeros;
  while (vezes > 0) {
    cin >> n;
    digitos = n.length();
    soma = 0;
    for (int e = 0; e < digitos; e++) {
      dg = n[e];
      soma += atoi(dg.c_str());
    }
    if (vezes == q_numeros) {
      maior = atoi(n.c_str());
      v_soma = soma;
    } else {
      if (soma > v_soma) {
        maior = atoi(n.c_str());
        v_soma = soma;
      }
    }
    vezes--;
  }
  cout << maior << endl;
  return 0;
}
