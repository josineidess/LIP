#include <iostream>

#include <cmath>

using namespace std;
float media(int linha[], int coluna);

int main() {
  int l, c;
  cin >> l;
  cin >> c;
  int mat[30][30];
  int soma = 0;
  for (int e = 0; e < l; e++) {
    for (int i = 0; i < c; i++) {
      cin >> mat[e][i];
    }
  }
  
  int mat_linha[c] = {};
  int cont = 0;
  for (int e = 0; e < l; e++) {
    for (int i = 0, k = 0; i < c; i++, k++) {
      mat_linha[k] = mat[e][i];
    }
    
    cout << "[ ";
    for (int j = 0; j < c; j++) {
      if (mat_linha[j] >= media(mat_linha, c)) {
        if (cont != 0) {
          cout << " , ";
        }
        cout << mat_linha[j];
        cont++;
      }
    }
    cout << " ]" << endl;
    cont = 0;
    mat_linha[c] = {};
  }
  
  return 0;
}

float media(int linha[], int coluna) {
  float soma = 0;
  for (int i = 0; i < coluna; i++) {
    soma += linha[i];
  }
  soma = soma / coluna;
  return soma;
}
