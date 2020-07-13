#include <iostream>

#include <ctype.h>

#define TAM 100

using namespace std;

void criptografar(int n, int tam_str, char frase[], char frase_cript[]);
void descriptografar(int n, int tam_str, char frase_cript[], char frase_descript[]);
char nova_letra(char letra, int n, bool minusc, bool par, bool crip);

int main() {
  
  int n, tam_str = 0, e = 0,i = 0,tam_str2=0;
  char frase[TAM], frase_cript[TAM],frase_para_desc[TAM],frase_descript[TAM];
  
  cin >> n;
  cin.get();
  cin.getline(frase, TAM);
  cin.getline(frase_para_desc,TAM);
  
  while (frase[e] != '\0') {
    tam_str++;
    e++;
  }
  tam_str++;
  
  while(frase_para_desc[i] != '\0'){
      tam_str2++;
      i++;
  }
  tam_str2++;
  
  criptografar(n, tam_str, frase, frase_cript);
  descriptografar(n,tam_str2,frase_para_desc,frase_descript);
  
  cout << frase << " => " << endl << frase_cript << endl;
  cout << frase_para_desc << " => "<< endl;
  cout << frase_descript << endl;
  
  return 0;
}

void criptografar(int n, int tam_str, char frase[], char frase_cript[]) {
  for (int e = 0; e < tam_str; e++) {
    if (e % 2 == 0) {
      if (islower(frase[e])) {
        frase_cript[e] = nova_letra(frase[e], n, true, true, true);
      } else {
        if (isupper(frase[e])) {
          frase_cript[e] = nova_letra(frase[e], n, false, true, true);
        } else {
          frase_cript[e] = frase[e];
        }
      }
    } 
    else {
      if (e == 1 || e % 2 != 0) {
        if (islower(frase[e])) {
          frase_cript[e] = nova_letra(frase[e], n, true, false, true);
        } else {
          if (isupper(frase[e])) {
            frase_cript[e] = nova_letra(frase[e], n, false, false, true);
          } else {
            frase_cript[e] = frase[e];
          }
        }
      }
    }
  }
}

void descriptografar(int n, int tam_str, char frase_cript[], char frase_descript[]) {
  for (int e = 0; e < tam_str; e++) {
    if (e % 2 == 0) {
      if (islower(frase_cript[e])) {
        frase_descript[e] = nova_letra(frase_cript[e], n, true, true, false);
      } else {
        if (isupper(frase_cript[e])) {
          frase_descript[e] = nova_letra(frase_cript[e], n, false, true, false);
        } else {
          frase_descript[e] = frase_cript[e];
        }
      }
    } 
    else {
      if (e == 1 || e % 2 != 0) {
        if (islower(frase_cript[e])) {
          frase_descript[e] = nova_letra(frase_cript[e], n, true, false, false);
        } else {
          if (isupper(frase_cript[e])) {
            frase_descript[e] = nova_letra(frase_cript[e], n, false, false, false);
          } else {
            frase_descript[e] = frase_cript[e];
          }
        }
      }
    }
  }
}

char nova_letra(char letra, int n, bool minusc, bool par, bool crip) {
  int cont = int(letra);
  if (crip) {
    if (minusc) {
      if (par) {
        for (int e = 0; e < n; e++) {
          if (cont < 122) {
            cont++;
          } else {
            if (cont == 122) {
              cont = 97;
            } else {
              cont++;
            }

          }
        }

      } else {
        for (int e = 0; e < n; e++) {
          if (cont > 97) {
            cont--;
          } else {
            if (cont == 97) {
              cont = 122;
            } else {
              cont--;
            }
          }
        }
      }

    } else {
      if (par) {
        for (int e = 0; e < (2 * n); e++) {
          if (cont < 90) {
            cont++;
          } else {
            if (cont == 90) {
              cont = 65;
            } else {
              cont++;
            }
          }
        }
      } else {
        for (int e = 0; e < (3 * n); e++) {
          if (cont > 65) {
            cont--;
          } else {
            if (cont == 65) {
              cont = 90;
            } else {
              cont--;
            }
          }
        }
      }
    }

  } else {
    if (minusc) {
      if (par) {
        for (int e = 0; e < n; e++) {
          if (cont > 97) {
            cont--;
          } else {
            if (cont == 97) {
              cont = 122;
            } else {
              cont--;
            }
          }
        }
      } else {
        for (int e = 0; e < n; e++) {
          if (cont < 122) {
            cont++;
          } else {
            if (cont == 122) {
              cont = 97;
            } else {
              cont++;
            }

          }
        }
      }
      } else {
        if (par) {
          for (int e = 0; e < (2 * n); e++) {
            if (cont > 65) {
              cont--;
            } else {
              if (cont == 65) {
                cont = 90;
              } else {
                cont--;
              }
            }
          }
      } else {
        for (int e = 0; e < (3 * n); e++) {
          if (cont < 90) {
            cont++;
          } else {
            if (cont == 90) {
              cont = 65;
            } else {
              cont++;
            }
          }
        }
      }
    }
  }
  return char(cont);
}
