#include <iostream>

using namespace std;

int l, c;
bool comparaLinha(int matriz[30][30], int linha[0][30], int l, int c, int pl);
bool passaLinha(int matriz[30][30], int l, int c);

int main() {
  cin >> l;
  cin >> c;
  int matriz[30][30];

  for (int e = 0; e < l; e++) {
    for (int i = 0; i < c; i++) {
      cin >> matriz[e][i];
    }
  }

  if (passaLinha(matriz, l, c)) {
    cout << "A matriz tem linhas repetidas" << endl;
  } else {
    cout << "A matriz nao tem linhas repetidas" << endl;
  }
  return 0;
}

bool passaLinha(int matriz[30][30], int l, int c) {
  int linha[1][30];
  for (int e = 0; e < l; e++) {
    for (int i = 0; i < c; i++) {
      linha[0][i] = matriz[e][i];
    }
    if (comparaLinha(matriz, linha, l, c, e)) {
      return true;
    }
  }
  return false;
}

bool comparaLinha(int matriz[30][30], int linha[0][30], int l, int c, int pl) {
  int cont = 0;
  for (int e = 0; e < l; e++) {
    for (int i = 0; i < c; i++) {
      if (linha[0][i] == matriz[e][i] && pl != e) {
        cont++;
      }
    }
    if (cont == c) {
      return true;
    } else {
      cont = 0;
    }
  }
  return false;
}
