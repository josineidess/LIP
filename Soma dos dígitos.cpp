#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h> 
#include <stdlib.h>  

using namespace std;
string n;
int digitos;
int soma=0;
string dg;
int main() {
  cin >> n;
  digitos = n.length();
  for(int e = 0;e < digitos;e++){
  dg = n[e];
  soma+=atoi(dg.c_str());
  }
  cout << soma << endl;
  return 0;
}
