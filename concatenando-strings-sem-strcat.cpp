#include <iostream>

#
define MAX 100

using namespace std;

void concatenar(char st1[], char st2[], char cst[], int tams1, int tams2);
int main() {
  char string1[MAX];
  char string2[MAX];
  char string_con[MAX];

  cin.getline(string1, MAX);
  int e = 0, quants1 = 0, quants2 = 0;
  while (string1[e] != '\0') {
    quants1++;
    e++;
  }
  e = 0;
  cin.getline(string2, MAX);
  while (string2[e] != '\0') {
    quants2++;
    e++;
  }
  concatenar(string1, string2, string_con, quants1, quants2);
  for (int e = 0; e < quants1; e++) {
    cout << string1[e];
  }
  cout << " ++ ";
  for (int e = 0; e < quants2; e++) {
    cout << string2[e];
  }
  cout << " = ";
  for (int e = 0; e < quants1 + quants2; e++) {
    cout << string_con[e];
  }

}

void concatenar(char st1[], char st2[], char cst[], int tams1, int tams2) {
  for (int e = 0; e < tams1; e++) {
    cst[e] = st1[e];
  }
  for (int i = tams1, e = 0; i < tams1 + tams2; i++, e++) {
    cst[i] = st2[e];
  }
}
