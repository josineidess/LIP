#include <iostream>

#include <cstdlib>

#define TAM 100

using namespace std;

void mudar_vetor(int vetor[], int vetor_permutado[], int tam, int semente, int & vezes, int mudancas[], int & t_mud);

int main() {
  int vetor[TAM], vetor_permutado[TAM], mudancas[TAM], t_mud = 0, s, t, vezes;
  cin >> s;
  cin >> t;

  for (int e = 0; e < t; e++) {
    cin >> vetor[e];
  }

  mudar_vetor(vetor, vetor_permutado, t, s, vezes, mudancas, t_mud);

  cout << "vetor original" << endl;
  cout << "[ ";
  for (int e = 0; e < t; e++) {
    if (e != 0) {
      cout << ", ";
    }
    cout << vetor[e];
  }
  cout << " ]" << endl;
  cout << "permutações" << endl;
  cout << "n = " << vezes << endl;
  for (int e = 0; e < vezes * 2; e += 2) {
    cout << "pos " << mudancas[e] << " <-> " << mudancas[e + 1] << endl;
  }
  cout << "resultado" << endl;
  cout << "[ ";
  for (int e = 0; e < t; e++) {
    if (e != 0) {
      cout << ", ";
    }
    cout << vetor_permutado[e];
  }
  cout << " ]" << endl;
  return 0;
}

void mudar_vetor(int vetor[], int vetor_permutado[], int tam, int semente, int & vezes, int mudancas[], int & t_mud) {
  srand(semente/tam);
  int n, i, j;

  for(int e = 0;e < tam;e ++){
      vetor_permutado[e] = vetor[e];
  }

  n = (rand() % (5 - 1 + 1)) + 1;
  vezes = n;
  for (int e = 0; e < vezes; e++) {
    i = (rand() % (tam - 0 + 0)) + 0;
    j = (rand() % (tam - 0 + 0)) + 0;
    vetor_permutado[i] = vetor_permutado[j];
    mudancas[t_mud] = i;
    t_mud++;
    vetor_permutado[j] = vetor_permutado[i];
    mudancas[t_mud] = j;
    t_mud++;
  }

}
