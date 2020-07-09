#include <iostream>

#define MAX 100

using namespace std;

void inverter(char pal[], char pal_inv[], int tam);
bool ehPalindromo(char pal[], char pal_inv[], int tam);

int main() {
  char palavra[MAX], palavra_invertida[MAX];
  cin >> palavra;
  int tam = 0, e = 0;
  while (palavra[e] != '\0') {
    tam++;
    e++;
  }
  inverter(palavra, palavra_invertida, tam);

  if (ehPalindromo(palavra, palavra_invertida, tam)) {
    cout << palavra << " é um palíndromo" << endl;
  } else {
    cout << palavra << " não é um palíndromo" << endl;
  }
  return 0;
}

void inverter(char pal[], char pal_inv[], int tam) {
  for (int e = tam - 1, k = 0; e >= 0; e--, k++) {
    pal_inv[k] = pal[e];
  }
}

bool ehPalindromo(char pal[], char pal_inv[], int tam) {
  for (int e = 0; e < tam; e++) {
    if (pal[e] != pal_inv[e]) {
      return false;
    }
  }
  return true;
}
