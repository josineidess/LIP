#include <iostream>

using namespace std;
bool soTemZeroUm(int mat[30][30], int t);
bool soTemUmUmLinha(int linha[], int t);
bool soTemUmUmColuna(int coluna[], int t);
bool compara(int matriz[30][30], int t);

int main() {
  int t, mat[30][30];
  cin >> t;
  for (int e = 0; e < t; e++) {
    for (int i = 0; i < t; i++) {
      cin >> mat[e][i];
    }
  }

  if (soTemZeroUm(mat, t)) {
    cout << "só tem 0 e 1" << endl;
  } else {
    cout << "não tem só 0 e 1" << endl;
  }
  if (compara(mat, t)) {
    cout << "permuta" << endl;
  } else {
    cout << "nao permuta" << endl;
  }
  return 0;
}

bool soTemZeroUm(int mat[30][30], int t) {
  for (int e = 0; e < t; e++) {
    for (int i = 0; i < t; i++) {
      if (mat[e][i] != 0 && mat[e][i] != 1) {
        return false;
      }
    }
  }
  return true;
}

bool soTemUmUmLinha(int linha[], int t) {
  int quant = 0;
  for (int e = 0; e < t; e++) {
    if (linha[e] == 1) {
      quant++;
    }
  }
  if (quant > 1) {
    return false;
  } else {
    return true;
  }
}

bool soTemUmUmColuna(int coluna[], int t) {
  int quant = 0;
  for (int e = 0; e < t; e++) {
    if (coluna[e] == 1) {
      quant++;
    }
  }
  if (quant > 1) {
    return false;
  } else {
    return true;
  }
}

bool compara(int matriz[30][30], int t) {
  int l = t, c = t, linha[t] = {}, cont = 0, quantL = 0, matriz_transp[30][30];
  int coluna[t] = {}, cont2 = 0, quantC = 0;

  for (int e = 0; e < l; e++) {
    for (int i = 0; i < c; i++) {
      linha[cont] = matriz[e][i];
      cont++;
    }
    cont = 0;
    if (soTemUmUmLinha(linha, t)) {
      quantL++;
    }
  }

  for (int e = 0; e < l; e++) {
    for (int i = 0; i < c; i++) {
      matriz_transp[e][i] = matriz[i][e];
    }
  }

  for (int e = 0; e < l; e++) {
    for (int i = 0; i < c; i++) {
      coluna[cont2] = matriz_transp[e][i];
      cont2++;
    }
    cont2 = 0;
    if (soTemUmUmColuna(coluna, t)) {
      quantC++;
    }
  }

  if (quantL == t && quantC == t) {
    return true;
  } else {
    return false;
  }
}
