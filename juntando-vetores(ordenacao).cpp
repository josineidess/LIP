#include <iostream>

using namespace std;

#define TAM 30

void preencher_v3(int v1[],int v2[],int v3[],int n);
void ordenar_v1(int v[],int n);
void ordenar_v2(int v[],int n);
void inverte_var(int& v1, int& v2);

int main() {
    int v1[TAM],v2[TAM],v3[2*TAM],n;
    cin >> n;
    
    for(int e = 0;e < n;e++){
        cin >> v1[e];
    }
    for(int e = 0;e < n;e++){
        cin >> v2[e];
    }
    
    cout << "[ ";
    for(int e = 0;e < n;e++){
        if(e!=0){
            cout << " , ";
        }
        cout << v1[e];
    }
    cout << " ]" << endl;
    
    cout << "+\n";
    
    cout << "[ ";
    for(int e = 0;e < n;e++){
        if(e!=0){
            cout << " , ";
        }
        cout << v2[e];
    }
    cout << " ]" << endl;
    
    preencher_v3(v1,v2,v3,n);

    cout << "=\n";
    
    cout << "[ ";
    for(int e = 0;e < 2*n ;e++){
        if(e!=0){
            cout << " , ";
        }
        cout << v3[e];
    }
    cout << " ]" << endl;
    
    return 0;
}

void preencher_v3(int v1[],int v2[],int v3[],int n){
    ordenar_v1(v1,n);
    ordenar_v2(v2,n);
    for(int e = 0,cv=0;e < 2*n;e+=2,cv++){
        v3[e] = v1[cv];
        v3[e+1] = v2[cv];
    }
}

void inverte_var(int& v1, int& v2){
    int aux = v1;
    v1 = v2;
    v2 = aux;
}

void ordenar_v1(int v[],int n){
  for(int e = n-1;e >= 1;e--){
      for(int i = 0;i < e;i++){
          if(v[i] > v[i +1 ]){
              inverte_var(v[i],v[i+1]);
          }
      }
  }
}

void ordenar_v2(int v[],int n){
    for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
        if (v[i] > v[j]) {
            inverte_var(v[i],v[j]);
        }
    }
}
}
