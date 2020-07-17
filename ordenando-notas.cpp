#include <iostream>
#include <iomanip>

#define TAM 30

using namespace std;

void ordenando(float notas[],int n);
void media(float notas[],int n,int k,float& med);

int main() {
    int k,n;
    float notas[TAM],med;
    cin >> k;
    cin >> n;
    
    for(int e = 0;e < n;e++){
        cin >> notas[e];
    }
    
    cout << "[ ";
    for(int e  = 0;e < n;e++){
        if(e!=0){
            cout << " , ";
        }
        cout << fixed << setprecision(2) << notas[e];
    }
    cout << " ]" << endl;
    
    media(notas,n,k,med);
    
    cout << "Média = " << fixed << setprecision(2) << med << endl;
    
}

void media(float notas[],int n,int k,float& med){
    ordenando(notas,n);
    float soma=0;
    for(int e = n-1;e >= n-k;e--){
        soma+= notas[e];
    }
    med = soma/k;
}

void ordenando(float notas[],int n){
 float ant;
    for(int e = n-1;e >= 1;e--){
      for(int i = 0;i < e;i++){
          if(notas[i] > notas[i +1 ]){
              ant = notas[i + 1];
              notas[i + 1] = notas[i];
              notas[i] = ant;
          }
      }
  }
}
