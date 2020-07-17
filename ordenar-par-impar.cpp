
#include <iostream>

#define TAM 50

using namespace std;

void ordena_cres(int vetor[],int t);
void ordenar_impar_par(int vetor[],int t);


int main()
{
    int t,vetor[TAM];
    
    cin >> t;
    for(int e = 0;e < t;e++){
        cin >> vetor[e];
    }
    
    cout << "[ ";
    for(int e = 0;e < t;e++){
        if(e!=0){
            cout << " , ";
        }
        cout << vetor[e];
    }
    cout << " ]" << endl;
    
    ordenar_impar_par(vetor,t);
    
    cout << "[ ";
    for(int e = 0;e < t;e++){
        if(e!=0){
            cout << " , ";
        }
        cout << vetor[e];
    }
    cout << " ]" << endl;
    
    return 0;
}

void ordenar_impar_par(int vetor[],int t){
    int vetor_imp[t/2],vetor_par[t/2];
    
    for(int e = 0,cont=0;e < t;e+=2,cont++){
        vetor_par[cont] = vetor[e];
        vetor_imp[cont] = vetor[e+1];
    }
    
    int tamvi=t/2,tamvp = t/2;
    
    if(t%2!=0){
        vetor[t-1] = vetor_par[t/2];
        tamvp++;
    }
    
    ordena_cres(vetor_par,tamvp);
    ordena_cres(vetor_imp,tamvi);
    
    for(int e = 0,par = 0,imp = t/2 -1;e < t;e+=2,par++,imp--){
        vetor[e] = vetor_par[par];
        vetor[e+1] = vetor_imp[imp];
    }
    if(t%2!=0){
        vetor[t-1] = vetor_par[tamvp-1];
    }
}

void ordena_cres(int vetor[],int t){
    int ant;
    for(int e = t-1;e >= 1;e--){
      for(int i = 0;i < e;i++){
          if(vetor[i] > vetor[i +1 ]){
              ant = vetor[i + 1];
              vetor[i + 1] = vetor[i];
              vetor[i] = ant;
          }
      }
  }
}

