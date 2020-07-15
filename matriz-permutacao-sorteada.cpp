#include <iostream>

#include <cstdlib>

#define TAM 100

using namespace std;

void gerar_matriz(int matriz[][TAM], int d, int n, int semente);
void retorna_linha(int matriz[][TAM], int d, int ll, int linha[]);
void retorna_coluna(int matriz[][TAM], int t, int cc, int coluna[]);

int main() {
  int D, n, matriz[TAM][TAM], semente;
  cin >> semente;
  cin >> D;
  cin >> n;
  gerar_matriz(matriz, D, n, semente);

  for (int l = 0; l < D; l++) {
    for (int c = 0; c < D; c++) {
      cout << matriz[l][c] << " ";
    }
    cout << endl;
  }
  return 0;
}

void gerar_matriz(int matriz[][TAM], int d, int n, int semente) {
  int um = 0;
  for (int l = 0; l < d; l++) {
    for (int c = 0; c < d; c++) {
      if (l == 0 && c == 0) {
        matriz[l][c] = 1;
      } else {
        if (um == c) {
          matriz[l][c] = 1;
        } else {
          matriz[l][c] = 0;
        }
      }
    }
    um++;
  }
  srand(semente);
  int ii, jj, lc, linha_ant[d], linha[d], coluna_ant[d], coluna[d];
  for (int e = 0; e < n; e++) {
    ii = rand() % d;
    jj = rand() % d;
    lc = rand() % 2;
    
    if (lc == 0) {
      retorna_linha(matriz, d, ii, linha);
      for (int c = 0; c < d; c++) {
        linha_ant[c] = matriz[jj][c];
        matriz[jj][c] = linha[c];
      }
      for (int c = 0; c < d; c++) {
        matriz[ii][c] = linha_ant[c];
      }
      cout << "linha: " << ii << " <-> " << jj << endl;
    }else if (lc == 1) {
      retorna_coluna(matriz, d, ii, coluna);
      for (int l = 0; l < d; l++) {
        for (int c = 0; c < d; c++) {
          if (c == jj) {
            coluna_ant[l] = matriz[l][c];
            matriz[l][c] = coluna[l];
          }
        }
      }

      for (int l = 0; l < d; l++) {
        for (int c = 0; c < d; c++) {
          if (c == ii) {
            matriz[l][c] = coluna_ant[l];
          }
        }
      }
      cout << "col: " << ii << " <-> " << jj << endl;
    }
    coluna[d] = {};
    coluna_ant[d] = {};
    linha[d] = {};
    linha_ant[d] = {};
  }
}

void retorna_linha(int matriz[][TAM], int d, int ll, int linha[]) {
  for (int l = 0; l < d; l++) {
    for (int c = 0; c < d; c++) {
      if (l == ll) {
        linha[c] = matriz[l][c];
      }
    }
  }
}

void retorna_coluna(int matriz[][TAM], int t, int cc, int coluna[]) {
  for (int l = 0; l < t; l++) {
    for (int c = 0; c < t; c++) {
      if (c == cc) {
        coluna[l] = matriz[l][c];
      }
    }
  }
}
