#include <iostream>

#define TAM 30

using namespace std;

void ordena(int vetor[], int vetor_orde[], int t);

int main() {
  int vetor[TAM], vetor_orde[TAM], t;
  cin >> t;
  for (int e = 0; e < t; e++) {
    cin >> vetor[e];
  }
  ordena(vetor, vetor_orde, t);
  cout << "[ ";
  for (int e = 0; e < t; e++) {
    if (e != 0) {
      cout << " , ";
    }
    cout << vetor[e];
  }
  cout << " ]" << endl;
  cout << "[ ";
  for (int e = 0; e < t; e++) {
    if (e != 0) {
      cout << " , ";
    }
    cout << vetor_orde[e];
  }
  cout << " ]" << endl;
  return 0;
}

void ordena(int vetor[], int vetor_orde[], int t) {
  for (int e = 0; e < t; e++) {
    vetor_orde[e] = vetor[e];
  }
  int aux;
  for (int i = 0; i < t; i++) {
    for (int e = 0; e < t; e++) {
      if (vetor_orde[e] > vetor_orde[e - 1]) {
        aux = vetor_orde[e];
        vetor_orde[e] = vetor_orde[e - 1];
        vetor_orde[e - 1] = aux;
      }
    }
  }
}
